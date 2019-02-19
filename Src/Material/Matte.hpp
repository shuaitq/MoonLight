#ifndef MOONLIGHT_MATTE_HPP_
#define MOONLIGHT_MATTE_HPP_

#include "Material.hpp"

namespace MoonLight
{
    class Matte : public Material
    {
    public:
        Matte(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b);

        Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident);
    };
}

#endif // MOONLIGHT_MATTE_HPP_