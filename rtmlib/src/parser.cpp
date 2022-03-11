#include "parser/parser.h"

#include "primitives/triangle.h" 

#include <fstream>
#include <iostream>
#include <sstream>

using namespace rtm;

Parser::Parser(const std::string& obj_filename)
{
    // initialize private members
    vertices = {};

    std::ifstream infile(obj_filename);
    if(infile.is_open())
    {
        std::string line;
        char command;
        int index;
        double x, y, z;
        
        std::vector<int> indices = {}; 
        std::vector<Point> points = {};
        Triangle t;

        while(std::getline(infile, line))
        {
            if(line.size() == 1) { continue; }

            std::stringstream iss(line);
            iss >> command;

            switch (command)
            {
            case 'v':
                iss >> x >> y >> z;
                vertices.push_back(Point(x, y, z));
                break;
            
            case 'f':
                indices.clear(); 
                while(iss >> index)
                {   
                    indices.push_back(index-1);
                }

                points.clear();
                for (auto &&i : indices)
                {
                    points.push_back(vertices.at(i));
                }
                
                t = Triangle(points.at(0), points.at(1), points.at(2));
                default_group.add_child(t);
                break;
            
            default:
                break;
            }
        }
        infile.close();
    }
    else
    {
        std::cout<<"File cannot be opened"<<"\n";
    }
}