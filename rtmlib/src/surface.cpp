#include "primitives/surface.h"
#include <iostream>
#include <utility>

using namespace rtm;

Surface::Surface() : m_transform{Matrix(4, 4)}, m_material(Material())
{
    m_transform.set_identity();
    m_is_group = false;
    m_parent = nullptr;
}

Surface::Surface(const Surface& s)
{
    m_material = s.m_material;
    m_transform = s.m_transform;
    m_is_group = s.m_is_group;
    m_parent = nullptr;
}

Surface& Surface::operator= (const Surface& s)
{
    m_material = s.m_material;
    m_transform = s.m_transform;
    m_is_group = s.m_is_group;
    m_parent = nullptr;

    return *this;
}

Surface::~Surface()
{
    std::cout<<"Surface destructor"<<"\n";
}

bool Surface::compare(const Surface* s) const
{
    // compare two pointers (memory addresses of each surfaces)
    if(this == s)
        return  true;
    else
        return false;
}

// converts point from world space to object space
Point Surface::world_to_object(Point& p) const
{
    if(this->has_parent())
    {
        // convert the point first from world space to parent space
        p = m_parent->world_to_object(p);
    }

    return inverse(m_transform) * p;
}

// converts normal from object to world space
Vector Surface::normal_to_world(Vector& normal) const
{
    normal = (inverse(m_transform)).transpose() * normal;
    normal.set_w(0);
    normal = normalize(normal);

    if(this->has_parent())
    {
        normal = this->m_parent->normal_to_world(normal);
    }

    return normal;
}
