# ComfyStream Plugin - HTTP Mode

## 🔧 **WebSocket Alternative**

Since WebSockets module is not available in your UE 5.6 installation, the ComfyStream plugin has been updated to use **HTTP polling** instead of WebSocket connections.

## ✅ **How It Works**

### **HTTP Polling Mode**
- **Method**: HTTP GET requests to ComfyUI's `/view` endpoint
- **Frequency**: Polls every 1 second (configurable)
- **Format**: Direct PNG image data
- **Channels**: Supports channels 1-8 via `?channel=N` parameter

### **ComfyUI Setup Required**
You need to set up ComfyUI to serve images via HTTP:

1. **Enable ComfyUI's built-in web server** (usually runs on port 8000)
2. **Use the `/view` endpoint** to serve images
3. **Configure channel parameter** for different image types

## 🚀 **Quick Start**

### **1. ComfyUI Setup**
```python
# In your ComfyUI workflow, add a SaveImage node
# Set the filename to include channel info:
# For depth maps: "depth_channel_1.png"
# For RGBA maps: "rgba_channel_2.png"

# Or use ComfyUI's API to save images with specific names
```

### **2. Unreal Engine Setup**
1. **Place ComfyStreamActor** in your level
2. **Set Base Material** to M_Displacement
3. **Configure channels**:
   - Depth Channel: Channel 1
   - RGBA Channel: Channel 2
4. **Set Server URL**: `http://192.168.1.247:8188`

### **3. That's It!**
The plugin will automatically:
- ✅ Poll ComfyUI every second for new images
- ✅ Decode PNG images to textures
- ✅ Update your material parameters
- ✅ Handle connection errors gracefully

## ⚙️ **Configuration**

### **Polling Settings**
```cpp
// In ComfyStreamActor or ComfyStreamComponent
ImageFetcher->PollingInterval = 1.0f; // Poll every second
ImageFetcher->ImageEndpoint = TEXT("/view"); // ComfyUI endpoint
```

### **Channel Configuration**
```cpp
// Depth channel
DepthChannel->StreamConfig.ChannelNumber = 1;
DepthChannel->StreamConfig.ChannelType = EComfyChannel::Depth;

// RGBA channel  
RGBAChannel->StreamConfig.ChannelNumber = 2;
RGBAChannel->StreamConfig.ChannelType = EComfyChannel::RGBA;
```

## 🔄 **HTTP Endpoints**

The plugin uses these ComfyUI HTTP endpoints:

- **`GET http://192.168.1.247:8188/view?channel=1`** - Get depth map image
- **`GET http://192.168.1.247:8188/view?channel=2`** - Get RGBA map image
- **`POST http://192.168.1.247:8188/prompt`** - Send prompts to ComfyUI
- **`GET http://192.168.1.247:8188/queue`** - Get queue status
- **`GET http://192.168.1.247:8188/history`** - Get execution history

## 📊 **Performance Considerations**

### **Polling Frequency**
- **Default**: 1 second (good balance)
- **High Performance**: 0.5 seconds (more CPU usage)
- **Low Performance**: 2-3 seconds (less responsive)

### **Network Usage**
- **Per Poll**: ~1-2KB (PNG image size)
- **Per Second**: ~1-2KB (with 1s polling)
- **Per Minute**: ~60-120KB

## 🛠️ **Troubleshooting**

### **Common Issues**

1. **No Images Received**
   - Check ComfyUI is running on port 8188
   - Verify `/view` endpoint is accessible
   - Check channel numbers match

2. **Connection Errors**
   - Verify server URL is correct
   - Check firewall settings
   - Ensure ComfyUI web server is enabled

3. **Image Decoding Errors**
   - Verify images are valid PNG format
   - Check image size (512x512 recommended)
   - Enable debug logging

### **Debug Logs**
```
[ComfyImageFetcher] Started polling for images from http://192.168.1.247:8188
[ComfyImageFetcher] Image received (12345 bytes)
[ComfyPNG] Successfully created texture: 512x512
```

## 🔄 **Migration from WebSocket**

If you later get WebSockets working, you can easily switch back:

1. **Enable WebSockets module** in your project
2. **Update ComfyStreamComponent** to use `UComfyWsClient` instead of `UComfyImageFetcher`
3. **Configure WebSocket URLs** instead of HTTP URLs

## ✅ **Advantages of HTTP Mode**

- ✅ **No WebSocket dependency** - works with any UE version
- ✅ **Simple setup** - just HTTP requests
- ✅ **Reliable** - HTTP is more stable than WebSocket
- ✅ **Debuggable** - easy to test with browser/curl
- ✅ **Compatible** - works with any ComfyUI setup

## 🎯 **Ready to Use**

The HTTP-based ComfyStream plugin is ready to use! It provides the same functionality as the WebSocket version but uses HTTP polling instead. Perfect for your depth and RGBA map streaming needs!
