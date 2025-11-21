#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "Vec3.h"

struct HitRecord {
    double t;
    Vec3 point;
    Vec3 normal;
    bool hit;

    HitRecord() : t(0), hit(false) {}
};

class Shape {
public:
    virtual ~Shape() {}
    virtual HitRecord intersect(const Ray& ray, double tMin, double tMax) const = 0;
};

#endif // SHAPE_H
