#ifndef MOONLIGHT_MIRROR_HPP_
#define MOONLIGHT_MIRROR_HPP_

#include "Material.hpp"

namespace MoonLight
{
    template <typename T>
    class Mirror : public Material<T>
    {
    public:
        Mirror(const RGB_T<T> &c, const RGB_T<T> &e, const std::shared_ptr<BRDF<T>> &b):Material<T>(c, e, b){}
        Ray<T> GetRay(const Vector3D_T<T> &position, const Vector3D_T<T> &normal, const Vector3D_T<T> &incident)
        {
            return this->brdf->GetRay(position, normal, incident - 2 * Dot(incident, normal) * normal);
        }
    };
}

#endif // MOONLIGHT_MIRROR_HPP_