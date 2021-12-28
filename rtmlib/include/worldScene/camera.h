#ifndef CAMERA_H    
#define CAMERA_H

#include "mat_entities/matrix.h"
#include "geometry/ray.h"

namespace rtm
{
class Camera
{
    private:
        unsigned int m_hsize; // pixels
        unsigned int m_vsize; // pixels
        float half_width;   // world-space units
        float half_height;  // world-space units
        float pixel_size;   // world-space units
        float m_field_of_view;
        Matrix m_transform;
    public:
        Camera();
        Camera(const int& hsize, const int& vsize, const float& field_of_view);

        Ray ray_for_pixel(const int& px, const int& py) const;

        inline float get_pixel_size() const {return pixel_size;}
        inline int get_hsize() const {return m_hsize;}
        inline int get_vsize() const {return m_vsize;}
        inline Matrix get_transform() const {return m_transform;}

        inline void set_transform(const Matrix& transform) {m_transform = transform;}


};
} // namespace rtm

#endif