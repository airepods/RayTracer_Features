#ifndef CUBE_H    
#define CUBE_H

#include <string>
#include "primitives/shape.h"

class Cube : public Shape
{
public:
    Cube()
    {}

    inline std::string type_to_str() override {return "Cube";}
    inline Cube* get_object_type() override {return this;}
};

#endif