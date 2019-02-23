#include "PerspectiveCamera.hpp"

namespace MoonLight
{
    Camera PerspectiveCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double fov)
    {
        return [=](const double x, const double y)
        {
            double tan_fov = tan(fov / 2);

            return Ray<double>(position, Normalize(front + up * (y * tan_fov) + right * (x * tan_fov * aspect)));
        };
    }
}