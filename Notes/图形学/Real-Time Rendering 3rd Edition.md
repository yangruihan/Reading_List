# Real-Time Rendering 3rd Edition

## Chapter 2 The Graphics Rendering Pipeline 

The main function of the pipeline is to generate, or render, a two-dimensional image, given a virtual camera, three-dimensional objects, light sources, shading equations, textures, and more.

### Architecture

```
---------------    ------------    --------------
| Application | -> | Geometry | -> | Rasterizer |
---------------    ------------    --------------
```

### Application Stage

The developer has full control over what happens in the application stage, since it executes on the CPU.

At the end of the application stage, the geometry to be rendered is fed to the geometry stage. These are the rendering primitives, i.e., points, lines, and triangles, that might eventually end up on the screen (or whatever output device is being used). This is the most important task of the application stage.

### Geometry Stage

The geometry stage is responsible for the majority of the per-polygon and per-vertex operations.

#### Sub Stages

```
Model&View Transform -> Vertex Shading -> Projection -> Clipping -> Screen Mapping
```

### Rasterizer Stage

Given the transformed and projected vertices with their associated shading data (all from the geometry stage), the goal of the rasterizer stage is to compute and set colors for the pixels covered by the object.

#### Sub Stages

```
Triangle Setup -> Triangle Traversal -> Pixel Shading -> Merging
```
