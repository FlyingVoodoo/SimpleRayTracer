#pragma once

#include "Ray.hpp"
#include "Vec3.hpp"


class Camera {
public:
    Vec3d origin;
    Vec3d lower_left_corner;
    Vec3d horizontal;
    Vec3d vertical;

    Camera() {
        double aspect_ratio = 16.0 / 9.0;
        double viewport_height = 2.0;
        double viewport_width = aspect_ratio * viewport_height;
        
        origin = Vec3d(0.0, 0.0, 0.0);
        
        horizontal = Vec3d(viewport_width, 0.0, 0.0);
        vertical = Vec3d(0.0, viewport_height, 0.0);
        
        lower_left_corner = origin - horizontal / 2.0 - vertical / 2.0 - Vec3d(0.0, 0.0, 1.0);
    }

    Ray<double> get_ray(double u, double v) const {
        return Ray<double>(origin, lower_left_corner + horizontal * u + vertical * v - origin);
    }
};