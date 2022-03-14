#include "worldScene/world.h"
#include <algorithm>

using namespace rtm;

World::World()
{
    default_flag = true;

    m_light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere* s1 = new Sphere();
    Sphere* s2 = new Sphere();

    // default sphere 1
    auto matsph1 = Material();
    matsph1.set_color(Color(0.8, 1.0, 0.6));
    matsph1.set_diffuse(0.7);
    matsph1.set_specular(0.2);
    // then material is deleted by the end of the scope
    // but set_material receives a variable by reference 
    // and modifies the material attrbute of the surface
    s1->set_material(matsph1);

    // default sphere 2
    s2->set_transform(scaling(0.5, 0.5, 0.5));

    m_surfaces = {s1, s2};
}

World::World(const PointLight& light, const std::vector<Surface*>& surfaces, bool ptr_delete) : m_light(light), m_surfaces(surfaces), default_flag(false)
{
    if(ptr_delete)
        m_ptr_delete = true;
}

World::~World()
{
    // if default flag is active (true)
    if(default_flag || m_ptr_delete)
    {
        for(auto p : m_surfaces)
        {
            delete p;
        }
        m_surfaces.clear();
    }
    // if not dont do nothing

}

// TODO implement copy constructors

std::vector<Intersection> World::intersects_with(const Ray& r) const
{
    std::vector<Intersection> intersections;

    for(const auto& surface : m_surfaces)
    {
        for(const auto& i : surface->intersects_with(r))
        {
            intersections.push_back(i);
        }
    }

    std::sort(intersections.begin(), intersections.end(), [](Intersection a, Intersection b){return a < b;});
    return intersections;
}

void World::precompute_inverse() const
{
    for(auto& surface : m_surfaces)
    {
        surface->set_invTransform();
    }
    
}

