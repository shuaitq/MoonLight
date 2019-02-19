#ifndef MOONLIGHT_GAMMA_CORRECTION_HPP_
#define MOONLIGHT_GAMMA_CORRECTION_HPP_

#include "ToneMapping.hpp"

namespace MoonLight
{
    class GammaCorrection : public ToneMapping
    {
    public:
        GammaCorrection(double g);
        void Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels);

    private:
        double gamma;
    };
}

#endif // MOONLIGHT_GAMMA_CORRECTION_HPP_