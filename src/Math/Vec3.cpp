#include "Vec3.hpp"
#include <cmath>

// constructors
Vec3::Vec3() : e{0.0, 0.0, 0.0} {}

Vec3::Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

// Getters
double Vec3::x() const { return e[0]; }
double Vec3::y() const { return e[1]; }
double Vec3::z() const { return e[2]; }

// Operators
Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
}

Vec3 Vec3::operator*(const Vec3& v) const {
    return Vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
}

Vec3 Vec3::operator*(double t) const {
    return Vec3(e[0] * t, e[1] * t, e[2] * t);
}

Vec3 Vec3::operator/(double t) const {
    return Vec3(e[0] / t, e[1] / t, e[2] / t);
}

// Friend function definition
Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

// Math stuff
double Vec3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

double Vec3::length() const {
    return std::sqrt(length_squared());
}

double Vec3::dot(const Vec3& v) const {
    return e[0] * v.x() + e[1] * v.y() + e[2] * v.z();
}

Vec3 Vec3::cross(const Vec3& v) const {
    return Vec3(e[1] * v.z() - e[2] * v.y(),
                e[2] * v.x() - e[0] * v.z(),
                e[0] * v.y() - e[1] * v.x());
}

Vec3 Vec3::unit_vector() const {
    return *this / length();
}