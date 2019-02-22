#ifndef MOONLIGHT_OBJECT_HPP_
#define MOONLIGHT_OBJECT_HPP_

#include "../Core/Ray.hpp"
#include "../Material/Material.hpp"

#include <functional>
#include <tuple>

namespace MoonLight
{
    using Object = std::function<std::tuple<double, Vector3D_T<double>, Vector3D_T<double>, Vector3D_T<double>, Material>(const Ray<double> &)>;
}

#endif // MOONLIGHT_OBJECT_HPP_