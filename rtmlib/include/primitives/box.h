#ifndef BOX_H    
#define BOX_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Box : public Surface
{    
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
    public:
        Box();
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Box";}

};
} // namespace rtm


#endif