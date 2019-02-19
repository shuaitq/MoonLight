#include "FisheyeCamera.hpp"

namespace MoonLight
{
    FisheyeCamera::FisheyeCamera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r, const double a, const double fo):Camera(p, f, u, r), aspect(a), fov(fo){}

    Ray<double> FisheyeCamera::GetRay(double x, double y)
    {
        double dis = sqrt((y - 0.5) * (y - 0.5) + (x - 0.5) * (x - 0.5));
        //T dis = abs(y - 0.5);
        double theta = dis * fov;

        double phi = atan2((0.5 - x) / aspect, (y - 0.5));

        return Ray<double>(this->position, this->front * cos(theta) + this->up * sin(theta) * sin(phi) + this->right * sin(theta) * cos(phi));
    }
}