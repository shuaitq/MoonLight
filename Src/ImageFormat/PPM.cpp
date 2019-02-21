#include "PPM.hpp"

#include <fstream>
#include <stdexcept>

namespace MoonLight
{
    ImageFormat PPM()
    {
        return [](const std::string &path, const int width, const int height, const std::vector<RGB_T<double>> &pixels)
        {
            std::ofstream out(path);

            if(!out.is_open())
            {
                throw std::runtime_error("Can't open file " + path);
            }

            out << "P3" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
            for(int i = 0; i < height * width; ++ i)
            {
                out << static_cast<int>(pixels[i].red * 255) << ' ' << static_cast<int>(pixels[i].green * 255) << ' ' << static_cast<int>(pixels[i].blue * 255) << ' ';
            }
            
            out.close();
        };
    }
}