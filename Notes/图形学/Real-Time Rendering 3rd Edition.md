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

## Chapter 3 The Graphics Processing Unit

### The Vertex Shader

The vertex shader provides a way to modify, create, or ignore values associated with each polygon’s vertex, such as its color, normal, texture coordinates, and position. Normally the vertex shader program transforms vertices from model space to homogeneous clip space; at a minimum, a vertex shader must always output this location.

The vertex shader can neither create nor destroy vertices, and results generated by one vertex cannot be passed on to another vertex.

The output of the vertex shader can be consumed in a number of different ways. The usual path is for each instance’s triangles to then be generated and rasterized, and the individual pixel fragments produced sent to the pixel shader program for continued processing.

### The Geometry Shader

The input to the geometry shader is a single object and its associated vertices. The object is typically a triangle in a mesh, a line segment, or simply a point.

The geometry shader processes this primitive and outputs zero or more primitives. Output is in the form of points, polylines, and triangle strips.

As important, no output at all can be generated by the geometry shader. In this way, a mesh can be selectively modiﬁed by editing vertices, adding new primitives, and removing others.

The geometry shader is guaranteed to output results from primitives in the same order as they are input.

### The Pixel Shader

This section of the pipeline is relatively ﬁxed in its processing steps, not programmable. Each triangle is traversed and the values at the vertices interpolated across the triangle’s area.

The pixel shader’s limitation is that it can inﬂuence only the fragment handed it.

Pixel shader programs typically set the fragment color for merging in the ﬁnal merging stage.

### The Merging Stage

The merging stage is where the depths and colors of the individual fragments (generated in the pixel shader) are combined with the frame buﬀer. This stage is where stencil-buﬀer and Z-buﬀer operations occur. Another operation that takes place in this stage is color blending, which is most commonly used for transparency and compositing operations

### Effects

These shaders are functions. An eﬀect ﬁle can consist of any number of functions and can include commonly used functions from other eﬀects ﬁles.

A pass typically consists of a vertex and pixel (and geometry) shader, 6 along with any state settings needed for the pass.

## Chapter 4 Transforms

A transform is an operation that takes entities such as points, vectors, or colors and converts them in some way.

A linear transform is one that preserves vector addition and scalar multiplication.

An aﬃne transform is one that performs a linear transform and then a translation.

All translation, rotation, scaling, reﬂection, and shearing matrices are aﬃne. 

The main characteristic of an aﬃne matrix is that it preserves the parallelism of lines, but not necessarily lengths and angles. An aﬃne transform may also be any sequence of concatenations of individual aﬃne transforms.

### Concatenation of Transforms

This composite matrix is **C** = **TRS**. Note the order here: The scaling matrix, S, should be applied to the vertices ﬁrst, and therefore appears to the right in the composition. This ordering implies that **TRSp** = (**T**(**R**(**Sp**))).

### The Rigid-Body Transform

Such a transform, consisting of concatenations of only translations and rotations, is called a rigid-body transform and has the characteristic of preserving lengths, angles, and handedness.

The inverse of **X** is computed as **X**<sup>−1</sup> = (**T**(**t**)**R**)<sup>−1</sup> = **R**<sup>−1</sup>**T**(**t**)<sup>−1</sup> = **R**<sup>*T*</sup>**T**(−**t**).
