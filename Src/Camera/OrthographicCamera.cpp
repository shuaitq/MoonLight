#include "OrthographicCamera.hpp"

namespace MoonLight
{
    OrthographicCamera::OrthographicCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double h):Camera(p, f, u, r), aspect(a), height(h){}

    Ray<double> OrthographicCamera::GetRay(const double x, const double y) const
    {
        return Ray<double>(this->position + this->up * (x / 2 * height) + this->right * (y / 2 * height * aspect), this->front);
    }
}