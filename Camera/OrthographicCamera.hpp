#ifndef MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_
#define MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    template <typename T>
    class OrthographicCamera : public Camera<T>
    {
    public:
        OrthographicCamera(const Vector3D_T<T> &p, const Vector3D_T<T> &f, const Vector3D_T<T> &u, const Vector3D_T<T> &r, const T a, const T w):Camera<T>(p, f, u, r), aspect(a), width(w){}
        Ray<T> GetRay(T x, T y)
        {
            return Ray<T>(this->position + this->up * (0.5 - x) * width / aspect + this->right * (y - 0.5) * width, this->front);
        }

    private:
        T aspect;
        T width;
    };
}

#endif // MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_