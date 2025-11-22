#include "Render.hpp"

Vec3d RayColor(const Rayd& r, const World& world) {
    hit_record rec;
    if (world.hit(r, 0.001, std::numeric_limits<double>::infinity(), rec)) {
        Vec3d ambient = Vec3d(0.3, 0.3, 0.3);
        Vec3d diffuse = 0.7 * (rec.normal + Vec3d(1.0, 1.0, 1.0)) * 0.5;
        return ambient + diffuse;
    }

    Vec3d unit_direction = r.direction.normalized();

    double t = 0.5 * (unit_direction.y + 1.0);

    Vec3d color_a(1.0, 1.0, 1.0);
    Vec3d color_b(0.5, 0.7, 1.0);

    return (1.0 - t) * color_a + t * color_b;
}