#include "primitives/group.h"

#include <vector>
#include <algorithm>

using namespace rtm;

Group::Group() : Surface()
{
    m_children = {};
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
    Ray ray = r.transform(inverse(this->get_transform()));

    return local_intersect(ray);
}

Vector Group::normal_at(const Point& world_point) const
{
    throw Group::calling_normal_on_group();
}

void Group::add_child(Surface* shape)
{
    shape->set_parent(this);
    m_children.push_back(shape);
}