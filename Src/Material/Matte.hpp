#ifndef MOONLIGHT_MATTE_HPP_
#define MOONLIGHT_MATTE_HPP_

#include "../BRDF/BRDF.hpp"
#include "Material.hpp"

namespace MoonLight
{
    Material Matte(const RGB_T<double> &color, const RGB_T<double> &emission, const BRDF &brdf);
}

#endif // MOONLIGHT_MATTE_HPP_