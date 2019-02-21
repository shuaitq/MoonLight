#ifndef MOONLIGHT_PERSPECTIVE_CAMERA_HPP_
#define MOONLIGHT_PERSPECTIVE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    Camera PerspectiveCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double fov);
}

#endif // MOONLIGHT_PERSPECTIVE_CAMERA_HPP_