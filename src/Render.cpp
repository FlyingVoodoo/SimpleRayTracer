#include "Render.hpp"
#include "Ray.hpp"
#include "utils.hpp"
#include "Material.hpp"

Color RayColor(const Rayd& r, const World& world, int depth) {
    hit_record rec;
    if (depth <= 0) {
        return Color(0.0, 0.0, 0.0);
    }
    if (world.hit(r, 0.001, std::numeric_limits<double>::infinity(), rec)) {
        Rayd scattered;
        Color attenuation;
        if (rec.material->scatter(r, rec, attenuation, scattered)) {
            return attenuation * RayColor(scattered, world, depth - 1);
        }

        return Color(0.0, 0.0, 0.0);
    }

    Vec3d unit_direction = r.direction.normalized();

    double t = 0.5 * (unit_direction.y + 1.0);

    Vec3d color_a(1.0, 1.0, 1.0);
    Vec3d color_b(0.5, 0.7, 1.0);

    return (1.0 - t) * color_a + t * color_b;
}