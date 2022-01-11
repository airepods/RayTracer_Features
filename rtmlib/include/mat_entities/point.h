#ifndef POINT_H    
#define POINT_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Point : public Tuple
{
    public:
        Point();
        Point(const double& x, const double& y, const double& z);
        Point(const double& x, const double& y, const double& z, const double& w);
        Point(double* elements);

        inline double x() const {return this->t[0];}
        inline double y() const {return this->t[1];}
        inline double z() const {return this->t[2];}
        inline double w() const {return this->t[3];}

        std::string to_str() const override;

        Point operator- () const;
};
} //namespace rtm

#endif