#include "Glass.hpp"

#include "../Utility/Rand.hpp"
#include "../Core/World.hpp"

namespace MoonLight
{
    Material Glass(const RGB_T<double> &color, const RGB_T<double> &emission, const BRDF &brdf, const double refractive_index)
    {
        return [=](const Vector3D_T<double> &position, const Vector3D_T<double> &normal, const Vector3D_T<double> &incident, const size_t depth)
        {
            double idotn = Dot(incident, normal), k;
            RGB_T<double> ret;
            Vector3D_T<double> direction;

            if(idotn <= 0)
            {
                // into
                double R0 = (refractive_index - 1) / (refractive_index + 1);
                R0 *= R0;
                double a = 1 + idotn;
                double aa = a * a;
                double Re = R0 + (1 - R0) * aa * aa * a;

                double eta = 1 / refractive_index;
                k = 1 - eta * eta * (1 - idotn * idotn);

                ret = (emission + color * World::Get().tracer(brdf(position, normal, incident * eta - normal * (idotn * eta + sqrt(k))), depth)) * (1 - Re) + (emission + color * World::Get().tracer(brdf(position, normal, incident - (2 * idotn) * normal), depth)) * Re;
            }
            else
            {
                // out
                k = 1 - refractive_index * refractive_index * (1 - idotn * idotn);

                if(k < 0)
                {
                    // Total reflection
                    ret = (emission + color * World::Get().tracer(brdf(position, normal, incident - (2 * idotn) * normal), depth));
                }
                else
                {
                    direction = incident * refractive_index + normal * (sqrt(k) - idotn * refractive_index);

                    double R0 = (refractive_index - 1) / (refractive_index + 1);
                    R0 *= R0;
                    double a = 1 - Dot(normal, direction);
                    double aa = a * a;
                    double Re = R0 + (1 - R0) * aa * aa * a;

                    ret = (emission + color * World::Get().tracer(brdf(position, normal, direction), depth)) * (1 - Re) + (emission + color * World::Get().tracer(brdf(position, normal, incident - (2 * idotn) * normal), depth)) * Re;
                }
            }
            
            return ret;
        };
    }
}