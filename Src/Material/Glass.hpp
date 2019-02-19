#ifndef MOONLIGHT_GLASS_HPP_
#define MOONLIGHT_GLASS_HPP_

#include "Material.hpp"

namespace MoonLight
{
    class Glass : public Material
    {
    public:
        Glass(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b, const double ri);
        Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident);

    private:
        double refractive_index;
    };
}

#endif // MOONLIGHT_GLASS_HPP_