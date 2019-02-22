#ifndef MOONLIGHT_GLASS_HPP_
#define MOONLIGHT_GLASS_HPP_

#include "../BRDF/BRDF.hpp"
#include "Material.hpp"

namespace MoonLight
{
    Material Glass(const RGB_T<double> &color, const RGB_T<double> &emission, const BRDF &brdf, const double refractive_index);
}

#endif // MOONLIGHT_GLASS_HPP_