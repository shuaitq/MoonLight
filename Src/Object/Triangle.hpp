#ifndef MOONLIGHT_TRIANGLE_HPP_
#define MOONLIGHT_TRIANGLE_HPP_

#include "Object.hpp"

namespace MoonLight
{
    template <typename T>
    class Triangle : public Object<T>
    {
    public:
        Triangle(const std::shared_ptr<Material<T>> &m, const Vector3D_T<T> &v_0, const Vector3D_T<T> &v_1, const Vector3D_T<T> &v_2):Object<T>(m), v0(v_0), v1(v_1), v2(v_2){}

        void Hit(const Ray<T> &r, Vector3D_T<T> &position, Vector3D_T<T> &normal, Vector3D_T<T> &incident, std::shared_ptr<Material<T>> &material, T &tmin)
        {
            Vector3D_T<T> E1 = v1 - v0;

            Vector3D_T<T> E2 = v2 - v0;

            Vector3D_T<T> P = Cross(r.direction, E2);

            T det = Dot(E1, P);

            Vector3D_T<T> TT;
            if(det > 0)
            {
                TT = r.origin - v0;
            }
            else
            {
                TT = v0 - r.origin;
                det = -det;
            }

            if(det < 0.0001)
            {
                return;
            }

            T t, u, v;

            u = Dot(TT, P);
            if(u < 0 || u > det)
            {
                return;
            }

            Vector3D_T<T> Q = Cross(TT, E1);

            v = Dot(r.direction, Q);
            if(v < 0 || u + v > det)
            {
                return;
            }

            t = Dot(E2, Q);

            T fInvDet = 1 / det;
            t *= fInvDet;
            u *= fInvDet;
            v *= fInvDet;

            const T eps = 1e-5;

            if(t < eps || t >= tmin)
            {
                return;
            }
            tmin = t;
            material = this->material;
            incident = r.direction;
            position = r.GetPoint(t);
            normal = Normalize(Cross(E2, E1));

            //std::cout << t << std::endl;
            //std::cout << normal << std::endl;
        }

    private:
        Vector3D_T<T> v0, v1, v2;
    };
}

#endif // MOONLIGHT_TRIANGLE_HPP_