# Migration from AComfyManager to ComfyStream Plugin

This guide shows how to migrate from your existing `AComfyManager` to the new `ComfyStream` plugin.

## Before (AComfyManager)

```cpp
// AComfyManager.h
class AComfyManager : public AActor
{
    UPROPERTY()
    UComfyWebSocketReceiver* Channel1Receiver;

    UPROPERTY()
    UComfyWebSocketReceiver* Channel2Receiver;

    UPROPERTY(EditAnywhere, Category="ComfyUI")
    UMaterialInterface* BaseMaterial;

    UPROPERTY()
    UMaterialInstanceDynamic* DynamicMaterial;
};

// AComfyManager.cpp
void AComfyManager::BeginPlay()
{
    // Create dynamic material
    if (BaseMaterial)
    {
        DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
        ScreenMesh->SetMaterial(0, DynamicMaterial);
    }

    // Channel 1 (Depth/Mask)
    Channel1Receiver = NewObject<UComfyWebSocketReceiver>(this);
    Channel1Receiver->OnTextureReceived.AddDynamic(this, &AComfyManager::OnChannel1Frame);
    Channel1Receiver->Connect(TEXT("ws://192.168.1.65:8001/?channel=1"));

    // Channel 2 (RGB)
    Channel2Receiver = NewObject<UComfyWebSocketReceiver>(this);
    Channel2Receiver->OnTextureReceived.AddDynamic(this, &AComfyManager::OnChannel2Frame);
    Channel2Receiver->Connect(TEXT("ws://192.168.1.65:8001/?channel=2"));
}
```

## After (ComfyStream Plugin)

### Option 1: Use ComfyStreamActor (Recommended)

```cpp
// Simply replace AComfyManager with AComfyStreamActor
// The actor handles everything automatically

// In your level:
// 1. Add ComfyStreamActor
// 2. Set Base Material to your M_Displacement material
// 3. Configure channel settings in the details panel
// 4. The actor will automatically connect and update materials
```

### Option 2: Use ComfyStreamComponent

```cpp
// YourActor.h
class YOURGAME_API AYourActor : public AActor
{
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ComfyStream")
    UComfyStreamComponent* ComfyStreamComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ComfyStream")
    UStaticMeshComponent* ScreenMesh;
};

// YourActor.cpp
void AYourActor::BeginPlay()
{
    Super::BeginPlay();

    // Create ComfyStream component
    ComfyStreamComponent = CreateDefaultSubobject<UComfyStreamComponent>(TEXT("ComfyStreamComponent"));
    
    // Configure for depth channel
    ComfyStreamComponent->StreamConfig.ChannelNumber = 1;
    ComfyStreamComponent->StreamConfig.ChannelType = EComfyChannel::Depth;
    ComfyStreamComponent->BaseMaterial = YourMaterial;
    
    // Bind events
    ComfyStreamComponent->OnTextureReceived.AddDynamic(this, &AYourActor::OnTextureReceived);
    
    // Connect
    ComfyStreamComponent->Connect();
}
```

### Option 3: Multiple Channels

```cpp
// For handling both depth and RGBA channels
class YOURGAME_API AYourActor : public AActor
{
    UPROPERTY()
    UComfyStreamComponent* DepthChannel;

    UPROPERTY()
    UComfyStreamComponent* RGBAChannel;

    UPROPERTY()
    UMaterialInstanceDynamic* DynamicMaterial;
};

void AYourActor::BeginPlay()
{
    Super::BeginPlay();

    // Create dynamic material
    DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
    ScreenMesh->SetMaterial(0, DynamicMaterial);

    // Depth channel
    DepthChannel = NewObject<UComfyStreamComponent>(this);
    DepthChannel->StreamConfig.ChannelNumber = 1;
    DepthChannel->StreamConfig.ChannelType = EComfyChannel::Depth;
    DepthChannel->OnTextureReceived.AddDynamic(this, &AYourActor::OnDepthTextureReceived);
    DepthChannel->Connect();

    // RGBA channel
    RGBAChannel = NewObject<UComfyStreamComponent>(this);
    RGBAChannel->StreamConfig.ChannelNumber = 2;
    RGBAChannel->StreamConfig.ChannelType = EComfyChannel::RGBA;
    RGBAChannel->OnTextureReceived.AddDynamic(this, &AYourActor::OnRGBATextureReceived);
    RGBAChannel->Connect();
}

void AYourActor::OnDepthTextureReceived(UTexture2D* Texture)
{
    if (DynamicMaterial && Texture)
    {
        DynamicMaterial->SetTextureParameterValue(TEXT("Depth_Map"), Texture);
    }
}

void AYourActor::OnRGBATextureReceived(UTexture2D* Texture)
{
    if (DynamicMaterial && Texture)
    {
        DynamicMaterial->SetTextureParameterValue(TEXT("RGB_Map"), Texture);
    }
}
```

## Key Differences

1. **Simplified Setup**: The plugin handles WebSocket creation and PNG decoding automatically
2. **Better Error Handling**: Built-in error handling and reconnection logic
3. **Blueprint Support**: Full Blueprint integration with events and functions
4. **Modular Design**: Separate components for different functionality
5. **Configuration**: Easy configuration through Blueprint or C++

## Benefits

- **Cleaner Code**: Less boilerplate code needed
- **Better Maintainability**: Modular design makes it easier to maintain
- **More Features**: Additional functionality like HTTP client and better error handling
- **Blueprint Friendly**: Easy to use in Blueprint without C++ knowledge
- **Extensible**: Easy to add new features or modify existing ones

## Migration Steps

1. **Remove Old Code**: Delete `AComfyManager`, `ComfyWebSocketReceiver`, and `Listening` classes
2. **Add Plugin**: Ensure the ComfyStream plugin is enabled in your project
3. **Replace Actor**: Replace `AComfyManager` with `AComfyStreamActor` or use `UComfyStreamComponent`
4. **Configure**: Set up the material and channel configurations
5. **Test**: Test the connection and texture updates

The plugin provides the same functionality as your original implementation but with better organization, error handling, and Blueprint support.
