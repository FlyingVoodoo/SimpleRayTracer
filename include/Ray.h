#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
public:
    Vec3 origin;
    Vec3 direction;

    Ray();
    Ray(const Vec3& origin, const Vec3& direction);

    Vec3 pointAt(double t) const;
};

#endif // RAY_H
