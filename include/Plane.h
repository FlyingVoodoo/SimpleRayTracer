#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
public:
    Vec3 point;
    Vec3 normal;

    Plane();
    Plane(const Vec3& point, const Vec3& normal);

    HitRecord intersect(const Ray& ray, double tMin, double tMax) const override;
};

#endif // PLANE_H
