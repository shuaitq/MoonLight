#ifndef MOONLIGHT_OBJECT_HPP_
#define MOONLIGHT_OBJECT_HPP_

#include "Ray.hpp"

class Object
{
public:
    virtual float Intersect(const Ray &r) const = 0;
};

#endif // MOONLIGHT_OBJECT_HPP_