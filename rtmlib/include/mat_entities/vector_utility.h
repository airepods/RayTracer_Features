#ifndef VECTOR_UTILITY_H    
#define VECTOR_UTILITY_H

#include "vector.h"

namespace rtm
{
inline float dot(Vector v1, Vector v2)
{
    return v1.x()*v2.x() + 
           v1.y()*v2.y() + 
           v1.z()*v2.z() + 
           v1.w()*v2.w();
}

inline Vector cross(Vector v1, Vector v2)
{
    return Vector(v1.y()*v2.z() - v1.z()*v2.y(),
                  v1.z()*v2.x() - v1.x()*v2.z(),
                  v1.x()*v2.y() - v1.y()*v2.x());
}

inline Vector normalize(Vector v)
{
    return Vector(v.x()/v.magnitude(), 
                  v.y()/v.magnitude(), 
                  v.z()/v.magnitude());
}
}

#endif
