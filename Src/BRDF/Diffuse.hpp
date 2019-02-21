#ifndef MOONLIGHT_DIFFUSE_HPP_
#define MOONLIGHT_DIFFUSE_HPP_

#include "../Core/Ray.hpp"

#include <functional>

namespace MoonLight
{
    std::function<Ray<double>(const Vector3D_T<double> &, const Vector3D_T<double> &, const Vector3D_T<double> &)> Diffuse(double degree);
}

#endif // MOONLIGHT_DIFFUSE_HPP_