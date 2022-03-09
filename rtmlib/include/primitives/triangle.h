#ifndef TRIANGLE_H    
#define TRIANGLE_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Triangle : public Surface
{
    private:
        Point m_p1;
        Point m_p2; 
        Point m_p3;
        Vector m_e1;
        Vector m_e2;
        Vector m_normal;
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual Triangle* clone_impl() const override { return new Triangle(*this); }
    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3);
        Triangle(const Triangle& s);
        Triangle& operator= (const Triangle& s);
        ~Triangle();
        
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        inline std::string type_to_str() const override {return "Triangle";}
};
} // namespace rtm


#endif