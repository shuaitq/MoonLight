#ifndef MOONLIGHT_MIRROR_HPP_
#define MOONLIGHT_MIRROR_HPP_

#include "../BRDF/BRDF.hpp"
#include "Material.hpp"

namespace MoonLight
{
    Material Mirror(const RGB_T<double> &color, const RGB_T<double> &emission, const BRDF &brdf);
}

#endif // MOONLIGHT_MIRROR_HPP_