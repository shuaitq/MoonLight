#ifndef MOONLIGHT_FISHEYE_CAMERA_HPP_
#define MOONLIGHT_FISHEYE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    class FisheyeCamera : public Camera
    {
    public:
        FisheyeCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo);
        Ray<double> GetRay(double x, double y);

    private:
        double aspect;
        double fov;
    };
}

#endif // MOONLIGHT_FISHEYE_CAMERA_HPP_