#ifndef MOONLIGHT_PPM_HPP_
#define MOONLIGHT_PPM_HPP_

#include "../Core/Color.hpp"

#include <string>
#include <fstream>
#include <stdexcept>

namespace MoonLight
{
    class PPM
    {
    public:
        static void Save(const std::string &path, const int width, const int height, const RGB_T<float> *ppm);
    private:
    };
}

#endif //MOONLIGHT_PPM_HPP_
