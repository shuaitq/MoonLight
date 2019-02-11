#ifndef MOONLIGHT_RAY_HPP_
#define MOONLIGHT_RAY_HPP_

#include "../Math/Vector.hpp"

namespace MoonLight
{
    template <typename T>
    class Ray
    {
    public:
        Vector3D_T<T> origin, direction;
        Ray():origin(), direction(){}
        Ray(const Vector3D_T<T> &o, const Vector3D_T<T> &d):origin(o), direction(d){}
        Vector3D_T<T> GetPoint(const T t) const
        {
            return origin + direction * t;
        }
    };
}

#endif // MOONLIGHT_RAY_HPP_