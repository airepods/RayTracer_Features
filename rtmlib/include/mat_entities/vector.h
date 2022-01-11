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
        Vector(const double& x, const double& y, const double& z);
        Vector(const double& x, const double& y, const double& z, const double& w);
        Vector(double* elements);

        inline double x() const {return this->t[0];}
        inline double y() const {return this->t[1];}
        inline double z() const {return this->t[2];}
        inline double w() const {return this->t[3];}

        inline void set_w(const double& w_val) { t[3] = w_val; }

        std::string to_str() const override;

        Vector operator- () const;

        double magnitude() const;
        Vector normalize() const;
        double dot(const Vector&) const;
};
} //namespace rtm

#endif