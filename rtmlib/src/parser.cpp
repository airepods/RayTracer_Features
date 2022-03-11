#include "parser/parser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

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
        double x, y, z;
        int id1, id2, id3;
        std::string group_name;
        
        Triangle t;

        while(std::getline(infile, line))
        {
            auto g = Group();

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
                // count
                if(countWordsInString(line) > 4)
                {
                    // it's a polygon, starts triangulation 
                    for (auto &&triangle : fan_triangulation())
                    {
                        default_group.add_child(triangle);    
                    }
                    
                }
                else
                {
                    // read three vertices
                    iss >> id1 >> id2 >> id3;
                    t = Triangle(vertices.at(id1-1), vertices.at(id2-1), vertices.at(id3-1));
                    
                    // if there is no group
                    if(group_name.empty())
                    {
                        default_group.add_child(t); 
                    }
                    else
                    {   
                        g.add_child(t);
                        default_group.add_child(g);
                    }
                        
                }
                break;
            
            case 'g':
                iss >> group_name;
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

std::vector<Triangle> Parser::fan_triangulation()
{
    std::vector<Triangle> triangles = {};
    for(int i = 1; i < vertices.size() - 1; ++i)
    {
        Triangle t(vertices.at(0), vertices.at(i), vertices.at(i+1));
        triangles.push_back(t);
    }
    return triangles;
}