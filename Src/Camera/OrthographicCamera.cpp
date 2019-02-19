#include "OrthographicCamera.hpp"

namespace MoonLight
{
    OrthographicCamera::OrthographicCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double w):Camera(p, f, u, r), aspect(a), width(w){}

    Ray<double> OrthographicCamera::GetRay(double x, double y)
    {
        return Ray<double>(this->position + this->up * (0.5 - x) * width / aspect + this->right * (y - 0.5) * width, this->front);
    }
}