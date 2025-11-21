#include "Camera.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Camera::Camera() {
    double aspectRatio = 16.0 / 9.0;
    double viewportHeight = 2.0;
    double viewportWidth = aspectRatio * viewportHeight;
    double focalLength = 1.0;

    origin = Vec3(0, 0, 0);
    horizontal = Vec3(viewportWidth, 0, 0);
    vertical = Vec3(0, viewportHeight, 0);
    lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);
}

Camera::Camera(const Vec3& lookFrom, const Vec3& lookAt, const Vec3& vup,
               double vfov, double aspect) {
    double theta = vfov * M_PI / 180.0;
    double halfHeight = std::tan(theta / 2.0);
    double halfWidth = aspect * halfHeight;

    origin = lookFrom;
    Vec3 w = (lookFrom - lookAt).normalized();
    Vec3 u = vup.cross(w).normalized();
    Vec3 v = w.cross(u);

    lowerLeftCorner = origin - halfWidth * u - halfHeight * v - w;
    horizontal = 2.0 * halfWidth * u;
    vertical = 2.0 * halfHeight * v;
}

Ray Camera::getRay(double u, double v) const {
    return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
