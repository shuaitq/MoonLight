#include "Specular.hpp"

namespace MoonLight
{
    BRDF Specular()
    {
        return [=](const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &direction)
        {
            return Ray<double>(position, direction);
        };
    }
}