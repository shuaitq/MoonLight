#ifndef MOONLIGHT_SAMPLER_HPP_
#define MOONLIGHT_SAMPLER_HPP_

#include "../Math/Vector.hpp"

#include <functional>

namespace MoonLight
{
    using Sampler = std::function<void(Vector2D_T<double> &)>;
}

#endif // MOONLIGHT_SAMPLER_HPP_