#ifndef SPHERE_H    
#define SPHERE_H

#include "surface.h"
#include "geometry/intersection.h"
#include <vector>
#include <string>

namespace rtm
{
class Sphere : public Surface
{
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual Sphere* clone_impl() const override { return new Sphere(*this); }
    public:
        Sphere();
        ~Sphere();

        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;
        
        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Sphere";}
};
} //namespace rtm

#endif