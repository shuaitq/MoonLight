#ifndef MOONLIGHT_SPHERE_HPP_
#define MOONLIGHT_SPHERE_HPP_

#include "Object.hpp"

namespace MoonLight
{
    template <typename T>
    class Sphere : public Object<T>
    {
    public:
        Sphere(std::shared_ptr<Material<T>> m, T r, const Vector3D_T<T> &p):Object<T>(m), radius(r), position(p){}
        void Hit(const Ray<T> &r, Vector3D_T<T> &p, Vector3D_T<T> &n, Vector3D_T<T> &i, std::shared_ptr<Material<T>> &m, T &tmin)
        {
            const T eps = 1e-5;

            T t;
            Vector3D_T<T> temp = r.origin - position;
            T a = Dot(r.direction, r.direction);
            T b = 2.0 * Dot(temp, r.direction);
            T c = Dot(temp, temp) - radius * radius;
            T disc = b * b - 4.0 * a * c;

            if(disc < 0)
            {
                return;
            }
            else
            {
                T e = sqrt(disc);
                T denom = 2.0 * a;
                t = (-b - e) / denom;

                if(t > eps && tmin > t)
                {
                    tmin = t;
                    m = this->material;
                    n = (temp + t * r.direction) / radius;
                    p = r.GetPoint(t);
                    i = r.direction;
                    
                    return;
                }

                t = (-b + e) / denom;

                if(t > eps && tmin > t)
                {
                    tmin = t;
                    m = this->material;
                    n = (temp + t * r.direction) / radius;
                    p = r.GetPoint(t);
                    i = r.direction;

                    return;
                }
            }

            return;
        }

        T radius;
        Vector3D_T<T> position;
    };
}

#endif // MOONLIGHT_SPHERE_HPP_