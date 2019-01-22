#ifndef MOONLIGHT_TRACER_HPP_
#define MOONLIGHT_TRACER_HPP_

#include "../Object/Object.hpp"

#include <vector>

namespace MoonLight
{
    extern std::vector<std::shared_ptr<Object<double>>> objects;
 
    template <typename T>
    class Tracer
    {
    public:
        const static int max_depth = 5;

        static RGB_T<T> Trace(const Ray<T> &r, const int depth = 0)
        {
            if(depth > max_depth)
            {
                return RGB_T<T>();
            }

            Vector3D_T<double> position, normal, incident;
            std::shared_ptr<Material<double>> material;
            double tmin = 100000000;
            
            for(auto object : objects)
            {
                object->Hit(r, position, normal, incident, material, tmin);
            }

            if(tmin == 100000000)
            {
                return RGB_T<T>();
            }

            //std::cout << material->GetRay(position, normal, incident) << std::endl;

            return material->Shade(Trace(material->GetRay(position, normal, incident), depth + 1));
        }
    };
}

#endif // MOONLIGHT_TRACER_HPP_