#ifndef MOONLIGHT_OBJECT_FILE_HPP_
#define MOONLIGHT_OBJECT_FILE_HPP_

#include "../Math/Vector.hpp"
#include "../Object/Triangle.hpp"
#include "../Material/Glass.hpp"
#include "../BRDF/Glossy.hpp"
#include "../Tracer/Tracer.hpp"

#include <vector>

namespace MoonLight
{
    template <typename T>
    class ObjectFile
    {
    public:
        static void Load(const std::string &path)
        {
            std::ifstream in(path);
            if(!in.is_open())
            {
                throw std::runtime_error("Object " + path + " doesn't exist!");
            }
            std::string str;
            T x, y, z;
            std::vector<Vector3D_T<T>> PointList;
            while(in >> str)
            {
                switch(str[0])
                {
                    case 'v':
                        in >> x >> y >> z;
                        PointList.push_back(Vector3D_T<T>(x, y, z));
                        break;
                    case 'f':
                        int a, b, c;
                        in >> a >> b >> c;
                        objects.push_back(std::make_shared<Triangle<T>>(std::make_shared<Glass<T>>(RGB_T<T>(1, 1, 1), RGB_T<T>(0, 0, 0), std::make_shared<Glossy<T>>(10000), 2.40), PointList[a - 1], PointList[b - 1], PointList[c - 1]));
                        break;
                    default:
                        throw std::runtime_error("Error! Unexpect Value!" + str);
                        break;
                }
            }
            in.close();
        }
    };
}

#endif // MOONLIGHT_OBJECT_FILE_HPP_