#ifndef WORLD_H    
#define WORLD_H

#include "lighting/pointLight.h"
#include "primitives/surface.h"
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
        ~World();

        //getters
        inline PointLight get_pointLight() {return m_light;}
        inline std::vector<Surface*> get_surfaces() {return m_surfaces;}
};
} // namespace rtm


#endif