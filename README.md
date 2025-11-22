# SimpleRayTracer

🎨 Simple CPU ray tracer in C++17: ray tracing, multithreaded rendering, diffuse lighting and antialiasing. From ray to pixel in 10 seconds.

**English** | [Русский](README.ru.md)

## 🎨 Demo

![Rendered Scene](output.png)

*Two spheres with diffuse lighting and gradient sky*

## ✨ Features

- ✅ **Ray tracing** with sphere intersection
- ✅ **Multithreaded rendering** (uses all CPU cores)
- ✅ **Antialiasing** via random sampling (configurable samples per pixel)
- ✅ **Diffuse lighting** with ambient + diffuse components
- ✅ **Gradient sky** (white → blue)
- ✅ **Gamma correction** on output
- ✅ **Template classes** Vec3/Ray for type flexibility

## 🛠 Technologies

- **C++17** (templates, std::thread, smart pointers)
- **CMake** (cross-platform build)
- **PPM format** (simple text image format)
- **Python + Pillow** (PNG conversion)

## 📦 Project Structure

```
SimpleRayTracer/
├── include/          # Header files
│   ├── Vec3.hpp      # 3D vector (template)
│   ├── Ray.hpp       # Ray (origin + direction)
│   ├── Hittable.hpp  # Abstract interface for objects
│   ├── Sphere.hpp    # Sphere (inherits Hittable)
│   ├── World.hpp     # Scene container
│   ├── Camera.hpp    # Camera with viewport
│   ├── Render.hpp    # Ray tracing function
│   └── utils.hpp     # Utilities (writeColor, gamma)
├── inline/           # Template implementations
│   ├── Vec3.ipp      # Operators, dot, cross, normalize
│   └── Ray.ipp       # pointAtParameter
├── src/              # Implementations
│   ├── main.cpp      # Entry point, multithreading
│   ├── Sphere.cpp    # Ray-sphere intersection algorithm
│   ├── World.cpp     # Find nearest intersection
│   └── Render.cpp    # Pixel color calculation
└── convert.py        # PPM → PNG converter
```

## 🚀 Build and Run

### Requirements

- **C++17** compiler (MSVC, GCC, Clang)
- **CMake** 3.15+
- **Python 3** + Pillow (for PNG conversion)

### Windows (MSVC)

```powershell
# Install Python dependencies
pip install Pillow numpy

# Build
cmake -B build
cmake --build build --config Release

# Render
.\build\bin\Release\SimpleRayTracer.exe

# Convert to PNG
python convert.py
```

### Linux/macOS

```bash
# Install dependencies
pip3 install Pillow numpy

# Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Render
./build/bin/SimpleRayTracer

# Convert
python3 convert.py
```

## ⚙️ Configuration

In `src/main.cpp` you can change parameters:

```cpp
const int image_width = 800;           // Image width
const int image_height = 450;          // Image height
const int samples_per_pixel = 100;     // Samples per pixel (AA)
```

### Scene

Adding objects in `main()`:

```cpp
World world;
world.add(std::make_shared<Sphere>(Vec3d(0.0, 0.0, -1.0), 0.5));    // Sphere in center
world.add(std::make_shared<Sphere>(Vec3d(0.0, -100.5, -1.0), 100.0)); // Ground
```

## 📐 Math

### Ray-Sphere Intersection

Solved using quadratic equation:

```
t² * (d·d) + 2t * d·(o-c) + (o-c)·(o-c) - r² = 0
```

where:
- `d` - ray direction
- `o` - ray origin
- `c` - sphere center
- `r` - sphere radius

### Diffuse Lighting

```cpp
Vec3d ambient = Vec3d(0.3, 0.3, 0.3);           // Base lighting
Vec3d diffuse = 0.7 * (normal + Vec3d(1, 1, 1)) * 0.5;  // Diffuse
return ambient + diffuse;
```

## 🎯 Performance

**Test scene** (800x450, 100 samples/pixel):
- **Ryzen 5600X** (12 threads): ~5-10 seconds
- **Core i5-9400F** (6 threads): ~15-20 seconds

**Optimizations:**
- Multithreaded rendering (automatically uses all cores)
- `lengthSquared()` instead of `length()` where possible
- Inline functions for vector operations

## 🔮 Roadmap

- [ ] **Materials** (metal, dielectrics, diffuse)
- [ ] **Reflections and refractions** (recursive ray tracing)
- [ ] **Other primitives** (planes, triangles, meshes)
- [ ] **BVH acceleration** for large scenes
- [ ] **Textures and normal mapping**
- [ ] **Depth of field and motion blur**

## 📚 Resources

Project based on concepts from:
- [Ray Tracing in One Weekend](https://raytracing.github.io/) - Peter Shirley
- [Physically Based Rendering](https://www.pbr-book.org/) - Matt Pharr & Greg Humphreys

## 📝 License

MIT License - do whatever you want

## 🤝 Contributing

Pull requests welcome! For major changes, please open an issue first.

---

**Made with ☕ and ray tracing magic**