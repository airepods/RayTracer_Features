#ifndef MATERIAL_H    
#define MATERIAL_H

#include "patterns/pattern.h"

namespace rtm
{
    class Material
    {
        private:
            Color m_color;
            float m_ambient;
            float m_diffuse;
            float m_specular;
            float m_shininess;
            float m_reflective;
            Pattern* m_pattern;

        public:
            Material();

            inline Color get_color() const {return m_color;}
            inline float get_ambient() const {return m_ambient;}
            inline float get_diffuse() const {return m_diffuse;}
            inline float get_specular() const {return m_specular;}
            inline float get_shininess() const {return m_shininess;}
            inline float get_reflective() const {return m_reflective;}
            inline Pattern* get_pattern() const {return m_pattern;}

            inline void set_color(const Color& color) {m_color = color;}
            inline void set_ambient(const float& ambient) {m_ambient = ambient;}
            inline void set_diffuse(const float& diffuse) {m_diffuse = diffuse;}
            inline void set_specular(const float& specular) {m_specular = specular;}
            inline void set_shininess(const float& shininess) {m_shininess = shininess;}
            inline void set_reflective(const float& reflective) {m_reflective = reflective;}
            inline void set_pattern(Pattern* pattern) {m_pattern = pattern;}
    };
}

#endif