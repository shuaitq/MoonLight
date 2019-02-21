#include "FisheyeCamera.hpp"

namespace MoonLight
{
    std::function<Ray<double>(const double, const double)> FisheyeCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double fov)
    {
        return [=](const double x, const double y)
        {
            double dis = sqrt(y * y + x * x);
            double theta = dis * fov;
            double phi = atan2(y * aspect, x);

            return Ray<double>(position, front * cos(theta) + up * sin(theta) * sin(phi) + right * sin(theta) * cos(phi));
        };
    }
}