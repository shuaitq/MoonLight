#ifndef MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_
#define MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    class OrthographicCamera : public Camera
    {
    public:
        OrthographicCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double w);
        Ray<double> GetRay(double x, double y);

    private:
        double aspect;
        double width;
    };
}

#endif // MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_