@echo off
echo Building Gaussian Splatting Docker image...
echo.

REM Change to the ComfyStream directory
cd /d "%~dp0"

REM Build the Docker image
docker build -f Dockerfile.gaussian-splatting -t gaussian-splatting:optimized .

if %ERRORLEVEL% EQU 0 (
    echo.
    echo SUCCESS: Docker image 'gaussian-splatting:optimized' built successfully!
    echo You can now use the Gaussian Splatting conversion features.
) else (
    echo.
    echo ERROR: Failed to build Docker image.
    echo Please check the Docker installation and try again.
)

pause
