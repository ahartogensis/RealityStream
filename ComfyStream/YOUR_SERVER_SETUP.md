# ComfyStream Plugin - Your Server Setup

## 🎯 **Your Server Configuration**

- **HTTP Server**: `192.168.1.247:8188` (ComfyUI main server)
- **WebSocket Server**: `192.168.1.247:8001` (WebViewer server)

## 🚀 **Quick Setup Guide**

### **1. ComfyUI Setup**

Make sure your ComfyUI is running and accessible:

1. **Start ComfyUI** on `192.168.1.247:8188`
2. **Enable WebViewer** on `192.168.1.247:8001`
3. **Configure your workflow** to output images to the `/view` endpoint

### **2. Unreal Engine Setup**

1. **Place ComfyStreamActor** in your level
2. **Set Base Material** to M_Displacement
3. **Configure channels**:
   - **Depth Channel**: Channel 1
   - **RGBA Channel**: Channel 2
4. **Server URL**: `http://192.168.1.247:8188` (already set as default)

### **3. Test Connection**

You can test the connection using a web browser:

- **Depth Map**: `http://192.168.1.247:8188/view?channel=1`
- **RGBA Map**: `http://192.168.1.247:8188/view?channel=2`

## 🔧 **Configuration Details**

### **Default Settings (Already Configured)**

```cpp
// Depth Channel
ServerURL = "http://192.168.1.247:8188"
ChannelNumber = 1
ChannelType = EComfyChannel::Depth

// RGBA Channel  
ServerURL = "http://192.168.1.247:8188"
ChannelNumber = 2
ChannelType = EComfyChannel::RGBA
```

### **Polling Settings**

- **Polling Interval**: 1 second (configurable)
- **Image Endpoint**: `/view`
- **Auto Reconnect**: Enabled

## 📋 **ComfyUI Workflow Requirements**

Your ComfyUI workflow should:

1. **Generate depth maps** and save them to channel 1
2. **Generate RGBA maps** and save them to channel 2
3. **Use the `/view` endpoint** to serve images
4. **Include channel parameter** in the URL

### **Example ComfyUI API Usage**

```python
# Save depth map to channel 1
import requests
depth_image = generate_depth_map()
requests.post('http://192.168.1.247:8188/view', 
              files={'image': depth_image}, 
              params={'channel': 1})

# Save RGBA map to channel 2  
rgba_image = generate_rgba_map()
requests.post('http://192.168.1.247:8188/view',
              files={'image': rgba_image},
              params={'channel': 2})
```

## ✅ **Ready to Use**

The plugin is now configured for your server setup! Just:

1. **Start ComfyUI** on `192.168.1.247:8188`
2. **Place ComfyStreamActor** in your level
3. **Set your M_Displacement material**
4. **Play the level** - it will automatically connect and start receiving images!

The plugin will poll your ComfyUI server every second for new images and automatically update your material with the received depth and RGBA maps.
