#ifndef MOONLIGHT_TONE_MAPPING_HPP_
#define MOONLIGHT_TONE_MAPPING_HPP_

#include "../Core/Color.hpp"

#include <vector>

namespace MoonLight
{
    class ToneMapping
    {
    public:
        virtual void Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels) = 0;
    };
}

#endif //MOONLIGHT_TONE_MAPPING_HPP_