#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"
//Ray is a line in 3d space it has a origin and a direction vector hence it can be represented by the parametric equation of a straight line in 3d space.
class Ray {
private:
    
    Point3 orig;//--> Point of origin of the ray
    Vec3 dir; // --> direction of the ray

public:
    
    Ray(); //default constructor of origination 0.00,0.00,0.00 in direction 0. 00,0.00,0.00
    Ray(const Point3& origin, const Vec3& direction); // copy constructorw
    //getters:
    Point3 origin() const; 
    Vec3 direction() const;

    // Calculates the 3D coordinate at parameter t along the ray
    Point3 at(double t) const;
};

#endif