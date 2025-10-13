# ComfyStream Plugin - WebViewer Integration

This guide shows how to use the ComfyStream plugin with ComfyUI webviewer nodes for real-time depth and RGBA map streaming.

## ComfyUI WebViewer Setup

### 1. Install WebViewer Nodes

Make sure you have the ComfyUI webviewer nodes installed in your ComfyUI setup. These nodes provide WebSocket streaming capabilities.

### 2. Configure WebViewer Nodes

In your ComfyUI workflow, use these nodes:

#### VrchWebSocketServerNode
- **Server**: `192.168.1.65` (or your server IP)
- **Port**: `8001` (WebSocket port)
- **Debug**: `True` (for troubleshooting)

#### VrchImageWebSocketWebViewerNode
- **Images**: Your generated depth/RGBA images
- **Channel**: `1` for depth maps, `2` for RGBA maps
- **Server**: `192.168.1.65:8001`
- **Format**: `PNG` (recommended for quality)
- **Number of Images**: `1`
- **Image Display Duration**: `1000` (1 second)
- **Fade Anim Duration**: `200` (0.2 seconds)
- **Blend Mode**: `none`
- **Loop Playback**: `True`
- **Update On End**: `False`
- **Background Colour Hex**: `#222222`
- **Window Width**: `1280`
- **Window Height**: `960`
- **Debug**: `True`

## Unreal Engine Setup

### 1. Add ComfyStreamActor to Level

1. Place a `ComfyStreamActor` in your level
2. Set the `Base Material` to your M_Displacement material
3. Configure the channel settings:

#### Depth Channel Configuration
- **Server URL**: `http://192.168.1.253:8188`
- **Channel Number**: `1`
- **Channel Type**: `Depth`
- **Auto Reconnect**: `True`
- **Ping Interval**: `20.0`

#### RGBA Channel Configuration
- **Server URL**: `http://192.168.1.253:8188`
- **Channel Number**: `2`
- **Channel Type**: `RGBA`
- **Auto Reconnect**: `True`
- **Ping Interval**: `20.0`

### 2. Material Setup

Your M_Displacement material should have these parameters:
- `Depth_Map`: Texture parameter for depth maps
- `RGB_Map`: Texture parameter for RGBA maps

### 3. Blueprint Events

The ComfyStreamActor provides these Blueprint events:

#### OnTextureReceived
- **Parameters**: `Texture` (UTexture2D*), `ChannelType` (EComfyChannel)
- **Purpose**: Called when a new texture is received

#### OnConnectionStatusChanged
- **Parameters**: `bConnected` (bool), `ChannelType` (EComfyChannel)
- **Purpose**: Called when connection status changes

#### OnError
- **Parameters**: `ErrorMessage` (FString), `ChannelType` (EComfyChannel)
- **Purpose**: Called when an error occurs

## C++ Usage

### Basic Setup

```cpp
// In your actor's BeginPlay()
void AYourActor::BeginPlay()
{
    Super::BeginPlay();

    // Create ComfyStream component
    ComfyStreamComponent = CreateDefaultSubobject<UComfyStreamComponent>(TEXT("ComfyStreamComponent"));
    
    // Configure for depth channel
    ComfyStreamComponent->StreamConfig.ServerURL = TEXT("http://192.168.1.253:8188");
    ComfyStreamComponent->StreamConfig.ChannelNumber = 1;
    ComfyStreamComponent->StreamConfig.ChannelType = EComfyChannel::Depth;
    ComfyStreamComponent->BaseMaterial = YourMaterial;
    
    // Bind events
    ComfyStreamComponent->OnTextureReceived.AddDynamic(this, &AYourActor::OnTextureReceived);
    ComfyStreamComponent->OnConnectionStatusChanged.AddDynamic(this, &AYourActor::OnConnectionStatusChanged);
    ComfyStreamComponent->OnError.AddDynamic(this, &AYourActor::OnError);
    
    // Connect
    ComfyStreamComponent->Connect();
}

void AYourActor::OnTextureReceived(UTexture2D* Texture)
{
    if (DynamicMaterial && Texture)
    {
        DynamicMaterial->SetTextureParameterValue(TEXT("Depth_Map"), Texture);
    }
}
```

### Multiple Channels

