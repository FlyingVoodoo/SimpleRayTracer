#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include "Vec3.h"
#include "Ray.h"
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Light.h"
#include "Scene.h"

double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

Vec3 computeColor(const Ray& ray, const Scene& scene, int depth = 0) {
    if (depth > 5) {
        return Vec3(0, 0, 0);
    }

    HitRecord hit = scene.intersect(ray, 0.001, 1000.0);
    
    if (!hit.hit) {
        // Background gradient (sky)
        Vec3 unitDirection = ray.direction.normalized();
        double t = 0.5 * (unitDirection.y + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }

    // Compute lighting
    Vec3 color(0, 0, 0);
    
    for (const auto& light : scene.lights) {
        Vec3 toLight = (light.position - hit.point).normalized();
        
        // Check if point is in shadow
        if (scene.isInShadow(hit.point, light.position)) {
            continue;
        }
        
        // Simple diffuse lighting
        double diffuse = std::max(0.0, hit.normal.dot(toLight));
        color = color + Vec3(1, 1, 1) * diffuse * light.intensity;
    }
    
    // Add ambient light
    Vec3 ambient = Vec3(0.2, 0.2, 0.2);
    color = color + ambient;
    
    // Clamp color values
    color.x = clamp(color.x, 0.0, 1.0);
    color.y = clamp(color.y, 0.0, 1.0);
    color.z = clamp(color.z, 0.0, 1.0);
    
    return color;
}

int main() {
    // Image settings
    const int imageWidth = 800;
    const int imageHeight = 600;
    const double aspectRatio = double(imageWidth) / double(imageHeight);

    // Camera setup
    Vec3 lookFrom(0, 2, 5);
    Vec3 lookAt(0, 0, 0);
    Vec3 vup(0, 1, 0);
    double vfov = 60.0;
    Camera camera(lookFrom, lookAt, vup, vfov, aspectRatio);

    // Scene setup
    Scene scene;
    
    // Add a sphere
    scene.addObject(std::make_shared<Sphere>(Vec3(0, 1, 0), 1.0));
    
    // Add ground plane
    scene.addObject(std::make_shared<Plane>(Vec3(0, 0, 0), Vec3(0, 1, 0)));
    
    // Add light
    scene.addLight(Light(Vec3(5, 5, 5), 1.0));

    // Render to PPM file
    std::ofstream outFile("output.ppm");
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output.ppm file!" << std::endl;
        return 1;
    }
    outFile << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

    std::cout << "Rendering..." << std::endl;

    for (int j = imageHeight - 1; j >= 0; --j) {
        std::cout << "\rScanlines remaining: " << j << " " << std::flush;
        
        for (int i = 0; i < imageWidth; ++i) {
            double u = double(i) / (imageWidth - 1);
            double v = double(j) / (imageHeight - 1);
            
            Ray ray = camera.getRay(u, v);
            Vec3 color = computeColor(ray, scene);
            
            // Convert to 0-255 range
            int ir = int(255.99 * color.x);
            int ig = int(255.99 * color.y);
            int ib = int(255.99 * color.z);
            
            outFile << ir << " " << ig << " " << ib << "\n";
        }
    }

    outFile.close();
    std::cout << "\nDone! Output written to output.ppm" << std::endl;

    return 0;
}
