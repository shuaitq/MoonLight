#ifndef MOONLIGHT_RAY_HPP_
#define MOONLIGHT_RAY_HPP_

#include "../Math/Math.hpp"

struct Ray
{
    Vector3D_T<float> direction, origin;
    Vector3D_T<float> GetPoint(const float t)
    {
        return origin + direction * t;
    }
};

#endif // MOONLIGHT_RAY_HPP_