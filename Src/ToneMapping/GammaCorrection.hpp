#ifndef MOONLIGHT_GAMMA_CORRECTION_HPP_
#define MOONLIGHT_GAMMA_CORRECTION_HPP_

#include "ToneMapping.hpp"

#include <cmath>

namespace MoonLight
{
    template <typename T>
    class GammaCorrection : public ToneMapping<T>
    {
    public:
        GammaCorrection(T g):gamma(g){}
        void Mapping(const int width, const int height, RGB_T<T> *pixels)
        {
            auto GammaCorrection = [](T x, T gamma){ return pow(x, 1 / gamma); };

            for(int i = 0; i < width * height; ++ i)
            {
                pixels[i].red = GammaCorrection(pixels[i].red, gamma);
                pixels[i].green = GammaCorrection(pixels[i].green, gamma);
                pixels[i].blue = GammaCorrection(pixels[i].blue, gamma);
            }
        }

    private:
        T gamma;
    };
}

#endif // MOONLIGHT_GAMMA_CORRECTION_HPP_