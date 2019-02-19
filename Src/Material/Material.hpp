#ifndef MOONLIGHT_MATERIAL_HPP_
#define MOONLIGHT_MATERIAL_HPP_

#include "../BRDF/BRDF.hpp"
#include "../Core/Color.hpp"

#include <memory>

namespace MoonLight
{
    class Material
    {
    public:
        Material(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b):color(c), emission(e), brdf(b){}
        virtual RGB_T<double> Shade(const RGB_T<double> &trace_color)
        {
            return emission + color * trace_color;
        }
        virtual Ray<double> GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident) = 0;
    protected:
        RGB_T<double> color;
        RGB_T<double> emission;
        std::shared_ptr<BRDF> brdf;
    };
}

#endif // MOONLIGHT_MATERIAL_HPP_