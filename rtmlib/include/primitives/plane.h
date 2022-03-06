#ifndef PLANE_H    
#define PLANE_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Plane : public Surface
{
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual Plane* clone_impl() const override { return new Plane(*this); }
    public:
        Plane();
        ~Plane();

        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Plane";}

};
} // namespace rtm


#endif