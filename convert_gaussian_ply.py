#!/usr/bin/env python3
"""
Gaussian Splatting PLY → OBJ (with Unreal Engine coordinates) + optional volumetric remeshing.
Recreates Blender Geometry Nodes "Points to Volume → Volume to Mesh" workflow in pure Python.

Requires: numpy, scipy, open3d
"""

import sys, os, struct, math
import numpy as np
from scipy.spatial import cKDTree
import open3d as o3d


# ============================================================
# === PLY Reading ============================================
# ============================================================

def read_ply_header(file_path):
    """Read PLY header and return vertex count and properties."""
    with open(file_path, 'rb') as f:
        header_lines = []
        while True:
            line_bytes = f.readline()
            try:
                line = line_bytes.decode('utf-8').strip()
            except UnicodeDecodeError:
                if b'end_header' in line_bytes:
                    line = 'end_header'
                else:
                    continue
            header_lines.append(line)
            if line == 'end_header':
                break
        
        vertex_count = 0
        properties = []
        for line in header_lines:
            if line.startswith('element vertex'):
                vertex_count = int(line.split()[-1])
            elif line.startswith('property'):
                parts = line.split()
                if len(parts) >= 3:
                    prop_type = parts[1]  # float, double, uchar, etc.
                    prop_name = parts[2]
                    properties.append((prop_name, prop_type))
        
        return vertex_count, properties


def read_ply_data(file_path, vertex_count, properties):
    """Read PLY binary data."""
    positions, normals, colors = [], [], []
    with open(file_path, 'rb') as f:
        # Skip header
        while True:
            line_bytes = f.readline()
            if b'end_header' in line_bytes:
                break
        
        # Build format string and calculate byte size
        format_str = ''
        prop_names = []
        for prop_name, prop_type in properties:
            prop_names.append(prop_name)
            if prop_type == 'float':
                format_str += 'f'
            elif prop_type == 'double':
                format_str += 'd'
            elif prop_type == 'uchar':
                format_str += 'B'
            elif prop_type == 'int':
                format_str += 'i'
        
        vertex_size = struct.calcsize(format_str)
        
        # Read vertex data
        for _ in range(vertex_count):
            vertex_data = struct.unpack(format_str, f.read(vertex_size))
            
            # Extract positions (x, y, z)
            if 'x' in prop_names and 'y' in prop_names and 'z' in prop_names:
                x_idx = prop_names.index('x')
                y_idx = prop_names.index('y')
                z_idx = prop_names.index('z')
                positions.append([vertex_data[x_idx], vertex_data[y_idx], vertex_data[z_idx]])

            # Extract normals
            if 'nx' in prop_names and 'ny' in prop_names and 'nz' in prop_names:
                nx_idx = prop_names.index('nx')
                ny_idx = prop_names.index('ny')
                nz_idx = prop_names.index('nz')
                normals.append([vertex_data[nx_idx], vertex_data[ny_idx], vertex_data[nz_idx]])

            # Extract colors from RGB (uchar 0-255)
            if 'red' in prop_names and 'green' in prop_names and 'blue' in prop_names:
                r_idx = prop_names.index('red')
                g_idx = prop_names.index('green')
                b_idx = prop_names.index('blue')
                rgb = [vertex_data[r_idx]/255.0, vertex_data[g_idx]/255.0, vertex_data[b_idx]/255.0]
                colors.append(rgb)
            # Extract colors from SH coefficients
            elif 'f_dc_0' in prop_names and 'f_dc_1' in prop_names and 'f_dc_2' in prop_names:
                dc_0_idx = prop_names.index('f_dc_0')
                dc_1_idx = prop_names.index('f_dc_1')
                dc_2_idx = prop_names.index('f_dc_2')
                sh_dc = [vertex_data[dc_0_idx], vertex_data[dc_1_idx], vertex_data[dc_2_idx]]
                rgb = [max(0, min(1, (1.0 / (1.0 + math.exp(-x))))) for x in sh_dc]
                colors.append(rgb)

    return positions, normals if normals else None, colors if colors else None


# ============================================================
# === Coordinate Conversion =================================
# ============================================================

