#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "geometry/intersection.h"
#include "primitives/shape.h"
#include "mat_entities/matrix.h"
#include <vector>
#include <string>

namespace rtm
{
class Sphere : public Shape
{
    private:
        Matrix _transform;
    public:
        Sphere();
        std::vector<Intersection> intersects(const Ray& r);
        
        inline std::string type_to_str() const override {return "Sphere";}
        inline Sphere* get_object_type() override {return this;}
        inline Matrix get_transform() {return _transform;}

        void set_transform(Matrix& transformation);
};
} //namespace rtm

#endif