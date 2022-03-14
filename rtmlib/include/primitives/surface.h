#ifndef SURFACE_H    
#define SURFACE_H

#include <string> 
#include <vector>
#include <memory>

#include "materials/material.h"
#include "geometry/ray.h"

namespace rtm
{
class Intersection;

class Surface
{
    protected:
        Matrix m_transform;
        Material m_material;
        Surface* m_parent;
        bool m_is_group;
        Matrix inv_transform;
    protected:
        virtual std::vector<Intersection> local_intersect(const Ray&) const = 0;
        virtual Surface* clone_impl() const = 0;
    public:
        Surface();
        Surface(const Surface& s);
        Surface& operator= (const Surface&);
        virtual ~Surface();
        
        inline auto clone() const { return std::unique_ptr<Surface>(clone_impl()); }

        virtual std::string type_to_str() const = 0;
        virtual Vector normal_at(const Point& world_point) const = 0;
        virtual std::vector<Intersection> intersects_with(const Ray&) const = 0;

        inline Matrix get_transform() const {return m_transform;}
        inline void set_transform(const Matrix& transformation) {m_transform = transformation;}

        virtual void set_invTransform() {inv_transform = inverse(m_transform);}

        inline Material get_material() const {return m_material;}
        inline void set_material(const Material& material) {m_material = material;}

        inline bool has_parent() const {return m_parent != nullptr;}
        virtual void set_parent(Surface* surface) {m_parent = surface;}
        //inline std::unique_ptr<Surface> get_parent() const {return m_parent;} 

        inline bool is_group() const {return m_is_group;}
        
        bool compare(const Surface* s) const;

        Point world_to_object(Point& p) const;
        Vector normal_to_world(Vector& normal) const;
};
} // namespace rtm

#endif