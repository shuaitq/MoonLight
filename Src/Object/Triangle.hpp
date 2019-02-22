#ifndef MOONLIGHT_TRIANGLE_HPP_
#define MOONLIGHT_TRIANGLE_HPP_

#include "Object.hpp"

namespace MoonLight
{
    Object Triangle(const Material &material, const Vector3D_T<double> &v0, const Vector3D_T<double> &v1, const Vector3D_T<double> &v2)
    {
        return [=](const Ray<double> &ray)
        {
            double t = std::numeric_limits<double>::max();
            Vector3D_T<double> position, normal;

            Vector3D_T<double> E1 = v1 - v0;

            Vector3D_T<double> E2 = v2 - v0;

            Vector3D_T<double> P = Cross(ray.direction, E2);

            double det = Dot(E1, P);

            Vector3D_T<double> TT;
            if(det > 0)
            {
                TT = ray.origin - v0;
            }
            else
            {
                TT = v0 - ray.origin;
                det = -det;
            }

            if(det < 0.0001)
            {
                return;
            }

            double t, u, v;

            u = Dot(TT, P);
            if(u < 0 || u > det)
            {
                return;
            }

            Vector3D_T<double> Q = Cross(TT, E1);

            v = Dot(ray.direction, Q);
            if(v < 0 || u + v > det)
            {
                return;
            }

            t = Dot(E2, Q);

            double fInvDet = 1 / det;
            t *= fInvDet;
            u *= fInvDet;
            v *= fInvDet;

            const double eps = 1e-5;

            if(t < eps || t >= tmin)
            {
                return;
            }
            tmin = t;
            material = this->material;
            incident = r.direction;
            position = r.GetPoint(t);
            normal = Normalize(Cross(E2, E1));

            return std::make_tuple(t, position, normal, ray.direction, material);
        };
    }
}

#endif // MOONLIGHT_TRIANGLE_HPP_