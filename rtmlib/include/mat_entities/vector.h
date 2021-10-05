#ifndef VECTOR_H    
#define VECTOR_H

#include "mat_entities/tuple.h"
#include <string>

class Vector : public Tuple
{
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(float x, float y, float z, float w);
        Vector(float* elements);

        inline float x() {return this->t[0];}
        inline float y() {return this->t[1];}
        inline float z() {return this->t[2];}
        inline float w() {return this->t[3];}

        std::string to_str();

        Vector operator- ();

        // Compute the magnitude of the vector
        float magnitude();
        // Normalize the vector
        Vector normalize();
        // Compute the dot product with another vector
        float dot(Vector);
};

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
#endif