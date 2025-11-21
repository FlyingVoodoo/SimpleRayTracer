#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
    Vec3 center;
    double radius;

    Sphere();
    Sphere(const Vec3& center, double radius);

    HitRecord intersect(const Ray& ray, double tMin, double tMax) const override;
};

#endif // SPHERE_H
