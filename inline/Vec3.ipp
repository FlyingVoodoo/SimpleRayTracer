template<typename T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
Vec3<T>::Vec3() : x(T()), y(T()), z(T()) {}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const {
    return Vec3<T>(x + other.x, y + other.y, z + other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const {
    return Vec3<T>(x - other.x, y - other.y, z - other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(T scalar) const {
    return Vec3<T>(x * scalar, y * scalar, z * scalar);
}

template<typename T>
Vec3<T> Vec3<T>::operator/(T scalar) const {
    return Vec3<T>(x / scalar, y / scalar, z / scalar);
}

template<typename T>
Vec3<T> Vec3<T>::operator-() const {
    return Vec3<T>(-x, -y, -z);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const Vec3<T>& other) const {
    return Vec3<T>(x * other.x, y * other.y, z * other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator/(const Vec3<T>& other) const {
    return Vec3<T>(x / other.x, y / other.y, z / other.z);
}

template<typename T>
T Vec3<T>::dot(const Vec3<T>& other) const {
    return x * other.x + y * other.y + z * other.z;
}

template<typename T>
Vec3<T> Vec3<T>::cross(const Vec3<T>& other) const {
    return Vec3<T>(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

template<typename T>
T Vec3<T>::lengthSquared() const {
    return x * x + y * y + z * z;
}

template<typename T>
T Vec3<T>::length() const {
    return std::sqrt(lengthSquared());
}

template<typename T>
Vec3<T> Vec3<T>::normalized() const {
    T lenSq = lengthSquared();
    if (lenSq > std::numeric_limits<T>::epsilon()) {
        return *this / std::sqrt(lenSq);
    }
    return Vec3<T>(T(), T(), T());
}

template<typename T>
Vec3<T> operator*(T scalar, const Vec3<T>& vec) {
    return vec * scalar;
}