#include "Plane.h"
#include <cmath>

Plane::Plane() : point(Vec3(0, 0, 0)), normal(Vec3(0, 1, 0)) {}

Plane::Plane(const Vec3& point, const Vec3& normal) 
    : point(point), normal(normal.normalized()) {}

HitRecord Plane::intersect(const Ray& ray, double tMin, double tMax) const {
    HitRecord record;
    
    double denom = normal.dot(ray.direction);
    
    // Check if ray is parallel to plane
    if (std::abs(denom) < 1e-6) {
        return record;
    }
    
    double t = (point - ray.origin).dot(normal) / denom;
    
    if (t < tMin || t > tMax) {
        return record;
    }
    
    record.hit = true;
    record.t = t;
    record.point = ray.pointAt(t);
    record.normal = normal;
    
    return record;
}
