#include "Mirror.hpp"

#include "../Core/World.hpp"

namespace MoonLight
{
    Material Mirror(const RGB_T<double> &color, const RGB_T<double> &emission, const BRDF &brdf)
    {
        return [=](const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident, const size_t depth)
        {
            return emission + color * World::Get().tracer(brdf(position, normal, incident - (2 * Dot(incident, normal)) * normal), depth);
        };
    }
}