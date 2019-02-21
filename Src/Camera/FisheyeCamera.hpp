#ifndef MOONLIGHT_FISHEYE_CAMERA_HPP_
#define MOONLIGHT_FISHEYE_CAMERA_HPP_

#include "Camera.hpp"

namespace MoonLight
{
    Camera FisheyeCamera(const Vector3D_T<double> &position, const Vector3D_T<double> &front, const Vector3D_T<double> &up, const Vector3D_T<double> &right, const double aspect, const double fov);
}

#endif // MOONLIGHT_FISHEYE_CAMERA_HPP_