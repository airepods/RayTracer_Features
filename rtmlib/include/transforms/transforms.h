#ifndef TRANSFORMS_H    
#define TRANSFORMS_H

#include "mat_entities/matrix.h"
#include "mat_entities/vector.h"

namespace rtm
{
Matrix translation(const float& x, const float& y, const float& z);
Matrix scaling(const float& x, const float& y, const float& z);
Matrix rotation_x(const float& angle);
Matrix rotation_y(const float& angle);
Matrix rotation_z(const float& angle);
Matrix shearing(const int& x_y, const int& x_z, const int& y_x, const int& y_z, const int& z_x, const int& z_y);
Matrix view_transform(const Point& from, const Point& to, const Vector& up);
} // namespace rtm

#endif