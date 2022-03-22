#ifndef SMOOTHTRIANGLE_H    
#define SMOOTHTRIANGLE_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class SmoothTriangle : public Surface
{
    private:
        // vertices
        Point m_p1;
        Point m_p2; 
        Point m_p3;
        // normal vertices
        Vector m_n1;
        Vector m_n2;
        Vector m_n3;
        // edges
        Vector m_e1;
        Vector m_e2;
        // face normal
        Vector m_normal;
    protected:
        inline virtual SmoothTriangle* clone_impl() const override { return new SmoothTriangle(*this); }
        std::vector<Intersection> local_intersect(const Ray&) const override;
    public:
        SmoothTriangle();
        SmoothTriangle(const Point& p1, const Point& p2, const Point& p3, const Vector& n1, const Vector& n2, const Vector& n3);
        SmoothTriangle(const SmoothTriangle& s);
        SmoothTriangle& operator= (const SmoothTriangle& s);
        ~SmoothTriangle();
        
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point, const Intersection& hit) const override;

        void set_invTransform() override;

        inline std::string type_to_str() const override {return "Smooth Triangle";}
};
} // namespace rtm


#endif