#pragma once

#include "Vec3.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable {
public:
    Vec3d center;
    double radius;

    Sphere(const Vec3d& center, double radius)
        : center(center), radius(radius) {}

    virtual bool hit(const Rayd& r, double t_min, double t_max, hit_record& rec) const override;

    virtual ~Sphere() = default;
};