#pragma once

#include "Vec3.hpp"
#include "Ray.hpp"

#include <memory>

struct hit_record {
    Vec3d point;
    Vec3d normal;
    double t;
    bool front_face;

    void setFaceNormal(const Rayd& r, const Vec3d& outward_normal) {
        front_face = r.direction.dot(outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable {
public:
    virtual bool hit(const Rayd& r, double t_min, double t_max, hit_record& rec) const = 0;
    virtual ~Hittable() = default;
};

using HittablePtr = std::shared_ptr<Hittable>;