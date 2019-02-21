#include "GammaCorrection.hpp"

#include <cmath>
#include <algorithm>

namespace MoonLight
{
    ToneMapping GammaCorrection(double gamma)
    {
        return [=](RGB_T<double> &rgb)
        {
            std::for_each(std::begin(rgb.color), std::end(rgb.color), [=](double &x)
            {
                x = pow(x, 1 / gamma);
            });
        };
    }
}