#ifndef MOONLIGHT_WORLD_HPP_
#define MOONLIGHT_WORLD_HPP_

#include "../Camera/Camera.hpp"
#include "../ImageFormat/ImageFormat.hpp"
#include "../Tracer/Tracer.hpp"
#include "../Object/Object.hpp"
#include "../ToneMapping/ToneMapping.hpp"
#include "../Sampler/Sampler.hpp"

#include <vector>

namespace MoonLight
{
    class World
    {
    public:
        Camera camera;
        ImageFormat image_format;
        Tracer tracer;
        std::vector<Object> objects;
        std::vector<ToneMapping> tone_mapping;
        Sampler sampler;

        void Render();

        static World& Get();
    private:
        World() = default;
        ~World() = default;
        World(const World &) = default;
        World& operator = (const World &) = default;
    };
}

#endif // MOONLIGHT_WORLD_HPP_