#ifndef MOONLIGHT_SPHERE_HPP_
#define MOONLIGHT_SPHERE_HPP_

#include "Object.hpp"

#include <limits>

namespace MoonLight
{
    Object Sphere(const Material &material, const Vector3D_T<double> &center, const double radius)
    {
        return [=](const Ray<double> &ray)
        {
            double t = std::numeric_limits<double>::max();
            Vector3D_T<double> position, normal;

            Vector3D_T<double> v = ray.origin - center;
            double a0 = v.Length2() - radius * radius;
            double DdotV = Dot(ray.direction, v);

            if(DdotV <= 0)
            {
                double delta = DdotV * DdotV - a0;

                if(delta >= 0)
                {
                    t = -DdotV - sqrt(delta);
                    position = ray.GetPoint(t);
                    normal = Normalize(position - center);
                }
            }

            return std::make_tuple(t, position, normal, ray.direction, material);
        };
    }
}

#endif // MOONLIGHT_SPHERE_HPP_