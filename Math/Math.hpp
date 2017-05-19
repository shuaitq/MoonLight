#ifndef MOONLIGHT_MATH_HPP_
#define MOONLIGHT_MATH_HPP_

#include "Vector.hpp"

#include <cmath>

// return t1 * u + t2 * (1-u) 
template <typename T, typename U>
T Interpolation(const T &t1, const T &t2, const U u)
{
    return t1 * u + t2 * (1 - u);
}

#endif //MOONLIGHT_MATH_HPP_