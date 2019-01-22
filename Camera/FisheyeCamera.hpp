#ifndef MOONLIGHT_FISHEYE_CAMERA_HPP_
#define MOONLIGHT_FISHEYE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    template <typename T>
    class FisheyeCamera : public Camera<T>
    {
    public:
        FisheyeCamera(const Vector3D_T<T> &p, const Vector3D_T<T> &f, const Vector3D_T<T> &u, const Vector3D_T<T> &r, const T a, const T fo):Camera<T>(p, f, u, r), aspect(a), fov(fo){}
        Ray<T> GetRay(T x, T y)
        {
            T dis = sqrt((y - 0.5) * (y - 0.5) + (x - 0.5) * (x - 0.5));
            //T dis = abs(y - 0.5);
            T theta = dis * fov;

            T phi = atan2((0.5 - x) / aspect, (y - 0.5));

            return Ray<T>(this->position, this->front * cos(theta) + this->up * sin(theta) * sin(phi) + this->right * sin(theta) * cos(phi));
        }

    private:
        T aspect;
        T fov;
    };
}

#endif // MOONLIGHT_FISHEYE_CAMERA_HPP_