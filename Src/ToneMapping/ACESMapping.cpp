#include "ACESMapping.hpp"

#include <algorithm>

namespace MoonLight
{
    ToneMapping ACESMapping()
    {
        return [](RGB_T<double> &rgb)
        {
            std::for_each(std::begin(rgb.color), std::end(rgb.color), [](double &x)
            {
                x = (x * (2.51 * x + 0.03)) / (x * (2.43 * x + 0.59) + 0.14);
            });
        };
    }
}