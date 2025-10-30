## ComfyStream Plugin

A complete **real-time ComfyUI to Unreal Engine 5.6 streaming pipeline** plus **runtime Gaussian Splat reconstruction** using World Explorer.

Developed by Alexia Hartogensis as a part of the School of Visual Art's Graduate Computer Art's Thesis 
My goal for this project is to build a pipeline that uses Computer Vision and AI to make scene reconstruction accessible, not just for researchers with advanced technical skills, but also for artists who want to create immersive, interactive artworks.
The workflow I’ve developed can take footage, real-time or recorded, and automatically convert it into a 3D environment, removing the hassle of manually rebuilding scenes in 3D software.
In other words, I’m using AI to automate the reconstruction process, creating a bridge between linear media and interactive worlds.

---

## Features

**Live streamed RGB/Depth/Mask** | WebSockets from ComfyUI  
**Material auto-update** | Textures applied live to your Unreal material  
**Lerp smoothing** | Frame-to-frame blending  
**Procedural Splat Import** | Converts Gaussian Splats to Mesh at runtime  
**Video → PLY → OBJ** | Full pipeline inside Unreal (Docker optional)  
**Blueprint friendly** | No C++ required  

### ComfyStream
- Real-time WebSocket stream from ComfyUI
- PNG decoder built-in  
- Seamless texture lerp smoothing  
- Auto-reconnect  
- Blueprint events  

### World Explorer Integration
- Accepts video input or existing `.ply`
- Runs reconstruction, converts to OBJ
- Spawns procedural mesh at runtime
- Handles vertex color translucency for correct depth layering

---

## Installation

1. Copy `ComfyStream/` into your project's `Plugins/` folder  
2. Right-click `.uproject` → **Generate Visual Studio files**  
3. Build project  
4. Install **World Explorer assets** (if separate)  
5. Run `build_docker.bat` (Docker Container for Gaussian splat pipeline)

---

## Usage

### Comfy Stream Setup

1. Drag **`ComfyStreamActor`** into your level  
2. Create an Unreal material (e.g. `M_Displacement`):  
   `RGB_Map` | Base Color  
   `Depth_Map` | Multiply by a displacement value → World Position Offset  
   `Mask_Map` | Opacity (Masked)  
3. Assign that material to the actor's base material   
4. Set WebSocket URL (default: `ws://localhost:8188`)  
5. Play — textures stream instantly
6. Corresponding ComfyUI workflow is object_sender.json

### Gaussian Splat (World Explorer)
1. Add the GameInstance subsystem (**auto added**)  
2. Call Blueprint: Check And Import Splat (Optional Video Path)
3. Either:
   - Pass a video path → full pipeline runs, or  
   - Drop a `point_cloud.ply` into  
      ```
      Plugins/ComfyStream/WorldExplorerOutputs/
      ```
4. Mesh auto-spawns when completed

---

## Blueprint Signals
`OnTextureReceived` | Each time a frame arrives  
`OnConnectionStatusChanged` | Connected / Disconnected  
`OnError` | Any connection/decoding failure  

---

## C++ Quick Start

```cpp
UComfyStreamComponent* Comfy = CreateDefaultSubobject<UComfyStreamComponent>("ComfyStream");
Comfy->StreamConfig.ServerURL = TEXT("ws://localhost:8188");
Comfy->StreamConfig.bEnableLerpSmoothing = true;
Comfy->Connect();
```

## Data Flow Overview 
Camera → ComfyUI → PNG stream → Unreal Material  
Video → Docker/Colmap → PLY → OBJ → Unreal Procedural Mesh

##Trouble Shooting 
| Issue           | Fix                                         |
| --------------- | ------------------------------------------- |
| No textures?    | Confirm Comfy WebSocket & channel running   |
| Textures black? | Check correct parameter names in material   |
| Mesh invisible? | Make splat material **Translucent + Unlit** |
| No OBJ import?  | Verify Docker installed & batch executed    |
