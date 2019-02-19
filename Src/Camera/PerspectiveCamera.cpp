#include "PerspectiveCamera.hpp"

namespace MoonLight
{
    PerspectiveCamera::PerspectiveCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo):Camera(p, f, u, r), aspect(a), fov(fo){}

    Ray<double> PerspectiveCamera::GetRay(double x, double y)
    {
        double tan_fov = tan(fov / 2);

        return Ray<double>(this->position, Normalize(this->front + this->up * (0.5 - x) * 2 * tan_fov / aspect + this->right * (y - 0.5) * 2 * tan_fov));
    }
}