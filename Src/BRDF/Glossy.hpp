#ifndef MOONLIGHT_GLOSSY_HPP_
#define MOONLIGHT_GLOSSY_HPP_

#include "BRDF.hpp"

namespace MoonLight
{
    class Glossy : public BRDF
    {
    public:
        Glossy(double d);
        Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &direction) const;
    private:
        double degree;
    };
}

#endif // MOONLIGHT_GLOSSY_HPP_