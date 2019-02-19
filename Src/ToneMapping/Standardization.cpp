#include "Standardization.hpp"

#include <cmath>

namespace MoonLight
{
    Standardization::Standardization(double l, double h):low(l), high(h){}

    void Standardization::Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels)
    {
        auto f = [&](double x){ return std::min(std::max(x, low), high); };

        for(int i = 0; i < width * height; ++ i)
        {
            pixels[i].red = f(pixels[i].red);
            pixels[i].green = f(pixels[i].green);
            pixels[i].blue = f(pixels[i].blue);
        }
    }
}