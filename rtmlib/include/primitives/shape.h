#ifndef SHAPE_H    
#define SHAPE_H

#include <string> 
#include "mat_entities/matrix.h"

namespace rtm
{
class Shape
{
public:
    virtual std::string type_to_str() const = 0;
    virtual Shape* get_object_type() = 0;
    virtual Matrix get_transform() const = 0;
    virtual void transform(const Matrix&) = 0;
};
} // namespace rtm

#endif