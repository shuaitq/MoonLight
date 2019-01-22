#ifndef MOONLIGHT_OBJECT_HPP_
#define MOONLIGHT_OBJECT_HPP_

#include "../Core/Ray.hpp"
#include "../Material/Material.hpp"

#include <memory>

namespace MoonLight
{
    template <typename T>
    class Object
    {
    public:
        Object(const std::shared_ptr<Material<T>> &m):material(m){}

        virtual void Hit(const Ray<T> &r, Vector3D_T<T> &position, Vector3D_T<T> &normal, Vector3D_T<T> &incident, std::shared_ptr<Material<T>> &material, T &tmin) = 0;

    protected:
        std::shared_ptr<Material<T>> material;
    };
}

#endif // MOONLIGHT_OBJECT_HPP_