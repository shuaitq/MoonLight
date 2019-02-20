#ifndef MOONLIGHT_BRDF_HPP_
#define MOONLIGHT_BRDF_HPP_

#include "../Core/Ray.hpp"
#include "../Math/Vector.hpp"

namespace MoonLight
{
    class BRDF
    {
    public:
        virtual Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &direction) const = 0;
    };
}

#endif // MOONLIGHT_BRDF_HPP_