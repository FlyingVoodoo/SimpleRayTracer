#include "Vec3.h"

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(double scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(double scalar) const {
    if (std::abs(scalar) < 1e-8) {
        return Vec3(0, 0, 0);
    }
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}

double Vec3::dot(const Vec3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::cross(const Vec3& v) const {
    return Vec3(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
    );
}

double Vec3::length() const {
    return std::sqrt(lengthSquared());
}

double Vec3::lengthSquared() const {
    return x * x + y * y + z * z;
}

Vec3 Vec3::normalized() const {
    double len = length();
    if (len > 1e-8) {
        return *this / len;
    }
    return Vec3(0, 0, 0);
}

Vec3 operator*(double scalar, const Vec3& v) {
    return v * scalar;
}
