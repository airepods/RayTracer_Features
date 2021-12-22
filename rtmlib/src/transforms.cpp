#include "transforms/transforms.h"
#include "mat_entities/matrix.h"
#include "util/utils.h"
#include <cmath>

using namespace rtm;

Matrix rtm::translation(const float& x, const float& y, const float& z)
{
    Matrix mtranslation = Matrix(4 , 4);
    mtranslation.set_identity();

    mtranslation.set_value(0, 3, x);
    mtranslation.set_value(1, 3, y);
    mtranslation.set_value(2, 3, z);

    return mtranslation;
}

Matrix rtm::scaling(const float& x, const float& y, const float& z)
{
    Matrix mscaling = Matrix(4 , 4);
    mscaling.set_identity();
    
    mscaling.set_value(0, 0, x);
    mscaling.set_value(1, 1, y);
    mscaling.set_value(2, 2, z);

    return mscaling;
}

Matrix rtm::rotation_x(float& angle)
{
    Matrix mrotate_x = Matrix(4 , 4);
    mrotate_x.set_identity();

    angle = to_radians(angle);

    mrotate_x.set_value(1, 1, cos(angle));
    mrotate_x.set_value(1, 2, -sin(angle));
    mrotate_x.set_value(2, 1, sin(angle));
    mrotate_x.set_value(2, 2, cos(angle));

    return mrotate_x;
}

Matrix rtm::rotation_y(float& angle)
{
    Matrix mrotate_y = Matrix(4 , 4);
    mrotate_y.set_identity();

    angle = to_radians(angle);

    mrotate_y.set_value(0, 0, cos(angle));
    mrotate_y.set_value(0, 2, sin(angle));
    mrotate_y.set_value(2, 0, -sin(angle));
    mrotate_y.set_value(2, 2, cos(angle));

    return mrotate_y;
}

Matrix rtm::rotation_z(float& angle)
{
    Matrix mrotate_z = Matrix(4 , 4);
    mrotate_z.set_identity();

    angle = to_radians(angle);

    mrotate_z.set_value(0, 0, cos(angle));
    mrotate_z.set_value(0, 1, -sin(angle));
    mrotate_z.set_value(1, 0, sin(angle));
    mrotate_z.set_value(1, 1, cos(angle));

    return mrotate_z;
}

Matrix rtm::shearing(const int& x_y, const int& x_z, const int& y_x, const int& y_z, const int& z_x, const int& z_y)
{
    Matrix mshearing = Matrix(4 , 4);
    mshearing.set_identity();

    mshearing.set_value(0, 1, x_y);
    mshearing.set_value(0, 2, x_z);
    mshearing.set_value(1, 0, y_x);
    mshearing.set_value(1, 2, y_z);
    mshearing.set_value(2, 0, z_x);
    mshearing.set_value(2, 1, z_y);

    return mshearing;
}