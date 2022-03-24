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
                    // indices
                    std::string id;
                    // vector of parts of a face
                    std::vector<std::string> parts = {};
                    // read the indices
                    while(iss >> id)
                    {
                        parts.push_back(id);
                    }
                    
                    std::vector<int> face_indices(parts.size());
                    std::vector<int> texture_indices(parts.size());
                    std::vector<int> normal_indices(parts.size());
                    for(int i=0; i<parts.size(); ++i)
                    {
                        auto subParts = splitString(parts[i], '/');

                        if(!normals_defined) 
                        {
                            face_indices[i] = std::stoi(subParts[0])-1;
                            continue;
                        } 
                        face_indices[i]     =   (subParts[0] == " " || subParts[0] == "") ? -1 : std::stoi(subParts[0])-1;
                        texture_indices[i]  =   (subParts[1] == " " || subParts[1] == "") ? -1 : std::stoi(subParts[1])-1;
                        normal_indices[i]   =   (subParts[2] == " " || subParts[2] == "") ? -1 : std::stoi(subParts[2])-1;
                    }

                    // it's a polygon, starts triangulation 
                    // if normals are not defined inside the obj file then use flat shading
                    if(!normals_defined)
                    {
                        for (const auto& triangle : fan_triangulation(face_indices)) 
                        { 
                            default_group.add_child(triangle); 
                        }
                    }
                    // if normals are defined inside the file then use vertex shading
                    else 
                    {
                        for (const auto& triangle : fan_triangulation(face_indices, normal_indices)) 
                        { 
                            default_group.add_child(triangle); 
                        }
                    }
                    
                }
                else
                {
                    // indices
                    std::string id1, id2, id3;
                    // read three indices
                    iss >> id1 >> id2 >> id3;
                        
                    std::array<std::string, 3> parts = {id1, id2, id3};

                    std::array<int, 3> face_indices;
                    std::array<int, 3> texture_indices;
                    std::array<int, 3> normal_indices;
                    for(int i = 0; i < 3; ++i)
                    {
                        auto subParts = splitString(parts[i], '/');

                        if(!normals_defined) 
                        {
                            face_indices[i] = std::stoi(subParts[0])-1;
                            continue;
                        } 
                        face_indices[i]     =   (subParts[0] == " " || subParts[0] == "") ? -1 : std::stoi(subParts[0])-1;
                        texture_indices[i]  =   (subParts[1] == " " || subParts[1] == "") ? -1 : std::stoi(subParts[1])-1;
                        normal_indices[i]   =   (subParts[2] == " " || subParts[2] == "") ? -1 : std::stoi(subParts[2])-1;
                    }
                    
                    Triangle t;
                    SmoothTriangle st;

                    if(!normals_defined)
                    {
                        t = Triangle(vertices[face_indices[0]], vertices[face_indices[1]], vertices[face_indices[2]]);
                        default_group.add_child(t);
                    }
                        
                    else
                    {
                        st = SmoothTriangle(
                            vertices[face_indices[0]], 
                            vertices[face_indices[1]], 
                            vertices[face_indices[2]], 
                            normals[normal_indices[0]],
                            normals[normal_indices[1]],
                            normals[normal_indices[2]]);
                            
                        default_group.add_child(st);
                    }
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

std::vector<Triangle> Parser::fan_triangulation(const std::vector<int>& face_list)
{
    std::vector<Triangle> triangles = {};
    for(int i = 1; i <= face_list.size() - 2; ++i)
    {
        Triangle t(vertices.at(face_list.at(0)), vertices.at(face_list.at(i)), vertices.at(face_list.at(i+1)));
        triangles.push_back(t);
    }
    return triangles;
}

std::vector<SmoothTriangle> Parser::fan_triangulation(const std::vector<int>& face_list, const std::vector<int>& normal_list)
{
    std::vector<SmoothTriangle> triangles = {};
    for(int i = 1; i <= face_list.size() - 2; ++i)
    {
        SmoothTriangle st(
            vertices.at(face_list.at(0)), 
            vertices.at(face_list.at(i)), 
            vertices.at(face_list.at(i+1)),
            normals.at(normal_list.at(0)),
            normals.at(normal_list.at(i)),
            normals.at(normal_list.at(i+1)) 
            );
        triangles.push_back(st);
    }
    return triangles;
}