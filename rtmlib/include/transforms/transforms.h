#ifndef TRANSFORMS_H    
#define TRANSFORMS_H

#include "mat_entities/matrix.h"

Matrix translation(float x, float y, float z);
Matrix scaling(float x, float y, float z);
Matrix rotation_x(float angle);
Matrix rotation_y(float angle);
Matrix rotation_z(float angle);
Matrix shearing(int x_y, int x_z, int y_x, int y_z, int z_x, int z_y);

#endif