#ifndef MOONLIGHT_ACES_MAPPING_HPP_
#define MOONLIGHT_ACES_MAPPING_HPP_

#include "ToneMapping.hpp"

namespace MoonLight
{
    template <typename T>
    class ACESMapping : public ToneMapping<T>
    {
    public:
        void Mapping(const int width, const int height, RGB_T<T> *pixels)
        {
            auto ACES = [](T x){ return (x*(2.51f*x+0.03f))/(x*(2.43f*x+0.59f)+0.14f); };

            for(int i = 0; i < width * height; ++ i)
            {
                pixels[i].red = ACES(pixels[i].red);
                pixels[i].green = ACES(pixels[i].green);
                pixels[i].blue = ACES(pixels[i].blue);
            }
        }
    };
}

#endif // MOONLIGHT_ACES_MAPPING_HPP_