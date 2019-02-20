#ifndef MOONLIGHT_IMAGE_FORMAT_HPP_
#define MOONLIGHT_IMAGE_FORMAT_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <vector>

namespace MoonLight
{
    class ImageFormat
    {
    public:
        virtual void Save(const std::string &path, const int width, const int height, const std::vector<RGB_T<double>> &pixels) const = 0;
    };
}

#endif // MOONLIGHT_IMAGE_FORMAT_HPP_