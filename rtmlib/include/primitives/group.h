#ifndef GROUP_H    
#define GROUP_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>
#include <vector>

namespace rtm
{
class Group : public Surface
{
    private:
        std::vector<Surface*> m_children;
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
    public:
        // exception class
        class calling_normal_on_group
        {
        };

        Group();
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;
    
        void add_child(Surface* shape); 

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Group";}
};
} // namespace rtm


#endif