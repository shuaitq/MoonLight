#ifndef MOONLIGHT_BRDF_HPP_
#define MOONLIGHT_BRDF_HPP_

#include "../Core/Ray.hpp"

#include <functional>

namespace MoonLight
{
    using BRDF = std::function<Ray<double>(const Vector3D_T<double> &, const Vector3D_T<double> &, const Vector3D_T<double> &)>;
}

#endif // MOONLIGHT_BRDF_HPP_