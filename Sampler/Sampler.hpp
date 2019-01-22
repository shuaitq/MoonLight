#ifndef MOONLIGHT_SAMPLER_HPP_
#define MOONLIGHT_SAMPLER_HPP_

#include <memory>

namespace MoonLight
{
    template <typename T, int N>
    class Sampler
    {
    public:
        virtual void Sampling(std::shared_ptr<std::array<Vector2D_T<T>, N * N>> samples) = 0;
    };
}

#endif // MOONLIGHT_SAMPLER_HPP_