#ifndef MOONLIGHT_INTERSECTRESULT_HPP_
#define MOONLIGHT_INTERSECTRESULT_HPP_

struct IntersectResult
{
    Vector3D_T<float> position, normal;
    std::shared_ptr<Object> geometry;
    float distance;
};

#endif // MOONLIGHT_INTERSECTRESULT_HPP_