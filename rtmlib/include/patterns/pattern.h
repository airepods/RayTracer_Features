#ifndef PATTERN_H    
#define PATTERN_H

#include "mat_entities/color.h"
#include "mat_entities/point.h"
#include "mat_entities/matrix_utility.h"
#include "mat_entities/tuple_utility.h"

namespace rtm
{
class Surface;

class Pattern
{
    protected:
        //bool m_exists = false;
        Color m_a;
        Color m_b;
        Matrix m_transform;
        Pattern* m_pattern_a;
        Pattern* m_pattern_b;

        Pattern(const Color& color);
        inline bool patterns_are_defined() const {return m_pattern_a != nullptr && m_pattern_b != nullptr ? true : false;}
    public:
        Pattern();
        Pattern(const Color& a, const Color& b);
        Pattern(Pattern* a, Pattern* b);

        virtual Color pattern_at(const Point& point) const = 0;
        Color pattern_at_object(const Surface* object, const Point& point) const;
        Color pattern_at_object(const Point& point) const;

        // inline bool exists() const {return m_exists;}
        // inline void set_true() {m_exists = true;}
        inline void set_transform(const Matrix& transform) {m_transform = transform;}
};
} // namespace rtm

#endif