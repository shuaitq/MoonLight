#ifndef MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_
#define MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    class OrthographicCamera : public Camera
    {
    public:
        OrthographicCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double h);
        Ray<double> GetRay(const double x, const double y) const;

    private:
        double height;
    };
}

#endif // MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_