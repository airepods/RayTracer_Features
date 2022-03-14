#ifndef CAMERA_H    
#define CAMERA_H

#include "geometry/ray.h"

namespace rtm
{
class Camera
{
    private:
        unsigned int m_hsize; // pixels
        unsigned int m_vsize; // pixels
        double half_width;   // world-space units
        double half_height;  // world-space units
        double pixel_size;   // world-space units
        double m_field_of_view;
        Matrix m_transform;
        Matrix inv_transform;
    public:
        Camera();
        Camera(const int& hsize, const int& vsize, const double& field_of_view);

        Ray ray_for_pixel(const int& px, const int& py) const;

        inline double get_pixel_size() const {return pixel_size;}
        inline int get_hsize() const {return m_hsize;}
        inline int get_vsize() const {return m_vsize;}
        inline Matrix get_transform() const {return m_transform;}

        void set_transform(const Matrix& transform);


};
} // namespace rtm

#endif