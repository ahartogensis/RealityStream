#!/usr/bin/env python3
"""
Gaussian Splatting PLY to OBJ converter optimized for Unreal Engine.
Handles coordinate system conversions and ensures proper 3D output.
"""

import sys
import os
import struct
import math

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
            elif line.startswith('property float'):
                prop_name = line.split()[-1]
                properties.append(prop_name)
        
        return vertex_count, properties

def read_ply_data(file_path, vertex_count, properties):
    """Read PLY binary data."""
    positions = []
    normals = []
    colors = []
    
    with open(file_path, 'rb') as f:
        # Skip header
        while True:
            line_bytes = f.readline()
            if b'end_header' in line_bytes:
                break
        
        # Read vertex data
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
    
    return positions, normals if normals else None, colors if colors else None

def convert_to_unreal_coordinates(positions, normals):
    """Convert coordinates to Unreal Engine coordinate system."""
    if not positions:
        return positions, normals
    
    # Calculate ranges to understand the data
    x_coords = [pos[0] for pos in positions]
    y_coords = [pos[1] for pos in positions]
    z_coords = [pos[2] for pos in positions]
    
    x_range = max(x_coords) - min(x_coords)
    y_range = max(y_coords) - min(y_coords)
    z_range = max(z_coords) - min(z_coords)
    
    print(f"[WorldExplorer] Original coordinate ranges:")
    print(f"  X: {min(x_coords):.6f} to {max(x_coords):.6f} (span: {x_range:.6f})")
    print(f"  Y: {min(y_coords):.6f} to {max(y_coords):.6f} (span: {y_range:.6f})")
    print(f"  Z: {min(z_coords):.6f} to {max(z_coords):.6f} (span: {z_range:.6f})")
    
    # Check if we have a flat plane (Z range is very small)
    if z_range < 0.001 and x_range > z_range * 10 and y_range > z_range * 10:
        print("[WorldExplorer] WARNING: Detected flat plane - swapping Y and Z")
        # Swap Y and Z coordinates
        for i in range(len(positions)):
            positions[i][1], positions[i][2] = positions[i][2], positions[i][1]
            if normals:
                normals[i][1], normals[i][2] = normals[i][2], normals[i][1]
        
        # Recalculate ranges after swap
        x_coords = [pos[0] for pos in positions]
        y_coords = [pos[1] for pos in positions]
        z_coords = [pos[2] for pos in positions]
        z_range = max(z_coords) - min(z_coords)
        print(f"[WorldExplorer] After Y/Z swap - Z range: {min(z_coords):.6f} to {max(z_coords):.6f} (span: {z_range:.6f})")
    
    # Convert to Unreal Engine coordinate system
    # Unreal: X=Forward, Y=Right, Z=Up
    # Common: X=Right, Y=Up, Z=Forward
    print("[WorldExplorer] Converting to Unreal Engine coordinate system...")
    print("[WorldExplorer] Mapping: X->Y (Right), Y->Z (Up), Z->X (Forward)")
    
    for i in range(len(positions)):
        # Store original values
        orig_x, orig_y, orig_z = positions[i]
        
        # Convert to Unreal coordinates
        # X (Right) -> Y (Right)
        # Y (Up) -> Z (Up) 
        # Z (Forward) -> X (Forward)
        positions[i] = [orig_z, orig_x, orig_y]
        
        if normals:
            orig_nx, orig_ny, orig_nz = normals[i]
            normals[i] = [orig_nz, orig_nx, orig_ny]
    
    # Calculate new ranges
    x_coords = [pos[0] for pos in positions]
    y_coords = [pos[1] for pos in positions]
    z_coords = [pos[2] for pos in positions]
    
    print(f"[WorldExplorer] Unreal coordinate ranges:")
    print(f"  X (Forward): {min(x_coords):.6f} to {max(x_coords):.6f} (span: {max(x_coords) - min(x_coords):.6f})")
    print(f"  Y (Right): {min(y_coords):.6f} to {max(y_coords):.6f} (span: {max(y_coords) - min(y_coords):.6f})")
    print(f"  Z (Up): {min(z_coords):.6f} to {max(z_coords):.6f} (span: {max(z_coords) - min(z_coords):.6f})")
    
    return positions, normals

