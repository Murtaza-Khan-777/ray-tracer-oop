#ifndef VEC3_HPP
#define VEC3_HPP

class Vec3 {
private:
    // Requirement A.1: Encapsulate its data[cite: 2]
    double e[3]; 

public:
    // constructors:
    Vec3();
    Vec3(double e0, double e1, double e2);

    //getters:
    double x() const;
    double y() const;
    double z() const;
    //operator overloading for vectors:
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator*(const Vec3& v) const;
    Vec3 operator*(double t) const;
    Vec3 operator/(double t) const;


    friend Vec3 operator*(double t, const Vec3& v);

    // Math operation declarations (all const as they don't modify the object)
    double length_squared() const;
    double length() const;
    double dot(const Vec3& v) const;
    Vec3 cross(const Vec3& v) const;
    Vec3 unit_vector() const;
};

// Aliases
using Point3 = Vec3; 
using Color = Vec3;

#endif