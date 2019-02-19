#include "ACESMapping.hpp"

namespace MoonLight
{
    void ACESMapping::Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels)
    {
        auto f = [](double x){ return (x * (2.51 * x + 0.03)) / (x * (2.43 * x + 0.59) + 0.14); };

        for(int i = 0; i < width * height; ++ i)
        {
            pixels[i].red = f(pixels[i].red);
            pixels[i].green = f(pixels[i].green);
            pixels[i].blue = f(pixels[i].blue);
        }
    }
}