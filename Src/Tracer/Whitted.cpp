#include "Whitted.hpp"

#include "../Core/World.hpp"

namespace MoonLight
{
    Tracer Whitted(const size_t max_depth, const double max_t)
    {
        return [=](const Ray<double> &ray, const size_t depth)
        {
            RGB_T<double> ret;

            if(depth <= max_depth)
            {
                std::tuple<double, Vector3D_T<double>, Vector3D_T<double>, Vector3D_T<double>, Material> t;
                std::get<0>(t) = max_t;

                for(const auto &o : World::Get().objects)
                {
                    auto temp = o(ray);

                    if(std::get<0>(temp) < std::get<0>(t) && std::get<0>(temp) >= 1e-5)
                    {
                        t = temp;
                    }
                }

                if(std::get<0>(t) != max_t)
                {
                    ret = std::get<4>(t)(std::get<1>(t), std::get<2>(t), std::get<3>(t), depth + 1);
                }
            }

            return ret;
        };
    }
}