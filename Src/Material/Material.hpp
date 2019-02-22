#ifndef MOONLIGHT_MATERIAL_HPP_
#define MOONLIGHT_MATERIAL_HPP_

#include "../Math/Vector.hpp"
#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    using Material = std::function<RGB_T<double>(const Vector3D_T<double> &, const Vector3D_T<double> &, const Vector3D_T<double> &, const size_t)>;
}

#endif // MOONLIGHT_MATERIAL_HPP_