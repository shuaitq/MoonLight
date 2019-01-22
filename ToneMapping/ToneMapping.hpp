#ifndef MOONLIGHT_TONE_MAPPING_HPP_
#define MOONLIGHT_TONE_MAPPING_HPP_

#include "../Core/Color.hpp"

namespace MoonLight
{
    template <typename T>
    class ToneMapping
    {
    public:
        virtual void Mapping(const int width, const int height, RGB_T<T> *pixels) = 0;
    };
}

#endif //MOONLIGHT_TONE_MAPPING_HPP_