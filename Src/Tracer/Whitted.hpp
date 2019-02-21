#ifndef MOONLIGHT_WHITTED_HPP_
#define MOONLIGHT_WHITTED_HPP_

#include "Tracer.hpp"

namespace MoonLight
{
    Tracer Whitted(const size_t max_depth, const double max_t);
}

#endif // MOONLIGHT_WHITTED_HPP_