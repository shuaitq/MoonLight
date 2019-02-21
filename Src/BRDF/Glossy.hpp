#ifndef MOONLIGHT_GLOSSY_HPP_
#define MOONLIGHT_GLOSSY_HPP_

#include "../Core/Ray.hpp"

#include <functional>

namespace MoonLight
{
    std::function<Ray<double>(const Vector3D_T<double> &, const Vector3D_T<double> &, const Vector3D_T<double> &)> Glossy(double degree);
}

#endif // MOONLIGHT_GLOSSY_HPP_