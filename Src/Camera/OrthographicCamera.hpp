#ifndef MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_
#define MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    Camera OrthographicCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double height);
}

#endif // MOONLIGHT_ORTHOGRAPHIC_CAMERA_HPP_