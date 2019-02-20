#include "Rand.hpp"

#include <cstdlib>

namespace MoonLight
{
    double Rand()
    {
        return drand48();
    }
}