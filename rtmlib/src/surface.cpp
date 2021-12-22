#include "primitives/surface.h"
#include "mat_entities/matrix.h"

using namespace rtm;

Surface::Surface() : m_transform{Matrix(4, 4)}, m_material(Material())
{
    m_transform.set_identity();
}

Surface::Surface(const Surface& s)
{
    m_material = s.m_material;
    m_transform = s.m_transform;
}
