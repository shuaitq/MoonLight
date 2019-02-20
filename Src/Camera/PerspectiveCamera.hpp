#ifndef MOONLIGHT_PERSPECTIVE_CAMERA_HPP_
#define MOONLIGHT_PERSPECTIVE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo);
        Ray<double> GetRay(const double x, const double y) const;

    private:
        double fov;
    };
}

#endif // MOONLIGHT_PERSPECTIVE_CAMERA_HPP_