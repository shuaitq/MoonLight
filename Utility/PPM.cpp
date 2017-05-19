#include "PPM.hpp"

namespace MoonLight
{
    void PPM::Save(const std::string &path, const int width, const int height, const RGB_T<float> *ppm)
    {
        std::ofstream in(path);
        if(!in.is_open())
        {
            throw std::runtime_error("Can't open file " + path);
        }
        in << "P3" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
        for(int i = 0; i < height * width; ++ i)
        {
            in << (int)(ppm[i].red * 255) << ' ' << (int)(ppm[i].green * 255) << ' ' << (int)(ppm[i].blue * 255) << ' ';
        }
        in.close();
    }
}