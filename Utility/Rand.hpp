#ifndef MOONLIGHT_RAND_HPP_
#define MOONLIGHT_RAND_HPP_

#include <cstdlib>
#include <ctime>

namespace MoonLight
{
    template <typename T>
    class Rand
    {
    public:
        static void init_rand()
        {
            srand(time(nullptr));
        }
        
        static T unit_of_rand()
        {
            return T(rand()) / RAND_MAX;
        }
    };
}

#endif // MOONLIGHT_RAND_HPP_