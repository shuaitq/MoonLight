#include "PerspectiveCamera.hpp"

namespace MoonLight
{
    PerspectiveCamera::PerspectiveCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo):Camera(p, f, u, r), aspect(a), fov(fo){}

    Ray<double> PerspectiveCamera::GetRay(const double x, const double y) const
    {
        double tan_fov = tan(fov / 2);

        return Ray<double>(this->position, Normalize(this->front + this->up * (x * tan_fov) + this->right * (y * tan_fov * aspect)));
    }
}