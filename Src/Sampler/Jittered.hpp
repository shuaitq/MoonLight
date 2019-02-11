#ifndef MOONLIGHT_JITTERED_HPP_
#define MOONLIGHT_JITTERED_HPP_

#include "Sampler.hpp"
#include "../Utility/Rand.hpp"

namespace MoonLight
{
    template <typename T, int N>
    class Jittered : public Sampler<T, N>
    {
    public:
        void Sampling(std::shared_ptr<std::array<Vector2D_T<T>, N * N>> samples)
        {
            for(int i = 0; i < N; ++ i)
            {
                for(int j = 0; j < N; ++ j)
                {
                    (*samples)[i * N + j] = Vector2D_T<T>((i + Rand<T>::unit_of_rand()) / N, (j + Rand<T>::unit_of_rand()) / N);
                }
            }
        }
    };
}

#endif // MOONLIGHT_JITTERED_HPP_