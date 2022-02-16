#ifndef CYLINDER_H    
#define CYLINDER_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Cylinder : public Surface
{
    public:
        Cylinder();
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Cylinder";}

};
} // namespace rtm


#endif