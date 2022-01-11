#ifndef PLANE_H    
#define PLANE_H

#include "surface.h"
#include "mat_entities/vector.h"
#include "geometry/intersection.h"
#include "geometry/ray.h"
#include <string>

namespace rtm
{
class Plane : public Surface
{
    public:
        Plane();
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Plane";}

};
} // namespace rtm


#endif