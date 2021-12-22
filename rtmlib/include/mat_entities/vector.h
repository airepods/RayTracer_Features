#ifndef VECTOR_H    
#define VECTOR_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Vector : public Tuple
{
    public:
        Vector();
        Vector(const float& x, const float& y, const float& z);
        Vector(const float& x, const float& y, const float& z, const float& w);
        Vector(float* elements);

        inline float x() const {return this->t[0];}
        inline float y() const {return this->t[1];}
        inline float z() const {return this->t[2];}
        inline float w() const {return this->t[3];}

        inline void set_w(const float& w_val) { t[3] = w_val; }

        std::string to_str() const override;

        Vector operator- () const;

        float magnitude() const;
        Vector normalize() const;
        float dot(const Vector&) const;
};
} //namespace rtm

#endif