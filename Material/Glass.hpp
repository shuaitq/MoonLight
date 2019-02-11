#ifndef MOONLIGHT_GLASS_HPP_
#define MOONLIGHT_GLASS_HPP_

#include "Material.hpp"

namespace MoonLight
{
    template <typename T>
    class Glass : public Material<T>
    {
    public:
        Glass(const RGB_T<T> &c, const RGB_T<T> &e, const std::shared_ptr<BRDF<T>> &b, const T ri):Material<T>(c, e, b), refractive_index(ri){}

        Ray<T> GetRay(const Vector3D_T<T> &position, const Vector3D_T<T> &normal, const Vector3D_T<T> &incident)
        {
            Vector3D_T<T> n;
            T nnt, ddn;
            bool into;
            if(Dot(normal, incident) < 0)
            {
                // into
                into = true;
                nnt = 1 / refractive_index;
                n = normal;
            }
            else
            {
                // out
                into = false;
                nnt = refractive_index / 1;
                n = -normal;
            }
            ddn = Dot(incident, n);

            T cos2t = 1-nnt*nnt*(1-ddn*ddn), a = refractive_index - 1, b = refractive_index + 1, c;

            if(cos2t < 0)
            {
                return Ray<T>(position, incident - 2 * Dot(incident, normal) * normal);
                //return this->brdf->GetRay(position, n, incident - 2 * Dot(incident, normal) * normal);
            }

            Vector3D_T<T> tdir = Normalize(incident * nnt - n * (ddn * nnt + sqrt(cos2t)));
            if(into)
            {
                c = 1 + ddn;
            }
            else
            {
                c = 1 - Dot(normal, tdir);
            }

            T R0 = a * a / (b * b);
            T Re = R0 + (1 - R0) * c * c * c * c * c;

            if(Rand<T>::unit_of_rand() > Re)
            {
                // Refraction
                if(into)
                {
                    return Ray<T>(position, tdir);
                    //return this->brdf->GetRay(position, -normal, tdir);
                }
                else
                {
                    return Ray<T>(position, tdir);
                    //return this->brdf->GetRay(position, normal, tdir);
                }
            }
            else
            {
                // Reflaction
                return Ray<T>(position, incident - 2 * Dot(incident, normal) * normal);
                //return this->brdf->GetRay(position, n, incident - 2 * Dot(incident, normal) * normal);
            }
        }
    private:
        T refractive_index;
    };
}

#endif // MOONLIGHT_GLASS_HPP_