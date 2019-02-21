#ifndef MOONLIGHT_TONE_MAPPING_HPP_
#define MOONLIGHT_TONE_MAPPING_HPP_

#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    using ToneMapping = std::function<void(RGB_T<double> &)>;
}

#endif //MOONLIGHT_TONE_MAPPING_HPP_