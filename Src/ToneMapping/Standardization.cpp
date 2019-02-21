#include "Standardization.hpp"

#include <algorithm>

namespace MoonLight
{
    ToneMapping Standardization(double low, double high)
    {
        return [=](RGB_T<double> &rgb)
        {
            std::for_each(std::begin(rgb.color), std::end(rgb.color), [=](double &x)
            {
                x = std::min(std::max(x, low), high);
            });
        };
    }
}