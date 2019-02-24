#include "Core/World.hpp"
#include "ToneMapping/ACESMapping.hpp"
#include "ToneMapping/GammaCorrection.hpp"
#include "ToneMapping/Standardization.hpp"
#include "BRDF/Glossy.hpp"
#include "BRDF/Diffuse.hpp"
#include "BRDF/Specular.hpp"
#include "Object/Sphere.hpp"
#include "Material/Matte.hpp"
#include "Material/Mirror.hpp"
#include "Material/Glass.hpp"
#include "ImageFormat/PPM.hpp"
#include "Camera/PerspectiveCamera.hpp"
#include "Camera/FisheyeCamera.hpp"
#include "Sampler/Jittered.hpp"
#include "Tracer/Whitted.hpp"

#include <cmath>

using namespace MoonLight;

const int width = 500, height = 500, samples = 5;

int main(int argc, char *argv[])
{
    auto &w = World::Get();
    auto &tone_mapping = w.tone_mapping;
    tone_mapping.push_back(ACESMapping());
    tone_mapping.push_back(GammaCorrection(2.2));
    tone_mapping.push_back(Standardization(0.0, 1.0));

    auto specular = Specular();
    //auto glossy = Glossy(1000);
    auto diffuse = Diffuse();

    auto &objects = w.objects;
    objects.push_back(Sphere(Matte(RGB_T<double>(1, 1, 1), RGB_T<double>(11, 11, 11), diffuse), Vector3D_T<double>(0, 1, 0.5), 0.2));
    objects.push_back(Sphere(Glass(RGB_T<double>(1, 1, 1), RGB_T<double>(0, 0, 0), specular, 1.5), Vector3D_T<double>(0.5, -0.7, 0.4), 0.3));
    objects.push_back(Sphere(Mirror(RGB_T<double>(1, 1, 1), RGB_T<double>(0, 0, 0), specular), Vector3D_T<double>(-0.5, -0.7, 0.6), 0.3));

    objects.push_back(Sphere(Matte(RGB_T<double>(0.75, 0.75, 0.75), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(0, -1001, 0), 1000));
    objects.push_back(Sphere(Matte(RGB_T<double>(0.75, 0.75, 0.75), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(0, +1001, 0), 1000));
    objects.push_back(Sphere(Matte(RGB_T<double>(0.25, 0.25, 0.75), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(-1001, 0, 0), 1000));
    objects.push_back(Sphere(Matte(RGB_T<double>(0.75, 0.25, 0.25), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(+1001, 0, 0), 1000));
    objects.push_back(Sphere(Matte(RGB_T<double>(0.75, 0.75, 0.75), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(0, 0, +1001.5), 1000));
    objects.push_back(Sphere(Matte(RGB_T<double>(0.75, 0.75, 0.75), RGB_T<double>(0, 0, 0), diffuse), Vector3D_T<double>(0, 0, -1003), 1000));

    w.image_format = PPM();

    w.camera = PerspectiveCamera(Vector3D_T<double>(0, 0, -1), Vector3D_T<double>(0, 0, 1), Vector3D_T<double>(0, 1, 0), Vector3D_T<double>(-1, 0, 0), (double)width / height, 0.5 * M_PI);

    w.sampler = Jittered(samples);

    w.tracer = Whitted(5, 1000.0);

    w.Render();

    return 0;
}