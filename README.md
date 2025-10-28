# ComfyStream Plugin

A Unreal Engine plugin for receiving ComfyUI websocket streams and creating dynamic materials with depth and RGBA maps.

## Features

- **WebSocket Connection**: Connect to ComfyUI server via WebSocket
- **Multiple Channels**: Support for depth maps, RGBA maps, and custom channels
- **Dynamic Materials**: Automatically update material parameters when new textures are received
- **PNG Decoding**: Built-in PNG decoder for texture conversion
- **HTTP Client**: Additional HTTP client for ComfyUI API operations
- **Auto-reconnection**: Automatic reconnection on connection loss
- **Blueprint Support**: Full Blueprint integration with events and functions

## Installation

1. Copy the `ComfyStream` folder to your project's `Plugins` directory
2. Regenerate project files
3. Compile your project

## Usage

### Basic Setup

1. Add a `ComfyStreamActor` to your level
2. Set the `Base Material` to your M_Displacement material
3. Configure the channel settings:
   - **Depth Channel**: Channel 1 for depth maps
   - **RGBA Channel**: Channel 2 for RGBA maps
4. Set the ComfyUI server URL (default: `ws://192.168.1.65:8001`)

### Blueprint Events

The plugin provides several Blueprint events:

- `OnTextureReceived`: Called when a new texture is received
- `OnConnectionStatusChanged`: Called when connection status changes
- `OnError`: Called when an error occurs

### C++ Usage

```cpp
// Create a ComfyStream component
UComfyStreamComponent* ComfyComponent = CreateDefaultSubobject<UComfyStreamComponent>(TEXT("ComfyStream"));

// Configure the component
ComfyComponent->StreamConfig.ChannelNumber = 1;
ComfyComponent->StreamConfig.ChannelType = EComfyChannel::Depth;
ComfyComponent->BaseMaterial = YourMaterial;

// Connect to ComfyUI
ComfyComponent->Connect();
```

### Material Setup

Your material should have the following parameters:
- `Depth_Map`: Texture parameter for depth maps
- `RGB_Map`: Texture parameter for RGBA maps

## Configuration

### Stream Configuration

```cpp
FComfyStreamConfig Config;
Config.ServerURL = TEXT("ws://192.168.1.65:8001");
Config.ChannelNumber = 1;
Config.ChannelType = EComfyChannel::Depth;
Config.PingInterval = 20.0f;
Config.bAutoReconnect = true;
Config.ReconnectDelay = 5.0f;
```

### Channel Types

- `EComfyChannel::Depth`: For depth maps
- `EComfyChannel::RGBA`: For RGBA maps
- `EComfyChannel::Custom`: For custom channels

## API Reference

### ComfyStreamComponent

Main component for handling ComfyUI streams.

**Functions:**
- `Connect()`: Connect to ComfyUI server
- `Disconnect()`: Disconnect from server
- `IsConnected()`: Check connection status
- `SetChannelNumber(int32)`: Set channel number
- `SetServerURL(FString)`: Set server URL

**Events:**
- `OnTextureReceived`: Texture received event
- `OnConnectionStatusChanged`: Connection status changed event
- `OnError`: Error event

### ComfyWsClient

WebSocket client for ComfyUI communication.

**Functions:**
- `Connect(FString)`: Connect to WebSocket URL
- `Disconnect()`: Disconnect
- `SendPing()`: Send ping message
- `SendMessage(FString)`: Send custom message

### ComfyPngDecoder

PNG decoder for texture conversion.

**Functions:**
- `DecodePNGToTexture(TArray<uint8>)`: Decode PNG to texture
- `IsValidPNGData(TArray<uint8>)`: Validate PNG data

### ComfyHttpClient

HTTP client for ComfyUI API operations.

**Functions:**
- `SendPrompt(FString)`: Send prompt to ComfyUI
- `GetQueueStatus()`: Get queue status
- `GetHistory(FString)`: Get execution history
- `InterruptQueue()`: Interrupt current queue

## Troubleshooting

### Common Issues

1. **Connection Failed**: Check if ComfyUI server is running and accessible
2. **Texture Not Updating**: Verify material parameter names match the component settings
3. **Compilation Errors**: Ensure WebSockets plugin is enabled

### Logs

The plugin provides detailed logging:
- `[ComfyWS]`: WebSocket related logs
- `[ComfyPNG]`: PNG decoding logs
- `[ComfyHTTP]`: HTTP client logs

## Dependencies

- WebSockets plugin
- ImageWrapper module
- HTTP module
- Json module

## License

This plugin is provided as-is for educational and development purposes.
