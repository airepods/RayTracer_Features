#include "primitives/triangleMesh.h"

using namespace rtm;

TriangleMesh::TriangleMesh() : Surface()
{}

TriangleMesh::TriangleMesh(
    const int& vertexCount, 
    const Point* vertices, 
    const int& triangleCount, 
    const unsigned short* triIndex) :
    m_vertexCount(vertexCount), m_triangleCount(triangleCount)

{
    m_vertexList = std::unique_ptr<Point []>(new Point[vertexCount]);
    for(int i = 0; i < vertexCount; ++i)
    {
        m_vertexList[i] = vertices[i];
    }

    m_triList = std::unique_ptr<unsigned short []>(new unsigned short[triangleCount * 3]);
    unsigned int l = 0;
    for(int i = 0; i < triangleCount; ++i)
    {
        m_triList[l]     = triIndex[l];
        m_triList[l + 1] = triIndex[l + 1];
        m_triList[l + 2] = triIndex[l + 2];
        l+=3;
    }
}

TriangleMesh::TriangleMesh(const TriangleMesh& s) : Surface(s)
{
}

TriangleMesh& TriangleMesh::operator= (const TriangleMesh& s)
{

    return *this;
}


TriangleMesh::~TriangleMesh()
{   
    //std::cout<<"Group destructor"<<"\n";
}

std::vector<Intersection> TriangleMesh::local_intersect(const Ray& ray) const
{
    std::vector<Intersection> intersections = {};
    return intersections;
}

std::vector<Intersection> TriangleMesh::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inv_transform);

    return local_intersect(ray);
}

Vector TriangleMesh::normal_at(const Point& world_point) const
{
    throw TriangleMesh::calling_normal_on_mesh();
}

void TriangleMesh::set_invTransform()
{
    inv_transform = inverse(m_transform);    
}