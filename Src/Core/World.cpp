#include "World.hpp"

namespace MoonLight
{
    void World::Render()
    {
        const int width = 500, height = 500, num_set = 2000, samples = 5;
        
        std::vector<RGB_T<double>> screen, back;
        screen.resize(width * height);
        back.resize(width * height);

        std::array<Vector2D_T<double>, samples * samples> s;

        for(auto &p : s)
        {
            sampler(p);
        }

        for(int set = 0; set < num_set; ++ set)
        {
            printf("set %d\n", set);
            for(int x = 0; x < height; ++ x)
            {
                printf("%d\n", x);
                for(int y = 0; y < width; ++ y)
                {
                    RGB_T<double> color;

                    for(const auto &p : s)
                    {
                        color += tracer(camera(((x + p.x) / height * 2) - 1, ((y + p.y) / width * 2) - 1), 0);
                    }
                    
                    screen[x * width + y] = screen[x * width + y] * set / (set + 1) + color / (set + 1) / samples / samples;
                }
            }

            for(int i = 0; i < height; ++ i)
            {
                for(int j = 0; j < width; ++ j)
                {
                    back[i * width + j] = screen[i * width + j];
                }
            }

            for(auto &p : back)
            {
                for(const auto &mapping : tone_mapping)
                {
                    mapping(p);
                }
            }

            image_format("test.ppm", width, height, back);
        }
    }

    World& World::Get()
    {
        static World world;
        
        return world;
    }
}