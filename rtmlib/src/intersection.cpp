#include "geometry/intersection.h"

using namespace rtm;

Intersection::Intersection() : m_object(nullptr)
{}

Intersection::Intersection(const double& t_val , const Surface* object_val) : m_t(t_val)
{
    m_object = const_cast<Surface*>(object_val);
}

double Intersection::get_t() const
{
    return m_t;
}

Surface* Intersection::get_shape() const
{
    return m_object;
}

bool Intersection::operator < (const Intersection& i) const
{
    return (m_t < i.m_t);
}

