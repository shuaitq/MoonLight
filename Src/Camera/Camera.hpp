#ifndef MOONLIGHT_CAMERA_HPP_
#define MOONLIGHT_CAMERA_HPP_

#include "../Core/Ray.hpp"
#include "../Math/Vector.hpp"

namespace MoonLight
{
    class Camera
    {
    public:
        Camera(const Vector3D_T<double> &p, const Vector3D_T<double> &f, const Vector3D_T<double> &u, const Vector3D_T<double> &r);
        virtual Ray<double> GetRay(double x, double y) = 0;

    protected:
        Vector3D_T<double> position;
        Vector3D_T<double> front, up, right;
    };
}

#endif // MOONLGITH_CAMERA_HPP_