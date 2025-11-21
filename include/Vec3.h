#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class Vec3 {
public:
    double x, y, z;

    Vec3();
    Vec3(double x, double y, double z);

    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(double scalar) const;
    Vec3 operator/(double scalar) const;
    Vec3 operator-() const;

    double dot(const Vec3& v) const;
    Vec3 cross(const Vec3& v) const;
    double length() const;
    double lengthSquared() const;
    Vec3 normalized() const;
};

// Helper function for scalar * vector
Vec3 operator*(double scalar, const Vec3& v);

#endif // VEC3_H
