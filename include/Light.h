#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3.h"

class Light {
public:
    Vec3 position;
    double intensity;

    Light();
    Light(const Vec3& position, double intensity);
};

#endif // LIGHT_H
