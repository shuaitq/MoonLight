#ifndef MOONLIGHT_JITTERED_HPP_
#define MOONLIGHT_JITTERED_HPP_

#include "../Math/Vector.hpp"

#include <functional>

namespace MoonLight
{
    std::function<void(Vector2D_T<double> &)> Jittered(size_t n);
}

#endif // MOONLIGHT_JITTERED_HPP_