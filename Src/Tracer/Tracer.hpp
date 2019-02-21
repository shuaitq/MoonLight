#ifndef MOONLIGHT_TRACER_HPP_
#define MOONLIGHT_TRACER_HPP_

#include "../Core/Ray.hpp"
#include "../Core/Color.hpp"

#include <functional>

namespace MoonLight
{
    using Tracer = std::function<RGB_T<double>(const Ray<double> &, const size_t)>;
}

#endif // MOONLIGHT_TRACER_HPP_