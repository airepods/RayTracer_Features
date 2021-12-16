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

        virtual std::string type_to_str() const = 0;

        virtual Surface* get_object_type() = 0;
        
        virtual Vector normal_at(const Point& world_point) = 0;

        virtual Matrix get_transform() const = 0;
        virtual void set_transform(const Matrix&) = 0;

        virtual Material get_material() = 0;
        virtual void set_material(const Material& material) = 0;
};
} // namespace rtm

#endif