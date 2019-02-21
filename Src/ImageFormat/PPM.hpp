#ifndef MOONLIGHT_PPM_HPP_
#define MOONLIGHT_PPM_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <functional>
#include <vector>

namespace MoonLight
{
    std::function<void(const std::string &, const size_t width, const size_t height, const std::vector<RGB_T<double>> &)> PPM();
}

#endif // MOONLIGHT_PPM_HPP_