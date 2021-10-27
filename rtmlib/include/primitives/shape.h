#ifndef SHAPE_H    
#define SHAPE_H

#include <string> 

class Shape
{
public:
    inline virtual std::string type_to_str() {return "Shape";}
    inline virtual Shape* get_object_type() {return this;};
};

#endif