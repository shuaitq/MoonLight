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
        // x [-1, 1] y [-1, 1]
        virtual Ray<double> GetRay(const double x, const double y) const = 0;

    protected:
        Vector3D_T<double> position;
        Vector3D_T<double> front, up, right;
    };
}

#endif // MOONLGITH_CAMERA_HPP_