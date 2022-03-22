#include "geometry/intersection.h"
#include <utility>

using namespace rtm;

Intersection::Intersection() : m_object(nullptr)
{}

Intersection::Intersection(const double& t_val , const Surface* object_val) : m_t(t_val)
{
    m_object = const_cast<Surface*>(object_val);
}

Intersection::Intersection(
    const double& t_val, 
    const Surface* object_val, 
    const double& u, 
    const double& v) :
    m_t(t_val), u(u), v(v)
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

bool Intersection::is_equal(const Intersection& i) const
{
    // if the two numbers are equal
    if(fcompare(m_t, i.get_t()) && m_object->compare(i.get_shape()))
        return true;
    else    
        return false;
}


bool Intersection::operator < (const Intersection& i) const
{
    return (m_t < i.m_t);
}

