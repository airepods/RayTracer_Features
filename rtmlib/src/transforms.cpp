#include "transforms/transforms.h"
#include "mat_entities/matrix.h"
#include "util/utils.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/vector_utility.h"
#include "mat_entities/matrix.h"
#include "mat_entities/matrix_utility.h"
#include <cmath>

using namespace rtm;

Matrix rtm::translation(const double& x, const double& y, const double& z)
{
    Matrix mtranslation = Matrix(4 , 4);
    mtranslation.set_identity();

    mtranslation.set_value(0, 3, x);
    mtranslation.set_value(1, 3, y);
    mtranslation.set_value(2, 3, z);

    return mtranslation;
}

Matrix rtm::scaling(const double& x, const double& y, const double& z)
{
    Matrix mscaling = Matrix(4 , 4);
    mscaling.set_identity();
    
    mscaling.set_value(0, 0, x);
    mscaling.set_value(1, 1, y);
    mscaling.set_value(2, 2, z);

    return mscaling;
}

Matrix rtm::rotation_x(const double& angle)
{
    Matrix mrotate_x = Matrix(4 , 4);
    mrotate_x.set_identity();

    mrotate_x.set_value(1, 1, std::cos(angle));
    mrotate_x.set_value(1, 2, -std::sin(angle));
    mrotate_x.set_value(2, 1, std::sin(angle));
    mrotate_x.set_value(2, 2, std::cos(angle));

    return mrotate_x;
}

Matrix rtm::rotation_y(const double& angle)
{
    Matrix mrotate_y = Matrix(4 , 4);
    mrotate_y.set_identity();

    mrotate_y.set_value(0, 0, std::cos(angle));
    mrotate_y.set_value(0, 2, std::sin(angle));
    mrotate_y.set_value(2, 0, -std::sin(angle));
    mrotate_y.set_value(2, 2, std::cos(angle));

    return mrotate_y;
}

Matrix rtm::rotation_z(const double& angle)
{
    Matrix mrotate_z = Matrix(4 , 4);
    mrotate_z.set_identity();

    mrotate_z.set_value(0, 0, std::cos(angle));
    mrotate_z.set_value(0, 1, -std::sin(angle));
    mrotate_z.set_value(1, 0, std::sin(angle));
    mrotate_z.set_value(1, 1, std::cos(angle));

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

Matrix rtm::view_transform(const Point& from, const Point& to, const Vector& up)
{
    auto forward = normalize(to - from);
    auto left = cross(forward, normalize(up));
    auto true_up = cross(left, forward);

    double mat_or[16] = { left.x(), left.y(), left.z(), 0, 
                         true_up.x(), true_up.y(), true_up.z(), 0,
                         -forward.x(), -forward.y(), -forward.z(), 0,
                         0, 0, 0, 1};

    Matrix orientation(4, 4, mat_or);

    return orientation * translation(-from.x(), -from.y(), -from.z());    
}
