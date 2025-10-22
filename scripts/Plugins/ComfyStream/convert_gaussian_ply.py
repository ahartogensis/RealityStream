#!/usr/bin/env python3
import sys, os
import struct
import math

# Try to import optional dependencies
try:
    import numpy as np
    # Test if numpy actually works
    test_array = np.array([1, 2, 3])
    HAS_NUMPY = True
except (ImportError, AttributeError):
    HAS_NUMPY = False
    print("WARNING: numpy not available or corrupted - using basic Python implementation")

try:
    import open3d as o3d
    HAS_OPEN3D = True
except ImportError:
    HAS_OPEN3D = False
    print("WARNING: open3d not available - using basic PLY reader")

def read_gaussian_ply_basic(ply_file):
    """Basic PLY reader without external dependencies."""
    print(f"[WorldExplorer] Reading PLY file (basic mode): {ply_file}")
    
    with open(ply_file, 'rb') as f:
        # Read header
        header_lines = []
        while True:
            line_bytes = f.readline()
            try:
                line = line_bytes.decode('utf-8').strip()
            except UnicodeDecodeError:
                # If we can't decode as UTF-8, try to find the end of header
                # by looking for the binary data start
                if b'end_header' in line_bytes:
                    line = 'end_header'
                else:
                    # Skip this line and continue
                    continue
            header_lines.append(line)
            if line == 'end_header':
                break
        
        # Parse header
        vertex_count = 0
        properties = []
        for line in header_lines:
            if line.startswith('element vertex'):
                vertex_count = int(line.split()[-1])
            elif line.startswith('property float'):
                prop_name = line.split()[-1]
                properties.append(prop_name)
        
        print(f"[WorldExplorer] Found {vertex_count} vertices with {len(properties)} properties")
        
        # Read binary data
        positions = []
        normals = []
        colors = []
        
        for i in range(vertex_count):
            vertex_data = struct.unpack('f' * len(properties), f.read(4 * len(properties)))
            
            # Extract position (x, y, z)
            positions.append(vertex_data[:3])
            
            # Extract normals if available
            if 'nx' in properties and 'ny' in properties and 'nz' in properties:
                nx_idx = properties.index('nx')
                normals.append(vertex_data[nx_idx:nx_idx+3])
            
            # Extract colors from spherical harmonics if available
            if 'f_dc_0' in properties and 'f_dc_1' in properties and 'f_dc_2' in properties:
                dc_0_idx = properties.index('f_dc_0')
                sh_dc = vertex_data[dc_0_idx:dc_0_idx+3]
                # Convert spherical harmonics to RGB (simplified)
                rgb = [max(0, min(1, (1.0 / (1.0 + math.exp(-x))))) for x in sh_dc]
                colors.append(rgb)
        
        return positions, normals if normals else None, colors if colors else None, None

def read_gaussian_ply(ply_file):
    """Read Gaussian Splatting PLY file and extract positions, colors, and other properties."""
    print(f"[WorldExplorer] Reading Gaussian Splatting PLY: {ply_file}")
    
    if HAS_OPEN3D:
        # Use open3d to read the PLY file
        pcd = o3d.io.read_point_cloud(ply_file)
        
        if len(pcd.points) == 0:
            print("[WorldExplorer] ERROR: No points found in PLY file")
            return None, None, None, None
        
        # Convert to numpy arrays
        positions = np.asarray(pcd.points)
        normals = np.asarray(pcd.normals) if pcd.has_normals() else None
        colors = np.asarray(pcd.colors) if pcd.has_colors() else None
        
        print(f"[WorldExplorer] Found {len(positions)} Gaussian splats")
        print(f"[WorldExplorer] Has normals: {normals is not None}")
        print(f"[WorldExplorer] Has colors: {colors is not None}")
        
        return positions, normals, colors, None
    else:
        # Use basic reader
        return read_gaussian_ply_basic(ply_file)

