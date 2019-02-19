#ifndef MOONLIGHT_PPM_HPP_
#define MOONLIGHT_PPM_HPP_

#include "ImageFormat.hpp"

#include <fstream>
#include <stdexcept>

namespace MoonLight
{
    class PPM : public ImageFormat
    {
    public:
        void Save(const std::string &path, const int width, const int height, const std::vector<RGB_T<double>> &pixels);
    };
}

#endif //MOONLIGHT_PPM_HPP_