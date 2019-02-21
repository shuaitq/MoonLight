#ifndef MOONLIGHT_IMAGE_FORMAT_HPP_
#define MOONLIGHT_IMAGE_FORMAT_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <vector>
#include <functional>

namespace MoonLight
{
    using ImageFormat = std::function<void(const std::string &, const size_t width, const size_t height, const std::vector<RGB_T<double>> &)>;
}

#endif // MOONLIGHT_IMAGE_FORMAT_HPP_