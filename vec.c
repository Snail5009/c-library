#include "vec.h"
#include <math.h>

double v2d_length(const Vec2D *v)
{
    return sqrt(v->x * v->x + v->y * v->y); // aka sqrt(dot(v,v))
}

void v2d_normalised(Vec2D *dest, const Vec2D *a)
{
    if (a->x == 0 && a->y == 0)
    {
        dest->x = NAN;
        dest->y = NAN;
        return;
    }
    double a_len_recip = 1.0 / v2d_length(a);
    dest->x = a->x * a_len_recip;
    dest->y = a->y * a_len_recip;
}

void v2d_negated(Vec2D *dest, const Vec2D *a)
{
    dest->x = -a->x;
    dest->y = -a->y;
}

double v2d_direction(const Vec2D *v)
{
    if (v->x == 0 && v->y == 0) return NAN;
    double angle = asin(v->y / v2d_length(v));
    if (v->x < 0 && v->y < 0) angle = -M_PI - angle; // 3rd quadrant
    else if (v->x < 0 && v->y >= 0) angle = M_PI - angle; // 2nd quadrant
    if (angle == -0.) angle = 0;
    return angle;
}


double v2d_scalar_product(const Vec2D *a, const Vec2D *b)
{
    return a->x * b->x + a->y * b->y;
}

void v2d_times_scalar(Vec2D *dest, const Vec2D *a, double b)
{
    dest->x = a->x * b;
    dest->y = a->y * b;
}

void v2d_times_v2d(Vec2D *dest, const Vec2D *a, const Vec2D *b)
{
    dest->x = a->x * b->x;
    dest->y = a->y * b->y;
}

void v2d_plus_scalar(Vec2D *dest, const Vec2D *a, double b)
{
    dest->x = a->x + b;
    dest->y = a->y + b;
}

void v2d_plus_v2d(Vec2D *dest, const Vec2D *a, const Vec2D *b)
{
    dest->x = a->x + b->x;
    dest->y = a->y + b->y;
}
