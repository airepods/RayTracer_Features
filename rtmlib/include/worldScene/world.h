#ifndef WORLD_H    
#define WORLD_H

#include "lighting/pointLight.h"
#include "primitives/surface.h"
#include "geometry/intersection.h"
#include "geometry/ray.h"
#include <vector>

namespace rtm
{
class World
{   
    private:
        PointLight m_light;
        std::vector<Surface*> m_surfaces;
    public:
        World();
        World(const PointLight& light, const std::vector<Surface*>& surfaces);
        ~World();

        std::vector<Intersection> intersects_with(const Ray& r) const;

        //getters
        inline PointLight get_pointLight() const {return m_light;}
        inline std::vector<Surface*> get_surfaces() const {return m_surfaces;}

        //setters
        inline void set_light(const PointLight& light) {m_light = light;}
};
} // namespace rtm


#endif