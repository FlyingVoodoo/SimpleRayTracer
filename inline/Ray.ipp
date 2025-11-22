template<typename T>
Ray<T>::Ray() : origin(Vec3<T>()), direction(Vec3<T>()) {}

template<typename T>
Ray<T>::Ray(const Vec3<T>& origin, const Vec3<T>& direction) 
    : origin(origin), direction(direction) {}

template<typename T>
Vec3<T> Ray<T>::pointAtParameter(T t) const {
    return origin + direction * t;
}