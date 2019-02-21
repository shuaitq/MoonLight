#ifndef MOONLIGHT_CAMERA_HPP_
#define MOONLIGHT_CAMERA_HPP_

#include "../Core/Ray.hpp"

#include <functional>

namespace MoonLight
{
    using Camera = std::function<Ray<double>(const double, const double)>;
}

#endif // MOONLIGHT_CAMERA_HPP_