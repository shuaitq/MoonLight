#ifndef MOONLIGHT_PERSPECTIVE_CAMERA_HPP_
#define MOONLIGHT_PERSPECTIVE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    template <typename T>
    class PerspectiveCamera : public Camera<T>
    {
    public:
        PerspectiveCamera(const Vector3D_T<T> &p, const Vector3D_T<T> &f, const Vector3D_T<T> &u, const Vector3D_T<T> &r, const T a, const T fo):Camera<T>(p, f, u, r), aspect(a), fov(fo){}
        Ray<T> GetRay(T x, T y)
        {
            T tan_fov = tan(fov / 2);

            return Ray<T>(this->position, Normalize(this->front + this->up * (0.5 - x) * 2 * tan_fov / aspect + this->right * (y - 0.5) * 2 * tan_fov));
        }

    private:
        T aspect;
        T fov;
    };
}

#endif // MOONLIGHT_PERSPECTIVE_CAMERA_HPP_