def downsample_data(positions, normals, colors, target_count=10000):
    """Downsample data to target count."""
    if len(positions) <= target_count:
        return positions, normals, colors
    
    step = max(1, len(positions) // target_count)
    positions = positions[::step]
    if normals:
        normals = normals[::step]
    if colors:
        colors = colors[::step]
    
    return positions, normals, colors

def cross_product(a, b):
    """Calculate cross product of two 3D vectors."""
    return [
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
    ]

def normalize_vector(v):
    """Normalize a 3D vector."""
    length = math.sqrt(v[0]**2 + v[1]**2 + v[2]**2)
    if length == 0:
        return [0, 0, 1]  # Default to up vector
    return [v[0] / length, v[1] / length, v[2] / length]

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
        
    except Exception as e:
        print(f"[WorldExplorer] Error creating texture: {e}")

def write_obj_file(positions, normals, colors, output_file):
    """Write OBJ file with Unreal Engine coordinate system."""
    # Create MTL file for materials
    mtl_file = output_file.replace('.obj', '.mtl')
    
    
    with open(output_file, 'w') as f:
        f.write("# Gaussian Splatting converted to OBJ for Unreal Engine\n")
        f.write("# Coordinate system: X=Forward, Y=Right, Z=Up\n")
        f.write(f"mtllib {os.path.basename(mtl_file)}\n")
        
        # Create quads (squares) for each point - smaller for better point cloud effect
        quad_size = 0.02  # Smaller size for more point-like appearance
        total_vertices = len(positions) * 4  # 4 vertices per quad
        total_faces = len(positions) * 2  # 2 triangles per quad
        
        f.write(f"# Vertices: {total_vertices} (4 per point)\n")
        f.write(f"# Faces: {total_faces} (2 triangles per point)\n\n")
        
        # Write vertices for quads oriented by normals (simplified approach)
        for i, pos in enumerate(positions):
            # Get the normal for this point
            if normals and i < len(normals):
                normal = normals[i]
            else:
                # Default to forward normal if no normal available
                normal = [1, 0, 0]
            
            # Create a simple perpendicular vector to the normal
            # Use a simple approach: if normal is mostly horizontal, use up vector
            if abs(normal[2]) < 0.7:  # Normal is mostly horizontal
                # Use Z-axis as the "up" direction for the quad
                right = [1, 0, 0]  # Always use X as right
                up = [0, 0, 1]     # Always use Z as up
            else:  # Normal is mostly vertical
                # Use Y-axis as the "up" direction for the quad
                right = [1, 0, 0]  # Always use X as right
                up = [0, 1, 0]     # Use Y as up
            
            # Scale by quad size
            half_size = quad_size * 0.5
            right_scaled = [right[0] * half_size, right[1] * half_size, right[2] * half_size]
            up_scaled = [up[0] * half_size, up[1] * half_size, up[2] * half_size]
            
            # Create 4 vertices for a quad oriented by the normal
            # Bottom-left
            v1 = [pos[0] - right_scaled[0] - up_scaled[0], 
                  pos[1] - right_scaled[1] - up_scaled[1], 
                  pos[2] - right_scaled[2] - up_scaled[2]]
            f.write(f"v {v1[0]:.6f} {v1[1]:.6f} {v1[2]:.6f}\n")
            
            # Bottom-right
            v2 = [pos[0] + right_scaled[0] - up_scaled[0], 
                  pos[1] + right_scaled[1] - up_scaled[1], 
                  pos[2] + right_scaled[2] - up_scaled[2]]
            f.write(f"v {v2[0]:.6f} {v2[1]:.6f} {v2[2]:.6f}\n")
            
            # Top-right
            v3 = [pos[0] + right_scaled[0] + up_scaled[0], 
                  pos[1] + right_scaled[1] + up_scaled[1], 
                  pos[2] + right_scaled[2] + up_scaled[2]]
            f.write(f"v {v3[0]:.6f} {v3[1]:.6f} {v3[2]:.6f}\n")
            
            # Top-left
            v4 = [pos[0] - right_scaled[0] + up_scaled[0], 
                  pos[1] - right_scaled[1] + up_scaled[1], 
                  pos[2] - right_scaled[2] + up_scaled[2]]
            f.write(f"v {v4[0]:.6f} {v4[1]:.6f} {v4[2]:.6f}\n")
        
        
        # Write normals if available (repeat for each quad vertex)
        if normals:
            for normal in normals:
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
        
        # Create faces for the quads (2 triangles per quad) - with color-based material groups
        f.write("\n# Small quads representing each Gaussian splat\n")
        
        # Group quads by color and assign different materials
        if colors:
            # Create more color groups for better color representation
            color_groups = {}
            group_colors = {}  # Store representative color for each group
            
            for i, color in enumerate(colors):
                # Boost saturation and brightness for more vibrant colors
                r, g, b = color[0], color[1], color[2]
                
                # Apply gamma correction and saturation boost
                r = min(1.0, r ** 0.7 * 1.3)  # Boost red
                g = min(1.0, g ** 0.7 * 1.3)  # Boost green  
                b = min(1.0, b ** 0.7 * 1.3)  # Boost blue
                
                # Create more granular color groups
                if r > 0.8 and g < 0.4 and b < 0.4:  # Strong red
                    group = "red_strong"
                elif r > 0.6 and g > 0.4 and b < 0.4:  # Orange/red
                    group = "orange"
                elif g > 0.8 and r < 0.4 and b < 0.4:  # Strong green
                    group = "green_strong"
                elif g > 0.6 and r > 0.4 and b < 0.4:  # Yellow/green
                    group = "yellow"
                elif b > 0.8 and r < 0.4 and g < 0.4:  # Strong blue
                    group = "blue_strong"
                elif b > 0.6 and g > 0.4 and r < 0.4:  # Cyan/blue
                    group = "cyan"
                elif b > 0.6 and r > 0.4 and g < 0.4:  # Purple/blue
                    group = "purple"
                elif r > 0.6 and g < 0.4 and b > 0.4:  # Magenta
                    group = "magenta"
                elif r > 0.7 and g > 0.7 and b > 0.7:  # White/light
                    group = "white"
                elif r < 0.3 and g < 0.3 and b < 0.3:  # Dark
                    group = "black"
                else:  # Mixed colors - use the most dominant
                    if r > g and r > b:
                        group = "red_mixed"
                    elif g > r and g > b:
                        group = "green_mixed"
                    else:
                        group = "blue_mixed"
                
                if group not in color_groups:
                    color_groups[group] = []
                    group_colors[group] = [r, g, b]  # Store the first color as representative
                
                color_groups[group].append(i)
            
            # Write faces grouped by material
            for group_name, indices in color_groups.items():
                f.write(f"usemtl {group_name}_material\n")
                for i in indices:
                    v1 = i * 4 + 1  # Bottom-left
                    v2 = i * 4 + 2  # Bottom-right
                    v3 = i * 4 + 3  # Top-right
                    v4 = i * 4 + 4  # Top-left
                    
                    # Create two triangles for each quad
                    f.write(f"f {v1} {v2} {v3}\n")
                    f.write(f"f {v1} {v3} {v4}\n")
        else:
            # No colors, use single material
            f.write("usemtl gaussian_material\n")
            for i in range(len(positions)):
                v1 = i * 4 + 1  # Bottom-left
                v2 = i * 4 + 2  # Bottom-right
                v3 = i * 4 + 3  # Top-right
                v4 = i * 4 + 4  # Top-left
                
                # Create two triangles for each quad
                f.write(f"f {v1} {v2} {v3}\n")
                f.write(f"f {v1} {v3} {v4}\n")
    
    # Create MTL file for materials
    with open(mtl_file, 'w') as f:
        f.write("# Material file for Gaussian Splatting\n")
        
        if colors:
            # Use boosted colors from the data
            # First, calculate the color groups and their representative colors
            color_groups = {}
            group_colors = {}
            
            for i, color in enumerate(colors):
                # Boost saturation and brightness for more vibrant colors
                r, g, b = color[0], color[1], color[2]
                
                # Apply gamma correction and saturation boost
                r = min(1.0, r ** 0.7 * 1.3)  # Boost red
                g = min(1.0, g ** 0.7 * 1.3)  # Boost green  
                b = min(1.0, b ** 0.7 * 1.3)  # Boost blue
                
                # Create more granular color groups
                if r > 0.8 and g < 0.4 and b < 0.4:  # Strong red
                    group = "red_strong"
                elif r > 0.6 and g > 0.4 and b < 0.4:  # Orange/red
                    group = "orange"
                elif g > 0.8 and r < 0.4 and b < 0.4:  # Strong green
                    group = "green_strong"
                elif g > 0.6 and r > 0.4 and b < 0.4:  # Yellow/green
                    group = "yellow"
                elif b > 0.8 and r < 0.4 and g < 0.4:  # Strong blue
                    group = "blue_strong"
                elif b > 0.6 and g > 0.4 and r < 0.4:  # Cyan/blue
                    group = "cyan"
                elif b > 0.6 and r > 0.4 and g < 0.4:  # Purple/blue
                    group = "purple"
                elif r > 0.6 and g < 0.4 and b > 0.4:  # Magenta
                    group = "magenta"
                elif r > 0.7 and g > 0.7 and b > 0.7:  # White/light
                    group = "white"
                elif r < 0.3 and g < 0.3 and b < 0.3:  # Dark
                    group = "black"
                else:  # Mixed colors - use the most dominant
                    if r > g and r > b:
                        group = "red_mixed"
                    elif g > r and g > b:
                        group = "green_mixed"
                    else:
                        group = "blue_mixed"
                
                if group not in color_groups:
                    color_groups[group] = []
                    group_colors[group] = [r, g, b]  # Store the first color as representative
                
                color_groups[group].append(i)
            
            # Create materials with boosted colors
            for group in group_colors:
                r, g, b = group_colors[group]
                
                f.write(f"newmtl {group}_material\n")
                f.write(f"Ka {r:.3f} {g:.3f} {b:.3f}\n")  # Ambient color
                f.write(f"Kd {r:.3f} {g:.3f} {b:.3f}\n")  # Diffuse color
                f.write("Ks 0.0 0.0 0.0\n")  # Specular color
                f.write("Ns 0.0\n")          # Specular exponent
                f.write("d 1.0\n")           # Dissolve (transparency)
                f.write("illum 2\n")         # Illumination model
                f.write("\n")
        else:
            # Default material if no colors
            f.write("newmtl gaussian_material\n")
            f.write("Ka 0.5 0.5 0.5\n")  # Ambient color
            f.write("Kd 0.5 0.5 0.5\n")  # Diffuse color
            f.write("Ks 0.0 0.0 0.0\n")  # Specular color
            f.write("Ns 0.0\n")          # Specular exponent
            f.write("d 1.0\n")           # Dissolve (transparency)
            f.write("illum 2\n")         # Illumination model
            f.write("\n")

def convert_gaussian_ply_to_obj(ply_file, obj_file):
    """Convert Gaussian Splatting PLY to OBJ for Unreal Engine."""
    print(f"[WorldExplorer] Converting Gaussian Splat PLY -> OBJ (Unreal Engine)")
    print(f"  Input:  {ply_file}")
    print(f"  Output: {obj_file}")
    print(f"[WorldExplorer] Current working directory: {os.getcwd()}")
    print(f"[WorldExplorer] Python executable: {sys.executable}")

    if not os.path.exists(ply_file):
        print(f"[WorldExplorer] ERROR: File not found: {ply_file}")
        print(f"[WorldExplorer] Available files in directory:")
        try:
            dir_path = os.path.dirname(ply_file)
            if os.path.exists(dir_path):
                for file in os.listdir(dir_path):
                    print(f"  {file}")
        except:
            print("  Could not list directory contents")
        return False

    try:
        # Read PLY file
        print("[WorldExplorer] Reading PLY file...")
        vertex_count, properties = read_ply_header(ply_file)
        print(f"[WorldExplorer] Found {vertex_count} vertices with {len(properties)} properties")
        
        positions, normals, colors = read_ply_data(ply_file, vertex_count, properties)
        print(f"[WorldExplorer] Loaded {len(positions)} points")
        
        # Convert to Unreal Engine coordinate system
        positions, normals = convert_to_unreal_coordinates(positions, normals)
        
        # Downsample if too many points
        if len(positions) > 10000:
            print(f"[WorldExplorer] Downsampling from {len(positions)} to 10000 points...")
            positions, normals, colors = downsample_data(positions, normals, colors, 10000)
        
        # Write OBJ file
        print("[WorldExplorer] Writing OBJ file...")
        write_obj_file(positions, normals, colors, obj_file)
        
        print(f"[WorldExplorer] SUCCESS: Created {obj_file}")
        print(f"[WorldExplorer] Vertices: {len(positions)}")
        return True
        
    except Exception as e:
        print(f"[WorldExplorer] ERROR: {e}")
        return False

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 convert_gaussian_unreal.py <input.ply> <output.obj>")
        sys.exit(1)

    ply_path = sys.argv[1]
    obj_path = sys.argv[2]
    
    success = convert_gaussian_ply_to_obj(ply_path, obj_path)
    sys.exit(0 if success else 1)
