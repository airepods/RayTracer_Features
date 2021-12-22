#ifndef SURFACE_H    
#define SURFACE_H

#include <string> 
#include "mat_entities/matrix.h"
#include "materials/material.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "geometry/ray.h"
#include <vector>

namespace rtm
{
class Intersection;

class Surface
{
    protected:
        Matrix m_transform;
        Material m_material;
    public:
        Surface();
        Surface(const Surface& s);
        
        virtual std::string type_to_str() const = 0;
        virtual Vector normal_at(const Point& world_point) const = 0;
        virtual std::vector<Intersection> intersects_with(const Ray&) const = 0;

        inline Matrix get_transform() const {return m_transform;}
        inline void set_transform(const Matrix& transformation) {m_transform = transformation;};

        inline Material get_material() const {return m_material;}
        inline void set_material(const Material& material) {m_material = material;}


};
} // namespace rtm

#endif