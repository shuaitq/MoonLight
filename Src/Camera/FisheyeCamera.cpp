#include "FisheyeCamera.hpp"

namespace MoonLight
{
    FisheyeCamera::FisheyeCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo):Camera(p, f, u, r, a), fov(fo){}

    Ray<double> FisheyeCamera::GetRay(const double x, const double y) const
    {
        double dis = sqrt(y * y + x * x);
        double theta = dis * fov;
        double phi = atan2(y * aspect, x);

        return Ray<double>(position, front * cos(theta) + up * sin(theta) * sin(phi) + right * sin(theta) * cos(phi));
    }
}