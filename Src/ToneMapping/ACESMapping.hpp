#ifndef MOONLIGHT_ACES_MAPPING_HPP_
#define MOONLIGHT_ACES_MAPPING_HPP_

#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    std::function<void(RGB_T<double> &)> ACESMapping();
}

#endif // MOONLIGHT_ACES_MAPPING_HPP_