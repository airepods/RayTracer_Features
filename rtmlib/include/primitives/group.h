#ifndef GROUP_H    
#define GROUP_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <map>

namespace rtm
{
class Group : public Surface
{
    protected:
        std::vector<Intersection> local_intersect(const Ray&) const override;
        inline virtual Group* clone_impl() const override { return new Group(*this); }
    private:
        std::vector<std::unique_ptr<Surface>> m_children;
    public:
        // exception class
        class calling_normal_on_group
        {
        };

        Group();
        Group(const Group& other_group);
        Group(Group && other_group) = default;
        Group& operator= (const Group& other_group);
        Group& operator= (Group && other_group) = default;
        ~Group();

        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        inline std::string type_to_str() const override {return "Group";} 

        template<class T>
        void add_child(const T& shape)
        {
            //auto s = new T(shape);
            std::unique_ptr<T> s = std::make_unique<T>(shape);
            s->set_parent(this);
            m_children.push_back(std::move(s));
        }

        void add_child(const Group& shape)
        {
            std::unique_ptr<Group> s = std::make_unique<Group>(shape);
            s->set_parent(this); 

            // make the inmediately below children point to their new parent address
            for (auto &&child : s->m_children)
            {
                child->set_parent(s.get());
            }
            m_children.push_back(std::move(s));
        }

};
} // namespace rtm


#endif