#include "Glass.hpp"

#include "../Utility/Rand.hpp"

namespace MoonLight
{
    Glass::Glass(const RGB_T<double> &c, const RGB_T<double> &e, const std::shared_ptr<BRDF> &b, const double ri):Material(c, e, b), refractive_index(ri){}

    Ray<double> Glass::GetRay(const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident)
    {
        Vector3D_T<double> n;
        double nnt, ddn;
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

        double cos2t = 1-nnt*nnt*(1-ddn*ddn), a = refractive_index - 1, b = refractive_index + 1, c;

        if(cos2t < 0)
        {
            return Ray<double>(position, incident - 2 * Dot(incident, normal) * normal);
            //return this->brdf->GetRay(position, n, incident - 2 * Dot(incident, normal) * normal);
        }

        Vector3D_T<double> tdir = Normalize(incident * nnt - n * (ddn * nnt + sqrt(cos2t)));
        if(into)
        {
            c = 1 + ddn;
        }
        else
        {
            c = 1 - Dot(normal, tdir);
        }

        double R0 = a * a / (b * b);
        double Re = R0 + (1 - R0) * c * c * c * c * c;

        if(Rand() > Re)
        {
            // Refraction
            if(into)
            {
                return Ray<double>(position, tdir);
                //return this->brdf->GetRay(position, -normal, tdir);
            }
            else
            {
                return Ray<double>(position, tdir);
                //return this->brdf->GetRay(position, normal, tdir);
            }
        }
        else
        {
            // Reflaction
            return Ray<double>(position, incident - 2 * Dot(incident, normal) * normal);
            //return this->brdf->GetRay(position, n, incident - 2 * Dot(incident, normal) * normal);
        }
    }
}