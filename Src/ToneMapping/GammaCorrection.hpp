#ifndef MOONLIGHT_GAMMA_CORRECTION_HPP_
#define MOONLIGHT_GAMMA_CORRECTION_HPP_

#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    std::function<void(RGB_T<double> &)> GammaCorrection(double gamma);
}

#endif // MOONLIGHT_GAMMA_CORRECTION_HPP_