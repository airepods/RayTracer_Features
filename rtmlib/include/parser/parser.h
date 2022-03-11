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
        Group default_group;
        Parser(const std::string& obj_filename);
    private:
        std::vector<Triangle> fan_triangulation();
};
};

#endif