```cpp
// For both depth and RGBA channels
void AYourActor::SetupComfyStreams()
{
    // Depth channel
    DepthChannel = NewObject<UComfyStreamComponent>(this);
    DepthChannel->StreamConfig.ServerURL = TEXT("http://192.168.1.253:8188");
    DepthChannel->StreamConfig.ChannelNumber = 1;
    DepthChannel->StreamConfig.ChannelType = EComfyChannel::Depth;
    DepthChannel->OnTextureReceived.AddDynamic(this, &AYourActor::OnDepthTextureReceived);
    DepthChannel->Connect();

    // RGBA channel
    RGBAChannel = NewObject<UComfyStreamComponent>(this);
    RGBAChannel->StreamConfig.ServerURL = TEXT("http://192.168.1.253:8188");
    RGBAChannel->StreamConfig.ChannelNumber = 2;
    RGBAChannel->StreamConfig.ChannelType = EComfyChannel::RGBA;
    RGBAChannel->OnTextureReceived.AddDynamic(this, &AYourActor::OnRGBATextureReceived);
    RGBAChannel->Connect();
}
```

## WebSocket Protocol Details

The plugin follows the ComfyUI WebSocket protocol:

### Connection URLs
- **Image Channel**: `ws://192.168.1.253:8001/image?channel=1`
- **JSON Channel**: `ws://192.168.1.253:8001/json?channel=1`
- **Latent Channel**: `ws://192.168.1.253:8001/latent?channel=1`

### Message Types
- `status`: Overall system status updates
- `execution_start`: When a prompt execution begins
- `execution_cached`: When cached results are used
- `executing`: Updates during node execution
- `progress`: Progress updates for long-running operations
- `executed`: When a node completes execution
- `execution_error`: When an error occurs
- `execution_interrupted`: When execution is interrupted

### Image Format
The plugin supports both:
1. **WebViewer Format**: Binary data with header `struct.pack(">II", 1, 2)` + PNG data
2. **Regular PNG Format**: Direct PNG data

## Troubleshooting

### Common Issues

1. **Connection Failed**
   - Check if ComfyUI server is running on port 8000
   - Check if WebSocket server is running on port 8001
   - Verify IP address and ports

2. **No Images Received**
   - Ensure webviewer nodes are properly configured
   - Check channel numbers match between ComfyUI and Unreal
   - Verify image format settings

3. **Texture Not Updating**
   - Check material parameter names
   - Verify dynamic material is created
   - Check Blueprint event bindings

### Debug Logs

Enable debug logging to see detailed information:
- `[ComfyWS]`: WebSocket connection logs
- `[ComfyPNG]`: PNG decoding logs
- `[ComfyHTTP]`: HTTP client logs

### Testing Connection

You can test the WebSocket connection using a simple tool like `wscat`:

```bash
# Install wscat
npm install -g wscat

# Connect to image channel
wscat -c "ws://192.168.1.253:8001/image?channel=1"

# Connect to JSON channel
wscat -c "ws://192.168.1.253:8001/json?channel=1"
```

## Performance Tips

1. **Image Resolution**: Use appropriate resolution (512x512 as mentioned)
2. **Update Frequency**: Adjust `Image Display Duration` in webviewer nodes
3. **Compression**: Use PNG format for better quality
4. **Network**: Ensure stable network connection between ComfyUI and Unreal

## Advanced Usage

### Custom Message Handling

```cpp
// Bind to WebSocket message events
WebSocketClient->OnWebSocketMessage.AddDynamic(this, &AYourActor::OnWebSocketMessage);

void AYourActor::OnWebSocketMessage(const FComfyWebSocketMessage& Message)
{
    switch (Message.MessageType)
    {
        case EComfyMessageType::ExecutionStart:
            // Handle execution start
            break;
        case EComfyMessageType::Progress:
            // Handle progress updates
            break;
        case EComfyMessageType::Executed:
            // Handle execution completion
            break;
    }
}
```

### HTTP API Integration

```cpp
// Send prompts to ComfyUI
HttpClient->SendPrompt(WorkflowJSON);

// Get queue status
HttpClient->GetQueueStatus();

// Get execution history
HttpClient->GetHistory(PromptID);
```

This integration provides a complete solution for real-time ComfyUI to Unreal Engine streaming with proper WebSocket protocol support and webviewer node compatibility.
