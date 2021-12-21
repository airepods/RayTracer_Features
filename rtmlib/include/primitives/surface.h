#ifndef SURFACE_H    
#define SURFACE_H

#include <string> 
#include "mat_entities/matrix.h"
#include "materials/material.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include <vector>

namespace rtm
{
class Surface
{
    protected:
        Matrix m_transform;
        Material m_material;
    public:
        Surface();

        virtual std::string type_to_str() = 0;
        virtual Vector normal_at(const Point& world_point) = 0;

        inline Matrix get_transform() {return m_transform;}
        inline void set_transform(const Matrix& transformation) {m_transform = transformation;};

        inline Material get_material() {return m_material;}
        inline void set_material(const Material& material) {m_material = material;}
};
} // namespace rtm

#endif