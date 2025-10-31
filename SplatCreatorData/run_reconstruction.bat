@echo off
setlocal enabledelayedexpansion
title WorldExplorer Reconstruction
cd /d "%~dp0"
echo ========================================
echo   WorldExplorer Reconstruction Pipeline
echo ========================================
echo Starting at %DATE% %TIME%
echo This will take 6-8 minutes
echo DO NOT CLOSE this window!
echo ========================================
echo.
docker run --rm --gpus all -v "C:/Users/alexi/OneDrive/Documents/Unreal Projects/Reconstruction_3D/Plugins/ComfyStream/WorldExplorerData:/workspace/data" -v "C:/Users/alexi/OneDrive/Documents/Unreal Projects/Reconstruction_3D/Plugins/ComfyStream/WorldExplorerOutputs:/workspace/outputs" -v "C:/Users/alexi/OneDrive/Documents/Unreal Projects/Reconstruction_3D/:/workspace/project" gaussian-splatting:optimized bash -lc "rm -rf /workspace/data/input /workspace/data/sparse /workspace/data/distorted /workspace/data/temp /workspace/data/database.db || true && mkdir -p /workspace/data/input && ffmpeg -y -i /workspace/data/input_video.* -qscale:v 1 -qmin 1 -vf fps=10 /workspace/data/input/frame_%%04d.jpg && python3 /workspace/gaussian-splatting/convert.py -s /workspace/data && colmap model_converter --input_path /workspace/data/sparse/0 --output_path /workspace/outputs/point_cloud.ply --output_type PLY && python3 /workspace/project/Plugins/ComfyStream/convert_gaussian_ply.py /workspace/outputs/point_cloud.ply /workspace/outputs/point_cloud.obj && echo '=== Cleaning up temporary files... ===' && rm -rf /workspace/data/input /workspace/data/sparse /workspace/data/distorted /workspace/data/temp /workspace/data/database.db || true && echo '=== Cleanup complete! OBJ ready for import. ===' && ls -lh /workspace/outputs/point_cloud.obj"
set EXITCODE=!ERRORLEVEL!
echo.
echo ========================================
if not !EXITCODE!==0 (
  echo ERROR: Docker command failed (code !EXITCODE!)
  echo - Ensure Docker Desktop is running
  echo - Ensure GPU is available to Docker
) else (
  echo RECONSTRUCTION COMPLETE!
  echo Mesh will auto-spawn in Unreal Engine!
)
echo ========================================
pause
