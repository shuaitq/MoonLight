#ifndef MOONLIGHT_SPHERE_HPP_
#define MOONLIGHT_SPHERE_HPP_

#include "../Core/Object.hpp"
#include "../Core/Material.hpp"
#include "../Core/IntersectResult.hpp"

class Sphere : public Object
{
public:
    Sphere(float r, const Vector3D_T<float> &p, const RGB_T<float> &e, const RGB_T<float> &c, Material &m);
    float Intersect(const Ray &r) const;

    float radius;
    Vector3D_T<float> position;
    RGB_T<float> color, emission;
    Material material;
};

#endif // MOONLIGHT_SPHERE_HPP_