#ifndef MOONLIGHT_IMAGE_FORMAT_HPP_
#define MOONLIGHT_IMAGE_FORMAT_HPP_

#include "../Core/Color.hpp"

#include <string>

namespace MoonLight
{
    template <typename T>
    class ImageFormat
    {
    public:
        virtual void Save(const std::string &path, const int width, const int height, const RGB_T<T> *pixels) = 0;
    };
}

#endif // MOONLIGHT_IMAGE_FORMAT_HPP_