#ifndef MOONLIGHT_DIFFUSE_HPP_
#define MOONLIGHT_DIFFUSE_HPP_

#include "BRDF.hpp"

namespace MoonLight
{
    template <typename T>
    class Diffuse : public BRDF<T>
    {
    public:
        Diffuse(T d):degree(d){}
        Ray<T> GetRay(const Vector3D_T<T> &position, const Vector3D_T<T> &normal, const Vector3D_T<T> &direction)
        {
            T phi = 2 * M_PI * Rand<T>::unit_of_rand();
            T cos_theta = pow(Rand<T>::unit_of_rand(), 1 / (1 + degree));
            T sin_theta = sqrt(1 - cos_theta * cos_theta);
            Vector3D_T<T> w = normal, u=Normalize(Cross((fabs(w.x)>0.1?Vector3D_T<T>(0,1,0):Vector3D_T<T>(1, 0, 0)), w)), v=Cross(w ,u);
            Vector3D_T<T> d = u * cos(phi) * sin_theta + v * sin(phi) * sin_theta + cos_theta * w;

            return Ray<T>(position, d);
        }
    
    private:
        T degree;
    };
}

#endif // MOONLIGHT_DIFFUSE_HPP_