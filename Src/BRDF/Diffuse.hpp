#ifndef MOONLIGHT_DIFFUSE_HPP_
#define MOONLIGHT_DIFFUSE_HPP_

#include "BRDF.hpp"

namespace MoonLight
{
    class Diffuse : public BRDF
    {
    public:
        Diffuse(double d);
        Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &direction) const;
        
    private:
        double degree;
    };
}

#endif // MOONLIGHT_DIFFUSE_HPP_