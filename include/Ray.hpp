#pragma once

#include "Vec3.hpp"

template<typename T>
class Ray {
public:
    Vec3<T> origin;
    Vec3<T> direction;

    Ray();
    Ray(const Vec3<T>& origin, const Vec3<T>& direction);

    Vec3<T> pointAtParameter(T t) const;
};

using Rayf = Ray<float>;
using Rayd = Ray<double>;

#include "../inline/Ray.ipp"
