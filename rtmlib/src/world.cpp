#include "worldScene/world.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"
#include "primitives/sphere.h"
#include "materials/material.h"
#include "mat_entities/color.h"
#include "transforms/transforms.h"
#include <algorithm>

using namespace rtm;

World::World()
{
    m_light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere* s1 = new Sphere();
    Sphere* s2 = new Sphere();

    // default sphere 1
    auto matsph1 = Material();
    matsph1.set_color(Color(0.8f, 1.0f, 0.6f));
    matsph1.set_diffuse(0.7f);
    matsph1.set_specular(0.2f);
    // then material is deleted by the end of the scope
    // but set_material receives a variable by reference 
    // and modifies the material attrbute of the surface
    s1->set_material(matsph1);

    // default sphere 2
    s2->set_transform(scaling(0.5f, 0.5f, 0.5f));

    m_surfaces = {s1, s2};
}

World::World(const PointLight& light, const std::vector<Surface*>& surfaces) : m_light(light), m_surfaces(surfaces)
{}

World::~World()
{
    for(auto p : m_surfaces)
    {
        delete p;
    }
    m_surfaces.clear();
}

// TODO implement copy constructors

std::vector<Intersection> World::intersects_with(const Ray& r) const
{
    std::vector<Intersection> intersections;

    for(auto surface : m_surfaces)
    {
        for(auto i : surface->intersects_with(r))
        {
            intersections.push_back(i);
        }
    }

    std::sort(intersections.begin(), intersections.end(), [](Intersection a, Intersection b){return a < b;});
    return intersections;
}

