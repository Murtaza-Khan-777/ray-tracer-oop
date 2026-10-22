# 3D Object-Oriented Ray Tracer

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![SFML](https://img.shields.io/badge/SFML-2.5+-green.svg)
![TGUI](https://img.shields.io/badge/TGUI-0.9-blue.svg)

A high-performance, interactive 3D ray tracing engine built from scratch in C++. This project demonstrates advanced Object-Oriented Programming (OOP) principles, real-time multi-threaded graphics rendering, and physically-based light transport.

**Course:** CS/CE 224/272 Object-Oriented Programming and Design Methodologies (Fall 2026)  
**Institution:** Habib University  

## 👥 Team Members
* **Muhammad Murtaza Khan** (mk11743) - GitHub: [@username1]
* **[Member 2 Full Name]** ([ID]) - GitHub: [@username2]
* **[Member 3 Full Name]** ([ID]) - GitHub: [@username3]
## 🛠️ How does a Ray Tracer work?
* **The ray tracer sets a 3d world with a camera placed at (0.00 , 0.00, 0.00) and a pixel map(viewport) placed at a distance of focal lenght from the camera, the direction vector from the camera to each pixel on the pixel provides as the primary ray for that pixel , the primary ray is then extrapolated from the pixel map to the 3d scene behind it the ray looks for the first "Hittable" it finds and collides with it , at collision the engine locates the light sources from the object known by the list of light sources mantained in the program, and draws a ray between them , the recursive nature of the call comes into the play and finds the final intensity of the light in the flow lightsource --> hittable --> pixel, the effect of surrounding objects on the color and brightness of the pixel in taken into account using Monte - Carlo Integration , where further rays are shot at point of collision in random directions and then averaged to find the final color of the select pixel , simulating the real world effect of other objects' emission on the color of a given object.
 
## 🌟 Key Features
* **Custom Math Engine:** Built-in `Vec3` and `Ray` classes with overloaded operators for hardware-agnostic linear algebra.
* **Polymorphic Geometry:** Abstract `Hittable` interface supporting mathematical intersections for `Sphere` and `Triangle` primitives.
* **Physically-Based Materials:** Implements the Strategy Pattern to handle different light scattering behaviors:
  * `Lambertian`: Matte diffuse color bleeding.
  * `Metal`: Specular reflection with adjustable fuzziness.
  * `Dielectric`: Glass refraction utilizing Snell's Law.
* **Real-Time GUI Rendering:** Uses **SFML** and **TGUI** in an MVC (Model-View-Controller) architecture to display the ray-traced image live as it renders on a background thread.
* **Direct Image Export:** Serializes the raw 24-bit floating-point HDR pixel buffer into standard standard LDR `.bmp` files on disk.

## 🏗️ Object-Oriented Architecture
This project strictly adheres to OOP methodologies and memory management:
* **Encapsulation & Const-Correctness:** All geometric and mathematical data is strictly private and accessed via const-safe getters.
* **Inheritance & Polymorphism:** Extensive use of virtual destructors and pure virtual functions (`= 0`) to decouple the rendering engine from specific shapes and materials.
* **Design Patterns:**
  * *Composite Pattern:* `HittableList` treats groups of objects identically to a single object.
  * *Strategy Pattern:* `Material` classes encapsulate specific scattering algorithms.
  * *MVC Pattern:* Decouples the mathematical `RayTracerEngine` (Model) from the SFML window (View).
* **Manual Memory Management:** Employs raw pointers (`*`), dynamic allocation (`new`/`delete`), and the Rule of Three for managing the `ImageBuffer` without memory leaks.

## 📁 Repository Structure
```text
ray-tracer-oop/
├── docs/                # draw.io class diagrams and proposal document
├── include/             # C++ Header files (.hpp)
│   ├── Math/            # Vec3.hpp, Ray.hpp
│   ├── Geometry/        # Hittable.hpp, Sphere.hpp, etc.
│   ├── Materials/       # Material.hpp, Lambertian.hpp, etc.
│   └── Core/            # RayTracerEngine.hpp, Scene.hpp
├── src/                 # C++ Source files (.cpp)
├── assets/              # TGUI fonts and UI themes
├── renders/             # Output folder for generated .bmp images
├── CMakeLists.txt       # Build configuration
└── README.md