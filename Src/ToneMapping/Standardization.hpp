#ifndef MOONLIGHT_STANDARDIZATION_HPP_
#define MOONLIGHT_STANDARDIZATION_HPP_

#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    std::function<void(RGB_T<double> &)> Standardization(double low, double high);
}

#endif // MOONLIGHT_STANDARDIZATION_HPP_