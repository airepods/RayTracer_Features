#include "worldScene/scene.h"
#include <assert.h>
#include <iostream>
#include <math.h>
#include "canvas/canvas.h"
#include "lighting/light.h"
#include "geometry/ray.h"
#include "mat_entities/color.h"
#include "progress_bar/progressbar.hpp"

using namespace rtm;

Scene* Scene::sInstance = nullptr;

// Scene is a singleton, it only 
// can be instantiated once
Scene::Scene()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

Canvas Scene::Render(const Camera& camera, const World& world)
{
    auto canvas = Canvas(camera.get_hsize(), camera.get_vsize());
    
    std::cout<<"Rendering..."<<"\n";
    progressbar bar(camera.get_vsize()-1);

    // hsize and vsize are expressed in pixels (canvas space)
    for(int y=0; y<camera.get_vsize()-1; ++y)
    {
        for(int x=0; x<camera.get_hsize()-1; ++x)
        {
            auto ray = camera.ray_for_pixel(x, y);
            auto color = color_at(world, ray);
            canvas.write_pixel(x, y, color);
        }

        // progress bar
        bar.update();
    }

    return canvas;
}