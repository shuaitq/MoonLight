#include "Sphere.hpp"

namespace MoonLight
{
    Sphere::Sphere(float r, const Vector3D_T<float> &p, const RGB_T<float> &e, const RGB_T<float> &c, Material &m):radius(r), position(p), emission(e), color(c), Material(m){}

    float intersect(const Ray &r) const {
        Vector3D_T<float> op = position - r.origin;
        double t, eps=1e-4, b=Dot(op, r.direction), det=b*b - Dot(op, op) + radius * radius;
        if (det<0) return 0; else det=sqrt(det);
        return (t=b-det)>eps ? t : ((t=b+det)>eps ? t : 0);
    }
}