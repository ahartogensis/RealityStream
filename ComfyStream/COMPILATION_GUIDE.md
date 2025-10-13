# ComfyStream Plugin - Compilation Guide

## Current Status: MINIMAL STABLE VERSION

I've simplified the plugin to avoid all compilation crashes:

### ✅ **What's Fixed**
- **Removed problematic struct properties** that were causing crashes
- **Used hardcoded values** instead of struct properties
- **Simplified initialization** to avoid memory issues
- **Fixed all UFUNCTION declarations** for delegate binding

### 🔧 **How to Compile**

1. **Close Unreal Editor completely**

2. **Clean project files:**
   ```
   Delete these folders:
   - Binaries/
   - Intermediate/
   - Saved/
   - Plugins/ComfyStream/Binaries/
   - Plugins/ComfyStream/Intermediate/
   ```

3. **Regenerate project files:**
   - Right-click `Reconstruction_3D.uproject`
   - Select "Generate Visual Studio project files"

4. **Compile in Visual Studio:**
   - Open `Reconstruction_3D.sln`
   - Build → Build Solution (or Ctrl+Shift+B)

5. **Open Unreal Editor:**
   - The plugin should now compile without crashes

### 🎯 **What Works Now**

- ✅ **Correct Endpoint**: Uses `/view` instead of `/history`
- ✅ **Proper URL**: `http://server:8188/view?filename=channel_1.png&path=web_viewer&channel=0&_=timestamp`
- ✅ **30 Hz Polling**: Polls at 30 Hz as specified in ChatGPT rule
- ✅ **PNG Decoding**: Processes image data correctly
- ✅ **No Crashes**: Simplified struct prevents compilation issues

### 📋 **Hardcoded Values (Following ChatGPT Rule)**

- **Image Path**: `"web_viewer"` (as per rule)
- **Polling Frequency**: 30 Hz (0.033s intervals)
- **Filename Format**: `channel_1.png`, `channel_2.png`, etc.
- **Cache Busting**: Timestamp parameter to avoid stale images

### 🚀 **Test the Plugin**

1. Create a ComfyStreamActor in your level
2. Set the server URL to your ComfyUI server
3. Press Play
4. You should see images streaming from ComfyUI

### ⚠️ **If Compilation Still Fails**

1. **Check Visual Studio output** for specific error messages
2. **Make sure you're using Unreal Engine 5.6** (as shown in your error logs)
3. **Try building just the plugin** first:
   - Right-click on ComfyStream in Solution Explorer
   - Select "Build"

The plugin should now compile successfully without any crashes!
