#include "Light.h"

Light::Light() : position(Vec3(0, 10, 0)), intensity(1.0) {}

Light::Light(const Vec3& position, double intensity) 
    : position(position), intensity(intensity) {}
