#include "primitives/group.h"

#include <vector>
#include <algorithm>

//#include <iostream>

using namespace rtm;

Group::Group() : Surface()
{
    m_is_group = true;
}

Group::Group(const Group& s) : Surface(s)
{
    // make children point to new parent (only upper children in the tree)
    for (auto &&child : s.m_children)
    {
        std::unique_ptr<Surface> ptr_base(child->clone());
        m_children.push_back(std::move(ptr_base));
    }
}

Group& Group::operator= (const Group& s)
{
    for (auto &&child : s.m_children)
    {
        std::unique_ptr<Surface> ptr_base(child->clone());
        m_children.push_back(std::move(ptr_base));
    }

    return *this;
}

Group::~Group()
{   
    //std::cout<<"Group destructor"<<"\n";
}

std::vector<Intersection> Group::local_intersect(const Ray& ray) const
{
    std::vector<Intersection> intersections = {};

    for(const auto& surface : m_children)
    {
        for(const auto& i : surface->intersects_with(ray))
        {
            intersections.push_back(i);
        }
    }

    std::sort(intersections.begin(), intersections.end(), [](Intersection a, Intersection b){return a < b;});
    return intersections;
}

std::vector<Intersection> Group::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(m_transform));

    return local_intersect(ray);
}

Vector Group::normal_at(const Point& world_point) const
{
    throw Group::calling_normal_on_group();
}