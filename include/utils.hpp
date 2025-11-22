#pragma once

#include <iostream>
#include "Vec3.hpp"
#include <random>

using Color = Vec3d;

inline void writeColor(std::ostream& out, const Color color, int samples_per_pixel) {
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

inline double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double randomDouble(double min, double max) {
    return min + (max - min) * randomDouble();
}

inline Vec3d randomInUnitSphere() {
    while (true) {
        auto p = Vec3d(
            randomDouble(-1.0, 1.0),
            randomDouble(-1.0, 1.0),
            randomDouble(-1.0, 1.0)
        );
        if (p.lengthSquared() >= 1.0) continue;
        return p;
    }
}

const int MAX_DEPTH = 50;