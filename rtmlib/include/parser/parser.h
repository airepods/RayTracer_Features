#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "mat_entities/point.h"
#include "primitives/group.h"
#include "primitives/triangle.h" 

namespace rtm
{
class Parser
{ 
    public:
        std::vector<Point> vertices;
        std::vector<Vector> normals;
        Group default_group;
        Parser(const std::string& obj_filename);
        inline Group obj_to_group() {return default_group;}
    private:
        
        std::vector<Triangle> fan_triangulation();
};
};

#endif