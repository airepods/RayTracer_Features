#include "parser/parser.h"
#include "util/utils.h"
#include "primitives/smoothTriangle.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <array>

using namespace rtm;

Parser::Parser(const std::string& obj_filename)
{
    // initialize private members
    vertices = {};

    std::ifstream infile(obj_filename);
    if(infile.is_open())
    {
        // line
        std::string line;
        // command
        std::string command;
        // vertices
        double x, y, z;
        // vertex normals
        double vn1, vn2, vn3;
        // check if there are normals
        bool normals_defined = false;  
        
        Triangle t;

        while(std::getline(infile, line))
        {
            // line is empty
            if(line.size() == 1) { continue; }

            std::stringstream iss(line);
            iss >> command;

            if(command == "v")
            {
                iss >> x >> y >> z;
                vertices.push_back(Point(x, y, z));
                continue;
            }

            if(command == "vn")
            {
                iss >> vn1 >> vn2 >> vn3;
                normals.push_back(Vector(vn1, vn2, vn3));
                normals_defined = true;
                continue;
            }

            if(command == "f")
            {
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
                    // indices
                    std::string id1, id2, id3;
                    // read three vertices
                    iss >> id1 >> id2 >> id3;
                        
                    std::array<std::string, 3> parts = {id1, id2, id3};

                    std::array<int, 3> face_indices;
                    std::array<int, 3> texture_indices;
                    std::array<int, 3> normal_indices;
                    for(int i = 0; i < 3; ++i)
                    {
                        auto subParts = splitString(parts[i], '/');
                        try
                        {
                            if(!normals_defined) 
                            {
                                face_indices[i] = std::stoi(subParts[0])-1;
                                continue;
                            }
                            face_indices[i] = std::stoi(subParts[0])-1;
                            texture_indices[i] = std::stoi(subParts[1])-1;
                            normal_indices[i] = std::stoi(subParts[2])-1;
                        }
                        catch(const std::exception& e)
                        {}
                    }
                    
                    if(!normals_defined)
                        Triangle t(vertices[face_indices[0]], vertices[face_indices[1]], vertices[face_indices[2]]);
                    else
                        SmoothTriangle(
                            vertices[face_indices[0]], 
                            vertices[face_indices[1]], 
                            vertices[face_indices[2]], 
                            normals[normal_indices[0]],
                            normals[normal_indices[1]],
                            normals[normal_indices[2]]);

                    default_group.add_child(t);
                }
                continue;
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