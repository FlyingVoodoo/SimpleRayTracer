#pragma once

#include <iostream>
#include "Vec3.hpp"

inline void writeColor(std::ostream& out, const Vec3d color, int samples_per_pixel) {
    double scale = 1.0 / samples_per_pixel;
    double r = std::sqrt(color.x * scale);
    double g = std::sqrt(color.y * scale);
    double b = std::sqrt(color.z * scale);

    auto to_byte = [](double intensity){
        if (std::isnan(intensity) || intensity < 0.0) intensity = 0.0;
        if (intensity > 1.0) intensity = 1.0;

        return static_cast<int>(255.999 * intensity);
    };

    out << to_byte(r) << ' ' << to_byte(g) << ' ' << to_byte(b) << '\n';
}