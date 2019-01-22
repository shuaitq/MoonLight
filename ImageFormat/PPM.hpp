#ifndef MOONLIGHT_PPM_HPP_
#define MOONLIGHT_PPM_HPP_

#include "../Core/Color.hpp"
#include "ImageFormat.hpp"

#include <string>
#include <fstream>
#include <stdexcept>

namespace MoonLight
{
    template <typename T>
    class PPM : public ImageFormat<T>
    {
    public:
        void Save(const std::string &path, const int width, const int height, const RGB_T<T> *pixels)
        {
            std::ofstream in(path);
            if(!in.is_open())
            {
                throw std::runtime_error("Can't open file " + path);
            }
            in << "P3" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
            for(int i = 0; i < height * width; ++ i)
            {
                in << (int)(pixels[i].red * 255) << ' ' << (int)(pixels[i].green * 255) << ' ' << (int)(pixels[i].blue * 255) << ' ';
            }
            in.close();
        }
    };
}

#endif //MOONLIGHT_PPM_HPP_