def convert_to_unreal_coordinates(positions, normals):
    """Convert coordinates to Unreal Engine coordinate system."""
    if not positions:
        return positions, normals

    x_coords = [p[0] for p in positions]
    y_coords = [p[1] for p in positions]
    z_coords = [p[2] for p in positions]
    x_range = max(x_coords) - min(x_coords)
    y_range = max(y_coords) - min(y_coords)
    z_range = max(z_coords) - min(z_coords)

    print(f"[WorldExplorer] Coordinate spans → X:{x_range:.3f}, Y:{y_range:.3f}, Z:{z_range:.3f}")
    if z_range < 0.001:
        print("[WorldExplorer] Flat plane detected — swapping Y/Z")
        for i in range(len(positions)):
            positions[i][1], positions[i][2] = positions[i][2], positions[i][1]
            if normals:
                normals[i][1], normals[i][2] = normals[i][2], normals[i][1]

    print("[WorldExplorer] Converting to Unreal Engine coordinate system...")
    for i in range(len(positions)):
        x, y, z = positions[i]
        positions[i] = [z, x, y]
        if normals:
            nx, ny, nz = normals[i]
            normals[i] = [nz, nx, ny]

    return positions, normals


# ============================================================
# === Downsample =============================================
# ============================================================

def downsample_data(positions, normals, colors, target_count=10000):
    if len(positions) <= target_count:
        return positions, normals, colors
    step = max(1, len(positions)//target_count)
    positions = positions[::step]
    if normals:
        normals = normals[::step]
    if colors:
        colors = colors[::step]
    return positions, normals, colors


# ============================================================
# === OBJ + MTL Writer =======================================
# ============================================================

def create_oriented_quad(position, normal, quad_size=0.02):
    """Create a quad oriented to face along its normal direction.
    
    Args:
        position: [x, y, z] center position
        normal: [nx, ny, nz] normal direction
        quad_size: size of the quad
    
    Returns:
        List of 4 vertices forming the quad
    """
    half = quad_size / 2
    x, y, z = position
    nx, ny, nz = normal
    
    # Normalize the normal
    normal_length = math.sqrt(nx*nx + ny*ny + nz*nz)
    if normal_length > 0.0001:
        nx, ny, nz = nx/normal_length, ny/normal_length, nz/normal_length
    else:
        nx, ny, nz = 0, 0, 1  # Default to Z-up if no normal
    
    # Create a coordinate system based on the normal
    # Find a perpendicular vector (tangent)
    if abs(nx) < 0.9:
        tangent = [1, 0, 0]
    else:
        tangent = [0, 1, 0]
    
    # Cross product: bitangent = normal × tangent
    bx = ny * tangent[2] - nz * tangent[1]
    by = nz * tangent[0] - nx * tangent[2]
    bz = nx * tangent[1] - ny * tangent[0]
    
    # Normalize bitangent
    b_length = math.sqrt(bx*bx + by*by + bz*bz)
    if b_length > 0.0001:
        bx, by, bz = bx/b_length, by/b_length, bz/b_length
    
    # Cross product: tangent = bitangent × normal
    tx = by * nz - bz * ny
    ty = bz * nx - bx * nz
    tz = bx * ny - by * nx
    
    # Create quad vertices in the tangent/bitangent plane
    vertices = [
        [x - tx*half - bx*half, y - ty*half - by*half, z - tz*half - bz*half],  # Bottom-left
        [x + tx*half - bx*half, y + ty*half - by*half, z + tz*half - bz*half],  # Bottom-right
        [x + tx*half + bx*half, y + ty*half + by*half, z + tz*half + bz*half],  # Top-right
        [x - tx*half + bx*half, y - ty*half + by*half, z - tz*half + bz*half]   # Top-left
    ]
    
    return vertices

def create_color_texture(colors, texture_file):
    """Create a simple color texture from the colors using basic Python."""
    try:
        # Create a simple PPM (Portable Pixmap) file - no external dependencies needed
        num_colors = len(colors)
        width = min(1024, num_colors)  # Max 1024 pixels wide
        height = max(1, (num_colors + width - 1) // width)  # Calculate height needed
        
        with open(texture_file, 'w') as f:
            # Write PPM header
            f.write("P3\n")
            f.write(f"{width} {height}\n")
            f.write("255\n")
            
            # Write pixel data
            for row in range(height):
                for col in range(width):
                    i = row * width + col
                    if i < num_colors:
                        color = colors[i]
                        # Convert from 0-1 range to 0-255 range
                        r = int(max(0, min(255, color[0] * 255)))
                        g = int(max(0, min(255, color[1] * 255)))
                        b = int(max(0, min(255, color[2] * 255)))
                        f.write(f"{r} {g} {b} ")
                    else:
                        f.write("0 0 0 ")  # Black for unused pixels
                f.write("\n")
        
        print(f"[WorldExplorer] Created color texture: {texture_file}")
        return width, height
        
    except Exception as e:
        print(f"[WorldExplorer] Error creating texture: {e}")
        return None, None

def write_obj_with_materials(positions, normals, colors, output_file):
    """Write OBJ + MTL with texture mapping and normal-oriented quads."""
    mtl_file = output_file.replace('.obj', '.mtl')
    texture_file = output_file.replace('.obj', '_texture.ppm')
    
    # Create texture if we have colors
    tex_width, tex_height = None, None
    if colors:
        tex_width, tex_height = create_color_texture(colors, texture_file)
    
    # Estimate normals if not provided using Open3D
    if not normals or len(normals) == 0:
        print("[WorldExplorer] Estimating normals for quad orientation...")
        import open3d as o3d
        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(np.array(positions))
        pcd.estimate_normals(
            search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1, max_nn=30)
        )
        normals_array = np.asarray(pcd.normals)
        normals = normals_array.tolist()
        print(f"[WorldExplorer] Estimated {len(normals)} normals")
    
    f = open(output_file, 'w')
    f.write("# Gaussian Splat OBJ (Unreal coords, normal-oriented quads)\n")
    f.write(f"mtllib {os.path.basename(mtl_file)}\n")
    f.write("usemtl color_texture\n")

    quad_size = 0.009  # Much smaller quads for finer detail
    
    # Write vertices using oriented quads
    for i, pos in enumerate(positions):
        normal = normals[i] if normals and i < len(normals) else [0, 0, 1]
        verts = create_oriented_quad(pos, normal, quad_size)
        for v in verts:
            f.write(f"v {v[0]:.6f} {v[1]:.6f} {v[2]:.6f}\n")

    # Write texture coordinates
    if colors and tex_width and tex_height:
        for i in range(len(positions)):
            # Calculate texture coordinates for this point
            col = i % tex_width
            row = i // tex_width
            u = (col + 0.5) / tex_width
            v = 1.0 - (row + 0.5) / tex_height  # Flip V coordinate
            
            # Each quad gets the same UV (point color)
            for _ in range(4):
                f.write(f"vt {u:.6f} {v:.6f}\n")

    # Write normals
    if normals:
        for n in normals:
            for _ in range(4):
                f.write(f"vn {n[0]:.6f} {n[1]:.6f} {n[2]:.6f}\n")

    # Write faces with texture coordinates
    for i in range(len(positions)):
        base = i*4+1
        if colors and tex_width:
            # Include texture coordinates in face definition
            if normals:
                f.write(f"f {base}/{base}/{base} {base+1}/{base+1}/{base+1} {base+2}/{base+2}/{base+2}\n")
                f.write(f"f {base}/{base}/{base} {base+2}/{base+2}/{base+2} {base+3}/{base+3}/{base+3}\n")
            else:
                f.write(f"f {base}/{base} {base+1}/{base+1} {base+2}/{base+2}\n")
                f.write(f"f {base}/{base} {base+2}/{base+2} {base+3}/{base+3}\n")
        else:
            if normals:
                f.write(f"f {base}//{base} {base+1}//{base+1} {base+2}//{base+2}\n")
                f.write(f"f {base}//{base} {base+2}//{base+2} {base+3}//{base+3}\n")
            else:
                f.write(f"f {base} {base+1} {base+2}\n")
                f.write(f"f {base} {base+2} {base+3}\n")
    f.close()

    # Write MTL file with texture reference
    with open(mtl_file, 'w') as f:
        f.write("# Material file with texture\n")
        f.write("newmtl color_texture\n")
        f.write("Ka 1.0 1.0 1.0\n")
        f.write("Kd 1.0 1.0 1.0\n")
        f.write("Ks 0.0 0.0 0.0\n")
        f.write("Ns 0.0\n")
        if colors and tex_width:
            f.write(f"map_Kd {os.path.basename(texture_file)}\n")

    print(f"[WorldExplorer] OBJ+MTL written → {output_file}")


# ============================================================
# === Geometry Nodes–like Remeshing ==========================
# ============================================================

def write_obj_with_vertex_colors(mesh, output_path):
    """Write OBJ file with vertex colors embedded in vertex definitions and create MTL file."""
    vertices = np.asarray(mesh.vertices)
    triangles = np.asarray(mesh.triangles)
    colors = np.asarray(mesh.vertex_colors) if mesh.has_vertex_colors() else None
    
    # Create MTL file path
    mtl_path = output_path.replace('.obj', '.mtl')
    mtl_name = os.path.basename(mtl_path)
    
    with open(output_path, 'w') as f:
        f.write("# OBJ file with vertex colors\n")
        f.write(f"# Vertices: {len(vertices)}\n")
        f.write(f"# Faces: {len(triangles)}\n")
        f.write(f"mtllib {mtl_name}\n")
        f.write("usemtl VertexColorMaterial\n\n")
        
        # Write vertices with colors
        for i, v in enumerate(vertices):
            if colors is not None and i < len(colors):
                # Write vertex with RGB color (0-1 range)
                f.write(f"v {v[0]:.6f} {v[1]:.6f} {v[2]:.6f} {colors[i][0]:.6f} {colors[i][1]:.6f} {colors[i][2]:.6f}\n")
            else:
                # Write vertex without color
                f.write(f"v {v[0]:.6f} {v[1]:.6f} {v[2]:.6f}\n")
        
        # Write faces (OBJ uses 1-based indexing)
        for tri in triangles:
            f.write(f"f {tri[0]+1} {tri[1]+1} {tri[2]+1}\n")
    
    # Create MTL file for vertex colored mesh
    with open(mtl_path, 'w') as f:
        f.write("# Material file for vertex colored mesh\n")
        f.write("# This material uses vertex colors embedded in the OBJ file\n")
        f.write("newmtl VertexColorMaterial\n")
        f.write("# Standard material properties\n")
        f.write("Ka 1.0 1.0 1.0\n")
        f.write("Kd 1.0 1.0 1.0\n")
        f.write("Ks 0.0 0.0 0.0\n")
        f.write("Ns 0.0\n")
        f.write("d 1.0\n")
        f.write("# Vertex colors are embedded in OBJ vertex definitions\n")
    
    print(f"[WorldExplorer] OBJ with vertex colors written: {output_path}")
    print(f"[WorldExplorer] MTL file created: {mtl_path}")

def geometry_nodes_like_remesh(positions, colors=None, poisson_depth=10, smooth_iterations=5, voxel_downsample=0.01):
    """Emulate Blender 'Points to Volume → Volume to Mesh' with color transfer.
    
    Args:
        positions: Point positions
        colors: Point colors (optional)
        poisson_depth: Depth for Poisson reconstruction (higher = more detail, 8-12 recommended)
        smooth_iterations: Number of smoothing iterations (higher = smoother)
        voxel_downsample: Voxel size for downsampling (smaller = more detail, 0 = no downsample)
    """
    positions_array = np.array(positions)
    if colors:
        colors_array = np.array(colors)
    
    # Build Open3D point cloud
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(positions_array)
    if colors:
        pcd.colors = o3d.utility.Vector3dVector(colors_array)
    
    # Optional voxel downsampling for uniformity
    if voxel_downsample > 0:
        pcd = pcd.voxel_down_sample(voxel_size=voxel_downsample)
        print(f"[WorldExplorer] Voxel downsampled to {len(pcd.points)} points")
    
    # Estimate normals with better parameters
    pcd.estimate_normals(
        search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=0.1, max_nn=30)
    )
    pcd.orient_normals_consistent_tangent_plane(k=15)

    # Create surface (Poisson) with higher quality
    print(f"[WorldExplorer] Running Poisson reconstruction (depth={poisson_depth})...")
    mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
        pcd, depth=poisson_depth, width=0, scale=1.1, linear_fit=False
    )
    
    # Remove low-density vertices (cleanup outlier geometry) - less aggressive
    densities = np.asarray(densities)
    density_threshold = np.quantile(densities, 0.001)  # Remove only bottom 0.1%
    vertices_to_remove = densities < density_threshold
    mesh.remove_vertices_by_mask(vertices_to_remove)
    
    # Clean up mesh
    mesh.remove_degenerate_triangles()
    mesh.remove_duplicated_triangles()
    mesh.remove_duplicated_vertices()
    mesh.remove_non_manifold_edges()
    
    # Apply Laplacian smoothing for cleaner surfaces
    if smooth_iterations > 0:
        print(f"[WorldExplorer] Applying Laplacian smoothing ({smooth_iterations} iterations)...")
        mesh = mesh.filter_smooth_laplacian(number_of_iterations=smooth_iterations)
    
    # Transfer colors from point cloud to mesh vertices
    if colors:
        print("[WorldExplorer] Transferring vertex colors...")
        mesh_vertices = np.asarray(mesh.vertices)
        pcd_points = np.asarray(pcd.points)
        pcd_colors = np.asarray(pcd.colors)
        
        # Filter out any NaN or inf values
        valid_mask = np.all(np.isfinite(mesh_vertices), axis=1)
        if not np.all(valid_mask):
            print(f"[WorldExplorer] Warning: Removing {np.sum(~valid_mask)} invalid vertices")
            mesh.remove_vertices_by_mask(~valid_mask)
            mesh_vertices = np.asarray(mesh.vertices)
        
        tree = cKDTree(pcd_points)
        distances, indices = tree.query(mesh_vertices, k=1)
        mesh_colors = pcd_colors[indices]
        mesh.vertex_colors = o3d.utility.Vector3dVector(mesh_colors)
    
    print(f"[WorldExplorer] Remeshed surface: {len(mesh.vertices)} vertices, {len(mesh.triangles)} triangles")
    return mesh


