cmake_minimum_required(VERSION 3.10)
project(SimpleRayTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/Vec3.cpp
    src/Ray.cpp
    src/Camera.cpp
    src/Sphere.cpp
    src/Plane.cpp
    src/Light.cpp
    src/Scene.cpp
)

# Headers
set(HEADERS
    include/Vec3.h
    include/Ray.h
    include/Camera.h
    include/Shape.h
    include/Sphere.h
    include/Plane.h
    include/Light.h
    include/Scene.h
)

# Include directories
include_directories(include)

# Create executable
add_executable(raytracer ${SOURCES} ${HEADERS})
