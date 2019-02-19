#include "Mirror.hpp"

namespace MoonLight
{
    Mirror::Mirror(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b):Material(c, e, b){}

    Ray<double> Mirror::GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident)
    {
        return this->brdf->GetRay(position, normal, incident - 2 * Dot(incident, normal) * normal);
    }
}