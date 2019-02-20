#include "Camera.hpp"

namespace MoonLight
{
    Camera::Camera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a):position(p), front(f), up(u), right(r), aspect(a){}
}