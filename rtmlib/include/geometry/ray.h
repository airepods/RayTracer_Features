#ifndef RAY_H    
#define RAY_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/matrix.h"

namespace rtm
{
class Ray
{
    private:
        Point m_origin;
        Vector m_direction;
    public:
        Ray();
        Ray(const Point& origin, const Vector& direction);

        inline Point origin() const {return m_origin;}
        inline Vector direction() const {return m_direction;}     

        inline void set_origin(const Point& o) {m_origin = o;}
        inline void set_direction(const Vector& v) {m_direction = v;} 

        Ray transform(const Matrix& m) const;
};
} //namespace rtm

#endif