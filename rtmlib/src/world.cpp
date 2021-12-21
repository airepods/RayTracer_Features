#include "worldScene/world.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"
#include "primitives/sphere.h"
#include "materials/material.h"
#include "mat_entities/color.h"
#include "transforms/transforms.h"

using namespace rtm;

World::World()
{
    m_light = PointLight(Point(-10, 10, -10), Color(1, 1, 1));
    Sphere* s1 = new Sphere;
    Sphere* s2 = new Sphere;

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

    m_surfaces.push_back(s1);
    m_surfaces.push_back(s2);
}

World::~World()
{
    for(auto p : m_surfaces)
    {
        delete p;
    }
    m_surfaces.clear();
}
