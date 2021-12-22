#ifndef COLOR_H    
#define COLOR_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Color : public Tuple
{
    public:
        Color();
        Color(const float& red, const float& green, const float& blue);
        Color(float* elements);

        inline float red() const {return this->t[0];}
        inline float green() const {return this->t[1];}
        inline float blue() const {return this->t[2];}

        inline float x() const {return this->t[0];}
        inline float y() const {return this->t[1];}
        inline float z() const {return this->t[2];}

        std::string to_str() const override;

        Color operator*(const Color&) const;
};
} //namespace rtm

#endif