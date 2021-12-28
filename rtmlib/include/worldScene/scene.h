#ifndef SCENE_H    
#define SCENE_H

#include "world.h"
#include "camera.h"
#include "canvas/canvas.h"

namespace rtm
{
class Scene
{
    private:
        static Scene* sInstance;
    public:
        Scene();
        static Canvas Render(const Camera& camera, const World& world);
};
}

#endif