# ============================================================
# === Main Pipeline ==========================================
# ============================================================

def convert_gaussian_ply_to_obj_and_remesh(ply_file, output_path):
    # Handle both directory and file path inputs
    if output_path.endswith('.obj'):
        # It's a file path - use it directly for remeshed output
        output_dir = os.path.dirname(output_path)
        remeshed_path = output_path
    else:
        # It's a directory path
        output_dir = output_path
        remeshed_path = os.path.join(output_dir, "gaussian_remeshed.obj")
    
    os.makedirs(output_dir, exist_ok=True)

    print(f"[WorldExplorer] Reading PLY: {ply_file}")
    vertex_count, properties = read_ply_header(ply_file)
    positions, normals, colors = read_ply_data(ply_file, vertex_count, properties)
    print(f"[WorldExplorer] Loaded {len(positions)} vertices")

    positions, normals = convert_to_unreal_coordinates(positions, normals)

    # Keep maximum detail for high-quality remesh
    if len(positions) > 100000:
        positions, normals, colors = downsample_data(positions, normals, colors, 100000)
        print(f"[WorldExplorer] Downsampled to {len(positions)}")

    # Skip original OBJ, go straight to remesh
    print("[WorldExplorer] Performing MAXIMUM QUALITY volumetric remesh...")
    print("[WorldExplorer] WARNING: This will take 5-10 minutes for best quality!")
    # Parameters optimized for sparse reconstructions with motion blur
    mesh = geometry_nodes_like_remesh(
        positions, 
        colors, 
        poisson_depth=12,       # MAXIMUM detail (very slow but best quality)
        smooth_iterations=5,    # Less smoothing = preserve more detail
        voxel_downsample=0.002  # Ultra-fine sampling for maximum resolution
    )
    
    # Use custom OBJ writer that properly embeds vertex colors
    write_obj_with_vertex_colors(mesh, remeshed_path)
    print(f"[WorldExplorer] Remeshed OBJ saved: {remeshed_path}")

    return True


# ============================================================
# === Entry Point ============================================
# ============================================================

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 convert_gaussian_ply.py <input.ply> <output.obj|output_dir>")
        sys.exit(1)
    ply_file = sys.argv[1]
    output_path = sys.argv[2]
    convert_gaussian_ply_to_obj_and_remesh(ply_file, output_path)
