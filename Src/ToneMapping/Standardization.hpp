#ifndef MOONLIGHT_STANDARDIZATION_HPP_
#define MOONLIGHT_STANDARDIZATION_HPP_

#include "ToneMapping.hpp"

#include <cmath>

namespace MoonLight
{
    template <typename T>
    class Standardization : public ToneMapping<T>
    {
    public:
        Standardization(T l, T h):low(l), high(h){}
        void Mapping(const int width, const int height, RGB_T<T> *pixels)
        {
            for(int i = 0; i < width * height; ++ i)
            {
                pixels[i].red = std::min(std::max(pixels[i].red, low), high);
                pixels[i].green = std::min(std::max(pixels[i].green, low), high);
                pixels[i].blue = std::min(std::max(pixels[i].blue, low), high);
            }
        }
    
    private:
        T low, high;
    };
}

#endif // MOONLIGHT_STANDARDIZATION_HPP_