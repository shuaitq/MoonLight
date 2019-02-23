#include "FisheyeCamera.hpp"

namespace MoonLight
{
    Camera FisheyeCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double fov)
    {
        return [=](const double x, const double y)
        {
            double dis = sqrt(y * y + x * x);
            double theta = dis * fov / 2;
            double phi = atan2(y, x * aspect);

            return Ray<double>(position, front * cos(theta) + up * sin(theta) * sin(phi) + right * sin(theta) * cos(phi));
        };
    }
}