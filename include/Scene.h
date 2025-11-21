#ifndef SCENE_H
#define SCENE_H

#include "Shape.h"
#include "Light.h"
#include <vector>
#include <memory>

class Scene {
public:
    std::vector<std::shared_ptr<Shape>> objects;
    std::vector<Light> lights;

    Scene();

    void addObject(std::shared_ptr<Shape> object);
    void addLight(const Light& light);
    
    HitRecord intersect(const Ray& ray, double tMin, double tMax) const;
    bool isInShadow(const Vec3& point, const Vec3& lightPos) const;
};

#endif // SCENE_H