def convert_gaussian_ply_to_obj(ply_file, obj_file, method="mesh", voxel_size=0.01):
    print(f"[WorldExplorer] Converting Gaussian Splat PLY -> OBJ")
    print(f"  Input:  {ply_file}")
    print(f"  Output: {obj_file}")
    print(f"  Method: {method}, voxel={voxel_size}")

    if not os.path.exists(ply_file):
        print(f"[WorldExplorer] ERROR: File not found: {ply_file}")
        sys.exit(1)

    # Read Gaussian Splatting data
    positions, normals, colors, properties = read_gaussian_ply(ply_file)
    
    if positions is None or len(positions) == 0:
        print("[WorldExplorer] ERROR: No Gaussian splats found in PLY.")
        sys.exit(1)

    print(f"[WorldExplorer] Loaded {len(positions)} Gaussian splats")
    
    # Convert to numpy arrays if not already
    if HAS_NUMPY and not hasattr(positions, 'shape'):
        positions = np.array(positions)
        if normals is not None:
            normals = np.array(normals)
        if colors is not None:
            colors = np.array(colors)
    
    # Calculate ranges
    if HAS_NUMPY:
        x_min, x_max = positions[:, 0].min(), positions[:, 0].max()
        y_min, y_max = positions[:, 1].min(), positions[:, 1].max()
        z_min, z_max = positions[:, 2].min(), positions[:, 2].max()
    else:
        x_coords = [pos[0] for pos in positions]
        y_coords = [pos[1] for pos in positions]
        z_coords = [pos[2] for pos in positions]
        x_min, x_max = min(x_coords), max(x_coords)
        y_min, y_max = min(y_coords), max(y_coords)
        z_min, z_max = min(z_coords), max(z_coords)
    
    print(f"[WorldExplorer] Position range: X[{x_min:.4f}, {x_max:.4f}], Y[{y_min:.4f}, {y_max:.4f}], Z[{z_min:.4f}, {z_max:.4f}]")

    # Check if we have a flat plane (all Z values are nearly the same)
    z_range = z_max - z_min
    if z_range < 0.001:
        print("[WorldExplorer] WARNING: Detected flat plane - Z range is very small")
        print("[WorldExplorer] This might be due to coordinate system or scale issues")
        
        # Try to detect if this is a coordinate system issue
        x_range = x_max - x_min
        y_range = y_max - y_min
        
        if x_range > z_range * 10 and y_range > z_range * 10:
            print("[WorldExplorer] Attempting to fix coordinate system - swapping Y and Z")
            # Swap Y and Z coordinates (common issue with some Gaussian Splatting exports)
            if HAS_NUMPY:
                positions[:, [1, 2]] = positions[:, [2, 1]]
                if normals is not None:
                    normals[:, [1, 2]] = normals[:, [2, 1]]
            else:
                # Swap for basic Python lists
                for i in range(len(positions)):
                    positions[i][1], positions[i][2] = positions[i][2], positions[i][1]
                    if normals is not None:
                        normals[i][1], normals[i][2] = normals[i][2], normals[i][1]
            
            # Recalculate Z range
            if HAS_NUMPY:
                z_min, z_max = positions[:, 2].min(), positions[:, 2].max()
            else:
                z_coords = [pos[2] for pos in positions]
                z_min, z_max = min(z_coords), max(z_coords)
            print(f"[WorldExplorer] New Z range: {z_min:.4f} -> {z_max:.4f}")

    # Downsample if requested (simple uniform sampling)
    if voxel_size > 0 and len(positions) > 10000:
        print(f"[WorldExplorer] Downsampling from {len(positions)} to reduce complexity...")
        step = max(1, len(positions) // 10000)
        positions = positions[::step]
        if normals is not None:
            normals = normals[::step]
        if colors is not None:
            colors = colors[::step]
        print(f"[WorldExplorer] Downsampled to {len(positions)} points")

    # Reconstruct mesh if requested and open3d is available
    if method == "mesh" and HAS_OPEN3D:
        print("[WorldExplorer] Reconstructing mesh using Poisson reconstruction...")
        try:
            # Create point cloud for mesh reconstruction
            pcd = o3d.geometry.PointCloud()
            pcd.points = o3d.utility.Vector3dVector(positions)
            
            if normals is not None:
                pcd.normals = o3d.utility.Vector3dVector(normals)
            else:
                # Estimate normals if not available
                print("[WorldExplorer] Estimating normals...")
                pcd.estimate_normals()
                pcd.orient_normals_consistent_tangent_plane(100)
            
            if colors is not None:
                pcd.colors = o3d.utility.Vector3dVector(colors)
            
            mesh, _ = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(pcd, depth=9)
            # Crop mesh to original point cloud bounding box
            bbox = pcd.get_axis_aligned_bounding_box()
            mesh = mesh.crop(bbox)
            
            # Clean mesh
            mesh.remove_degenerate_triangles()
            mesh.remove_duplicated_triangles()
            mesh.remove_duplicated_vertices()
            mesh.remove_non_manifold_edges()
            mesh.compute_vertex_normals()
            
            # Save mesh
            o3d.io.write_triangle_mesh(obj_file, mesh)
            print(f"[WorldExplorer] SUCCESS: Wrote mesh OBJ: {obj_file}")
            print(f"[WorldExplorer] Vertices={len(mesh.vertices)} Faces={len(mesh.triangles)}")
            return
            
        except Exception as e:
            print(f"[WorldExplorer] WARNING: Mesh reconstruction failed: {e}")
            print("[WorldExplorer] Falling back to point cloud export...")
            method = "point_cloud"
    
    # Export as point cloud (fallback or requested method)
    print("[WorldExplorer] Exporting as point cloud...")
    with open(obj_file, 'w') as f:
        f.write("# Gaussian Splatting converted to OBJ (Point Cloud)\n")
        f.write(f"# Original splats: {len(positions)}\n\n")
        
        # Write vertices
        for i, pos in enumerate(positions):
            f.write(f"v {pos[0]:.6f} {pos[1]:.6f} {pos[2]:.6f}")
            if colors is not None:
                color = colors[i]
                f.write(f" {color[0]:.6f} {color[1]:.6f} {color[2]:.6f}")
            f.write("\n")
        
        # Write normals if available
        if normals is not None:
            for normal in normals:
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
        
        f.write("\n# Point cloud - no faces\n")
    
    print(f"[WorldExplorer] SUCCESS: Wrote point cloud OBJ: {obj_file}")
    print(f"[WorldExplorer] Vertices={len(positions)}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 convert_gaussian_ply.py <input.ply> <output.obj>")
        sys.exit(1)

    ply_path = sys.argv[1]
    obj_path = sys.argv[2]
    convert_gaussian_ply_to_obj(ply_path, obj_path)
