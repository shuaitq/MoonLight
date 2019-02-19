#include "GammaCorrection.hpp"

#include <cmath>

namespace MoonLight
{
    GammaCorrection::GammaCorrection(double g):gamma(g){}

    void GammaCorrection::Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels)
    {
        auto f = [&](double x){ return pow(x, 1 / gamma); };

        for(int i = 0; i < width * height; ++ i)
        {
            pixels[i].red = f(pixels[i].red);
            pixels[i].green = f(pixels[i].green);
            pixels[i].blue = f(pixels[i].blue);
        }
    }
}