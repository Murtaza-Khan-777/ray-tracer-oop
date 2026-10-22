#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "Ray.hpp"

// Forward declaration of Material
class Material; 

// collection of all the data to be passed on
struct HitRecord {
    Point3 p;
    Vec3 normal;
    Material* mat_ptr; //pointer to a material object
    double t;
    bool front_face;

    // Determines if the ray hit the outside or the inside of the object
    inline void set_face_normal(const Ray& r, const Vec3& outward_normal) {
        front_face = r.direction().dot(outward_normal) < 0; // if they are in same relative direction dot>=0 so it means the ray is inside the object
        normal = front_face ? outward_normal : outward_normal * -1.0; // if it is inside the ray goes towards the centre of the of the obejct (total internal reflection concept from physics)
    }
};

class Hittable {
public:
    //desctuctor
    virtual ~Hittable() = default;

    //finds if hit or not
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

#endif