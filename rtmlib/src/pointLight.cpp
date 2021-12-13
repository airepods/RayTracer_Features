#include <lighting/pointLight.h>

using namespace rtm;

PointLight::PointLight()
{}

PointLight::PointLight(const Point& position, const Color& intensity) : m_position(position), m_intensity(intensity)
{}

