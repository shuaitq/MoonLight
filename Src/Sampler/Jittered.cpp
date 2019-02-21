#include "Jittered.hpp"

#include "../Utility/Rand.hpp"

namespace MoonLight
{
    std::function<void(Vector2D_T<double> &)> Jittered(size_t n)
    {
        return [=](Vector2D_T<double> &v)
        {
            static size_t i = 0, j = 0;

            v.x = (i + Rand()) / n;
            v.y = (j + Rand()) / n;

            ++ j;
            if(j == n)
            {
                ++ i;
                j = 0;
            }
        };
    }
}