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
        Color(const double& red, const double& green, const double& blue);
        Color(double* elements);

        inline double red() const {return this->t[0];}
        inline double green() const {return this->t[1];}
        inline double blue() const {return this->t[2];}

        inline double x() const {return this->t[0];}
        inline double y() const {return this->t[1];}
        inline double z() const {return this->t[2];}

        std::string to_str() const override;

        Color operator*(const Color&) const;
};
} //namespace rtm

#endif