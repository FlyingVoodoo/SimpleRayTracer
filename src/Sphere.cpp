#include "Sphere.h"
#include <cmath>

Sphere::Sphere() : center(Vec3(0, 0, 0)), radius(1.0) {}

Sphere::Sphere(const Vec3& center, double radius) 
    : center(center), radius(radius) {}

HitRecord Sphere::intersect(const Ray& ray, double tMin, double tMax) const {
    HitRecord record;
    
    Vec3 oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    
    // Check for degenerate ray (zero or near-zero length direction)
    if (std::abs(a) < 1e-8) {
        return record;
    }
    
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        return record;
    }
    
    double sqrtDiscriminant = std::sqrt(discriminant);
    double t = (-b - sqrtDiscriminant) / (2.0 * a);
    
    if (t < tMin || t > tMax) {
        t = (-b + sqrtDiscriminant) / (2.0 * a);
        if (t < tMin || t > tMax) {
            return record;
        }
    }
    
    record.hit = true;
    record.t = t;
    record.point = ray.pointAt(t);
    record.normal = (record.point - center).normalized();
    
    return record;
}
