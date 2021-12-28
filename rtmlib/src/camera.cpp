#include "worldScene/camera.h"
#include "math.h"
#include "mat_entities/matrix_utility.h"
#include "mat_entities/point.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/vector_utility.h"

using namespace rtm;

Camera::Camera()
{}

Camera::Camera(const int& hsize, const int& vsize, const float& field_of_view)
: m_hsize(hsize), m_vsize(vsize), m_field_of_view(field_of_view), m_transform{Matrix(4, 4)}
{
    m_transform.set_identity(); 

    float half_view = tan(m_field_of_view/2);
    float aspect = (static_cast<float>(m_hsize)/static_cast<float>(m_vsize));

    if(aspect >= 1)
    {
        half_width = half_view;
        half_height = half_view/aspect;
    }
    else
    {
        half_width = half_view * aspect;
        half_height = half_view;
    }

    pixel_size = (half_width*2)/m_hsize;
}

Ray Camera::ray_for_pixel(const int& px, const int& py) const // px and py are in canvas space (pixel locations)
{
    // the offset from the edge of the canvas to the pixel's center
    float xoffset = (px + 0.5f) * pixel_size;
    float yoffset = (py + 0.5f) * pixel_size;

    // the untransformed coordinates of the pixel in world space.
    float world_x = half_width - xoffset;
    float world_y = half_height - yoffset;

    // using the camera matrix, transform the canvas point and the origin,
    // and then compute the ray's direction vector. (canvas is at z=-1)
    Point pixel = inverse(m_transform) * Point(world_x, world_y, -1);
    Point origin = inverse(m_transform) * Point(0, 0, 0);
    auto direction = normalize(pixel - origin);

    return Ray(origin, direction);
}