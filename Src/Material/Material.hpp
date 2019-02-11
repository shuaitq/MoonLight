#ifndef MOONLIGHT_MATERIAL_HPP_
#define MOONLIGHT_MATERIAL_HPP_

#include "../BRDF/BRDF.hpp"
#include "../Core/Color.hpp"

#include <memory>

namespace MoonLight
{
    template <typename T>
    class Material
    {
    public:
        Material(const RGB_T<T> &c, const RGB_T<T> &e, const std::shared_ptr<BRDF<T>> &b):color(c), emission(e), brdf(b){}
        virtual RGB_T<T> Shade(const RGB_T<T> &trace_color)
        {
            return emission + color * trace_color;
        }
        virtual Ray<T> GetRay(const Vector3D_T<T> &position, const Vector3D_T<T> &normal, const Vector3D_T<T> &incident) = 0;
    protected:
        RGB_T<T> color;
        RGB_T<T> emission;
        std::shared_ptr<BRDF<T>> brdf;
    };
}

#endif // MOONLIGHT_MATERIAL_HPP_