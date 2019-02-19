#include "Glossy.hpp"

#include "../Utility/Rand.hpp"

namespace MoonLight
{
    Glossy::Glossy(double d):degree(d){}

    Ray<double> Glossy::GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &direction)
    {
        double phi = 2 * M_PI * Rand();
        double cos_theta = pow(Rand(), 1 / (1 + degree));
        double sin_theta = sqrt(1 - cos_theta * cos_theta);
        Vector3D_T<double> w = direction, u = Normalize(Cross((fabs(w.x) > 0.1 ? Vector3D_T<double>(0, 1, 0) : Vector3D_T<double>(1, 0, 0)), w)), v = Cross(w, u);
        Vector3D_T<double> d = u * cos(phi) * sin_theta + v * sin(phi) * sin_theta + cos_theta * w;

        return Ray<double>(position, d);
    }
}