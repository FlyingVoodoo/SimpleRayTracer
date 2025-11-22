#pragma once

#include <cmath>
#include <limits>

template<typename T>
class Vec3 {
public:
    T x, y, z;

    Vec3();
    Vec3(T x, T y, T z);

    Vec3<T> operator+(const Vec3<T>& other) const;
    Vec3<T> operator-(const Vec3<T>& other) const;
    Vec3<T> operator*(T scalar) const;
    Vec3<T> operator/(T scalar) const;
    Vec3<T> operator-() const;

    T dot(const Vec3<T>& other) const;
    Vec3<T> cross(const Vec3<T>& other) const;
    T lengthSquared() const;
    T length() const;
    Vec3<T> normalized() const;
};

template<typename T>
Vec3<T> operator*(T scalar, const Vec3<T>& vec);

using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;
using Vec3i = Vec3<int>;

#include "../inline/Vec3.ipp"





