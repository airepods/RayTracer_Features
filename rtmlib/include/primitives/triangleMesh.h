#ifndef TRIANGLEMESH_H    
#define TRIANGLEMESH_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>
#include <array>
#include <memory>
#include <utility>
#include <map>

namespace rtm
{
class TriangleMesh : public Surface
{
    private:
        int m_vertexCount;
        std::unique_ptr<Point []> m_vertexList;
        int m_triangleCount;
        std::unique_ptr<unsigned short []> m_triList;

    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual TriangleMesh* clone_impl() const override { return new TriangleMesh(*this); }
    public:
        // exception class
        class calling_normal_on_mesh
        {
        };

        TriangleMesh();
        TriangleMesh(const int& vertexCount, const Point* vertices, const int& triangleCount, const unsigned short* triList);
        TriangleMesh(const TriangleMesh& other_tmesh);
        TriangleMesh(TriangleMesh && other_tmesh) = default;
        TriangleMesh& operator= (const TriangleMesh& other_tmesh);
        TriangleMesh& operator= (TriangleMesh && other_tmesh) = default;
        ~TriangleMesh();

        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        void set_invTransform() override;

        inline std::string type_to_str() const override {return "Triangle Mesh";} 
};
} // namespace rtm


#endif