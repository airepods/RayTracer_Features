#include "patterns/pattern.h"
#include "primitives/surface.h"
#include <cmath>

using namespace rtm;

Pattern::Pattern()
{}

Pattern::Pattern(const Color& a, const Color& b) 
    : m_a(a), m_b(b), m_transform{Matrix(4, 4)}, m_pattern_a(nullptr), m_pattern_b(nullptr)
{
    m_transform.set_identity();
}

Pattern::Pattern(const Color& color) : m_a(color), m_transform{Matrix(4, 4)}, m_pattern_a(nullptr), m_pattern_b(nullptr)
{
    m_b = rtm::Color(0, 0, 0);
    m_transform.set_identity();
}

Pattern::Pattern(Pattern* a, Pattern* b) : m_transform{Matrix(4, 4)}, m_pattern_a(a), m_pattern_b(b)
{
    m_a = rtm::Color(0, 0, 0);
    m_b = rtm::Color(0, 0, 0);
    m_transform.set_identity();
}

Color Pattern::pattern_at_object(const Surface* object, const Point& point) const
{
    auto object_point = object->world_to_object(point);
    auto pattern_point = inverse(m_transform) * object_point;

    return pattern_at(pattern_point);
}

Color Pattern::pattern_at_object(const Point& point) const
{   
    // point is in object space
    auto pattern_point = inverse(m_transform) * point;

    return pattern_at(pattern_point);
}