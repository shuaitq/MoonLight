#ifndef MOONLIGHT_CAMERA_HPP_
#define MOONLIGHT_CAMERA_HPP_

#include "../Core/Ray.hpp"

namespace MoonLight
{
    template <typename T>
    class Camera
    {
    public:
        Camera(const Vector3D_T<T> &p, const Vector3D_T<T> &f, const Vector3D_T<T> &u, const Vector3D_T<T> &r):position(p), front(f), up(u), right(r){}
        virtual Ray<T> GetRay(T x, T y) = 0;
    
    protected:
        Vector3D_T<T> position;
        Vector3D_T<T> front, up, right;
    };
}

#endif // MOONLGITH_CAMERA_HPP_