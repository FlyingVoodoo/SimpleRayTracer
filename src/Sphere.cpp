#include <cmath>
#include "Sphere.hpp"

bool Sphere::hit(const Rayd& r, double t_min, double t_max, hit_record& rec) const {
    Vec3d oc = r.origin - center;

    double a = r.direction.lengthSquared();

    double half_b = oc.dot(r.direction);

    double c = oc.lengthSquared() - radius * radius;

    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0) {
        return false;
    }

    double sqrt_d = std::sqrt(discriminant);

    double root = (-half_b - sqrt_d) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrt_d) / a;
        if (root < t_min || root > t_max) {
            return false;
        }
    }

    rec.t = root;
    rec.point = r.pointAtParameter(rec.t);
    Vec3d outward_normal = (rec.point - center) / radius;
    rec.setFaceNormal(r, outward_normal);
    rec.material = material;
    return true;
}