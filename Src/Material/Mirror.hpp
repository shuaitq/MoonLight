#ifndef MOONLIGHT_MIRROR_HPP_
#define MOONLIGHT_MIRROR_HPP_

#include "Material.hpp"

namespace MoonLight
{
    class Mirror : public Material
    {
    public:
        Mirror(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b);
        Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident);
    };
}

#endif // MOONLIGHT_MIRROR_HPP_