#ifndef MOONLIGHT_ACES_MAPPING_HPP_
#define MOONLIGHT_ACES_MAPPING_HPP_

#include "ToneMapping.hpp"

namespace MoonLight
{
    class ACESMapping : public ToneMapping
    {
    public:
        void Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels);
    };
}

#endif // MOONLIGHT_ACES_MAPPING_HPP_