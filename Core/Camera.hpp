#ifndef MOONLIGHT_CAMERA_HPP_
#define MOONLIGHT_CAMERA_HPP_

#include "../Math/Math.hpp"

#include <iostream>

namespace MoonLight
{
    class Camera
    {
    public:
        Point3D_T<float> position;
        float fov;
        float aspect;
    private:
    };
}

#endif //MOONLIGHT_CAMERA_HPP_
