#pragma once

#include "Vec3.hpp"
#include "Material.hpp"
#include "utils.hpp"

class Lambertian : public Material {
public:
    Color albredo;

    Lambertian(const Color& a) : albredo(a) {}

    virtual bool scatter(const Rayd& r_in, const hit_record& rec, Color& attenuation, Rayd& scattered) const override;
};