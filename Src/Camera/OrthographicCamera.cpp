#include "OrthographicCamera.hpp"

namespace MoonLight
{
    Camera OrthographicCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double height)
    {
        return [=](const double x, const double y)
        {
            return Ray<double>(position + up * (y / 2 * height) + right * (x / 2 * height * aspect), front);
        };
    }
}