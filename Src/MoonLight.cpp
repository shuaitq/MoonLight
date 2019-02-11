#include "ToneMapping/ACESMapping.hpp"
#include "ToneMapping/GammaCorrection.hpp"
#include "ToneMapping/Standardization.hpp"
#include "Object/Sphere.hpp"
#include "Object/Triangle.hpp"
#include "ImageFormat/PPM.hpp"
#include "Sampler/Jittered.hpp"
#include "Utility/Rand.hpp"
#include "Utility/ObjectFile.hpp"
#include "Camera/PerspectiveCamera.hpp"
#include "Camera/FisheyeCamera.hpp"
#include "Camera/OrthographicCamera.hpp"
#include "Tracer/Tracer.hpp"
#include "Material/Matte.hpp"
#include "Material/Mirror.hpp"
#include "Material/Glass.hpp"
#include "BRDF/Glossy.hpp"
#include "BRDF/Diffuse.hpp"

#include <cmath>
#include <iostream>
#include <vector>
#include <memory>

using namespace MoonLight;

const int width = 500, height = 500, num_set = 2000, samples = 5;

using type = double;

RGB_T<type> screen[width * height], back[width * height];

std::vector<std::shared_ptr<ToneMapping<type>>> tonemapping;
std::shared_ptr<ImageFormat<type>> save = std::make_shared<PPM<type>>();
std::shared_ptr<Sampler<type, samples>> sampler = std::make_shared<Jittered<type, samples>>();
std::shared_ptr<Camera<type>> camera = std::make_shared<PerspectiveCamera<type>>(Vector3D_T<type>(0, 0, -1), Vector3D_T<type>(0, 0, 1), Vector3D_T<type>(0, 1, 0), Vector3D_T<type>(-1, 0, 0), (type)width / height, 0.5 * M_PI);

std::shared_ptr<std::array<Vector2D_T<type>, samples * samples>> points = std::make_shared<std::array<Vector2D_T<type>, samples * samples>>();

int main(int argc, char *argv[])
{
    Rand<type>::init_rand();

    tonemapping.push_back(std::make_shared<ACESMapping<type>>());
    tonemapping.push_back(std::make_shared<GammaCorrection<type>>(2.2));
    tonemapping.push_back(std::make_shared<Standardization<type>>(0, 1));

    std::shared_ptr<BRDF<type>> glossy = std::make_shared<Glossy<type>>(1000);
    std::shared_ptr<BRDF<type>> diffuse = std::make_shared<Diffuse<type>>(1);
    std::shared_ptr<BRDF<type>> reflection = std::make_shared<Glossy<type>>(1000);

    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(1, 1, 1), RGB_T<type>(11, 11, 11), diffuse),0.2, Vector3D_T<type>(0, 1, 0.5)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Glass<type>>(RGB_T<type>(1, 1, 1), RGB_T<type>(0, 0, 0), glossy, 1.5),0.3, Vector3D_T<type>(0.5, -0.7, 0.4)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Mirror<type>>(RGB_T<type>(1, 1, 1), RGB_T<type>(0, 0, 0), reflection),0.3, Vector3D_T<type>(-0.5, -0.7, 0.6)));

    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.75, 0.75, 0.75), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(0, -1001, 0)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.75, 0.75, 0.75), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(0, +1001, 0)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.25, 0.25, 0.75), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(-1001, 0, 0)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.75, 0.25, 0.25), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(+1001, 0, 0)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.75, 0.75, 0.75), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(0, 0, +1001.5)));
    objects.push_back(std::make_shared<Sphere<type>>(std::make_shared<Matte<type>>(RGB_T<type>(0.75, 0.75, 0.75), RGB_T<type>(0, 0, 0), diffuse), 1000, Vector3D_T<type>(0, 0, -1003)));

    for(int set = 0; set < num_set; ++ set)
    {
        printf("set %d\n", set);
        for(int x = 0; x < height; ++ x)
        {
            printf("%d\n", x);
            for(int y = 0; y < width; ++ y)
            {
                sampler->Sampling(points);

                RGB_T<type> color;
                for(int k = 0; k < samples * samples; ++ k)
                {
                    color += Tracer<type>::Trace(camera->GetRay(((x + (*points)[k].x) / height), (y + (*points)[k].y) / width));
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

        for(auto mapping : tonemapping)
        {
            mapping->Mapping(width, height, back);
        }

        save->Save("test.ppm", width, height, back);
    }

    return 0;
}