#include "Scene.h"
#include <limits>

Scene::Scene() {}

void Scene::addObject(std::shared_ptr<Shape> object) {
    objects.push_back(object);
}

void Scene::addLight(const Light& light) {
    lights.push_back(light);
}

HitRecord Scene::intersect(const Ray& ray, double tMin, double tMax) const {
    HitRecord closestHit;
    double closestT = tMax;

    for (const auto& object : objects) {
        HitRecord hit = object->intersect(ray, tMin, closestT);
        if (hit.hit && hit.t < closestT) {
            closestT = hit.t;
            closestHit = hit;
        }
    }

    return closestHit;
}

bool Scene::isInShadow(const Vec3& point, const Vec3& lightPos) const {
    Vec3 toLight = lightPos - point;
    double distance = toLight.length();
    Vec3 direction = toLight.normalized();
    
    Ray shadowRay(point + direction * 0.001, direction);
    
    HitRecord hit = intersect(shadowRay, 0.001, distance - 0.001);
    return hit.hit;
}
