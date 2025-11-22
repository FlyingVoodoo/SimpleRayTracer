#pragma once

#include "Ray.hpp"
#include "Hittable.hpp"
#include "utils.hpp"

class Hittable;

class Material {
public:
    virtual bool scatter(const Rayd& r_in, const hit_record& rec, Color& attenuation, Rayd& scattered) const = 0;

    virtual ~Material() = default;
};