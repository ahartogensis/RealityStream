#!/usr/bin/env python3
"""
Docker-compatible version of the Gaussian Splatting PLY to OBJ converter.
This script is designed to work in the Docker environment with proper dependencies.
"""

import sys
import os
import numpy as np
import open3d as o3d

def read_gaussian_ply(ply_file):
    """Read Gaussian Splatting PLY file using open3d."""
    print(f"[WorldExplorer] Reading Gaussian Splatting PLY: {ply_file}")
    
    # Use open3d to read the PLY file
    pcd = o3d.io.read_point_cloud(ply_file)
    
    if len(pcd.points) == 0:
        print("[WorldExplorer] ERROR: No points found in PLY file")
        return None, None, None
    
    # Convert to numpy arrays
    positions = np.asarray(pcd.points)
    normals = np.asarray(pcd.normals) if pcd.has_normals() else None
    colors = np.asarray(pcd.colors) if pcd.has_colors() else None
    
    print(f"[WorldExplorer] Found {len(positions)} Gaussian splats")
    print(f"[WorldExplorer] Has normals: {normals is not None}")
    print(f"[WorldExplorer] Has colors: {colors is not None}")
    
    return positions, normals, colors

def convert_gaussian_ply_to_obj(ply_file, obj_file, method="mesh", voxel_size=0.01):
    """Convert Gaussian Splatting PLY to OBJ format."""
    print(f"[WorldExplorer] Converting Gaussian Splat PLY -> OBJ")
    print(f"  Input:  {ply_file}")
    print(f"  Output: {obj_file}")
    print(f"  Method: {method}, voxel={voxel_size}")

    if not os.path.exists(ply_file):
        print(f"[WorldExplorer] ERROR: File not found: {ply_file}")
        sys.exit(1)

    # Read Gaussian Splatting data
    positions, normals, colors = read_gaussian_ply(ply_file)
    
    if positions is None or len(positions) == 0:
        print("[WorldExplorer] ERROR: No Gaussian splats found in PLY.")
        sys.exit(1)

    print(f"[WorldExplorer] Loaded {len(positions)} Gaussian splats")
    print(f"[WorldExplorer] Position range: X[{positions[:, 0].min():.4f}, {positions[:, 0].max():.4f}], Y[{positions[:, 1].min():.4f}, {positions[:, 1].max():.4f}], Z[{positions[:, 2].min():.4f}, {positions[:, 2].max():.4f}]")

    # Check if we have a flat plane (all Z values are nearly the same)
    z_range = positions[:, 2].max() - positions[:, 2].min()
    if z_range < 0.001:
        print("[WorldExplorer] WARNING: Detected flat plane - Z range is very small")
        print("[WorldExplorer] This might be due to coordinate system or scale issues")
        
        # Try to detect if this is a coordinate system issue
        x_range = positions[:, 0].max() - positions[:, 0].min()
        y_range = positions[:, 1].max() - positions[:, 1].min()
        
        if x_range > z_range * 10 and y_range > z_range * 10:
            print("[WorldExplorer] Attempting to fix coordinate system - swapping Y and Z")
            # Swap Y and Z coordinates (common issue with some Gaussian Splatting exports)
            positions[:, [1, 2]] = positions[:, [2, 1]]
            if normals is not None:
                normals[:, [1, 2]] = normals[:, [2, 1]]
            print(f"[WorldExplorer] New Z range: {positions[:, 2].min():.4f} -> {positions[:, 2].max():.4f}")

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

    # Downsample if requested
    if voxel_size > 0 and len(pcd.points) > 10000:
        print(f"[WorldExplorer] Downsampling from {len(pcd.points)} to reduce complexity...")
        pcd = pcd.voxel_down_sample(voxel_size)
        print(f"[WorldExplorer] Downsampled to {len(pcd.points)} points")

    # Reconstruct mesh if requested
    if method == "mesh":
        print("[WorldExplorer] Reconstructing mesh using Poisson reconstruction...")
        try:
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
        f.write(f"# Original splats: {len(pcd.points)}\n\n")
        
        # Write vertices
        for i, pos in enumerate(pcd.points):
            f.write(f"v {pos[0]:.6f} {pos[1]:.6f} {pos[2]:.6f}")
            if pcd.has_colors():
                color = pcd.colors[i]
                f.write(f" {color[0]:.6f} {color[1]:.6f} {color[2]:.6f}")
            f.write("\n")
        
        # Write normals if available
        if pcd.has_normals():
            for normal in pcd.normals:
                f.write(f"vn {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}\n")
        
        f.write("\n# Point cloud - no faces\n")
    
    print(f"[WorldExplorer] SUCCESS: Wrote point cloud OBJ: {obj_file}")
    print(f"[WorldExplorer] Vertices={len(pcd.points)}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 convert_gaussian_ply_docker.py <input.ply> <output.obj>")
        sys.exit(1)

    ply_path = sys.argv[1]
    obj_path = sys.argv[2]
    convert_gaussian_ply_to_obj(ply_path, obj_path)
