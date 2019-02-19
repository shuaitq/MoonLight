#ifndef MOONLIGHT_STANDARDIZATION_HPP_
#define MOONLIGHT_STANDARDIZATION_HPP_

#include "ToneMapping.hpp"

namespace MoonLight
{
    class Standardization : public ToneMapping
    {
    public:
        Standardization(double l, double h);
        void Mapping(const int width, const int height, std::vector<RGB_T<double>> &pixels);

    private:
        double low, high;
    };
}

#endif // MOONLIGHT_STANDARDIZATION_HPP_