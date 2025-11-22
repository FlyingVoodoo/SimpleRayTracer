#include "Lambertian.hpp"
#include "utils.hpp"

bool Lambertian::scatter(const Rayd& r_in, const hit_record& rec, Color& attenuation, Rayd& scattered) const {
    auto scatter_direction = rec.normal + randomInUnitSphere();

    if (scatter_direction.nearZero())
        scatter_direction = rec.normal;

    scattered = Rayd(rec.point, scatter_direction);
    attenuation = albredo;
    return true;
}