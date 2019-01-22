#ifndef MOONLIGHT_BRDF_HPP_
#define MOONLIGHT_BRDF_HPP_

namespace MoonLight
{
    template <typename T>
    class BRDF
    {
    public:
        virtual Ray<T> GetRay(const Vector3D_T<T> &position, const Vector3D_T<T> &normal, const Vector3D_T<T> &direction) = 0;
    };
}

#endif // MOONLIGHT_BRDF_HPP_