# Fix Unreal Engine Crash - ComfyStream Plugin

## The Problem
The crash is caused by struct layout changes in `FComfyStreamConfig`. When we added new properties, existing assets in your project may have corrupted references.

## Solution Steps

### Step 1: Clean Project Files
1. Close Unreal Editor completely
2. Delete these folders from your project:
   - `Binaries/`
   - `Intermediate/`
   - `Saved/`
3. Delete `Plugins/ComfyStream/Binaries/` and `Plugins/ComfyStream/Intermediate/`

### Step 2: Regenerate Project Files
1. Right-click on `Reconstruction_3D.uproject`
2. Select "Generate Visual Studio project files"
3. Open the project in Unreal Editor

### Step 3: Reset ComfyStreamActor Instances
If you have any ComfyStreamActor instances in your level:
1. Select them in the level
2. In the Details panel, reset the `DepthChannelConfig` and `RGBAChannelConfig` properties
3. Or delete and recreate the actors

### Step 4: Test the Plugin
1. Create a new ComfyStreamActor in your level
2. Set the server URL to your ComfyUI server
3. Press Play and test the image streaming

## What We Fixed
- Removed inline default values that could cause conflicts
- Added proper constructor initialization
- Added safety checks for invalid config values
- Added bounds checking for polling frequency

## If Crash Persists
1. Check the Unreal Engine crash logs in `Saved/Crashes/`
2. Try creating a new test level with just a ComfyStreamActor
3. Make sure your ComfyUI server is running and accessible
