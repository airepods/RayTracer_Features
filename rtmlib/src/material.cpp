#include "materials/material.h"

using namespace rtm;

Material::Material() : m_color(1, 1, 1), m_ambient(0.1f), m_diffuse(0.9f), m_specular(0.9f), m_shininess(200.0f)
{}

void Material::set_pattern(Pattern& pattern)
{
    pattern.exists = true;
    m_pattern = pattern;
}

