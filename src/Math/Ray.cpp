#include "Ray.hpp"

//constructors
Ray::Ray() : orig(Point3()), dir(Vec3()) {}

Ray::Ray(const Point3& origin, const Vec3& direction) 
    : orig(origin), dir(direction) {}

//getter
Point3 Ray::origin() const { 
    return orig; 
}

Vec3 Ray::direction() const { 
    return dir; 
}

// Parametric equation P(t) = A + tB
Point3 Ray::at(double t) const {
    return orig + (dir * t);
}