#ifndef POINTLIGHT_H    
#define POINTLIGHT_H

#include "mat_entities/point.h"
#include "mat_entities/color.h"

namespace rtm
{
    class PointLight
    {
        private:
            Point m_position;
            Color m_intensity;
        public:
            PointLight();
            PointLight(const Point& position, const Color& intensity);

            inline Point get_position() const {return m_position;}
            inline Color get_intensity() const {return m_intensity;}
    };
}


#endif