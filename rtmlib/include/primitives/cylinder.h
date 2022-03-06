#ifndef CYLINDER_H    
#define CYLINDER_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Cylinder : public Surface
{
    private:
        double m_minimum; // y coordinate
        double m_maximum; // y coordinate
        bool m_closed;
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual Cylinder* clone_impl() const override { return new Cylinder(*this); }
    public:
        Cylinder();
        Cylinder(double minimum, double maximum, bool closed = false);
        Cylinder(const Cylinder& s);
        Cylinder& operator= (const Cylinder& s);
        ~Cylinder();
        
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Cylinder";}
    private:
        void intersect_caps(const Ray& r, std::vector<Intersection>& xs) const;
        bool check_cap(const Ray& r, const double& t) const;

};
} // namespace rtm


#endif