#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "geometry/intersection.h"
#include "primitives/surface.h"
#include "mat_entities/matrix.h"
#include <vector>
#include <string>
#include "materials/material.h"

namespace rtm
{
class Sphere : public Surface
{
    public:
        Sphere();

        std::vector<Intersection> intersects(const Ray&);
        
        inline std::string type_to_str() const override {return "Sphere";}
        inline Sphere* get_object_type() override {return this;}

        inline Matrix get_transform() const override {return m_transform;}
        void set_transform(const Matrix& transformation) override;

        Vector normal_at(const Point& world_point) override;

        inline Material get_material() override {return m_material;}
        inline void set_material(const Material& material) override {m_material = material;}

};
} //namespace rtm

#endif