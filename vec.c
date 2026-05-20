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

bool v2d_isnull(const Vec2D *v)
{
    return v->x == 0 && v->y == 0;
}

double v2d_direction(const Vec2D *v)
{
    double v_length;
    double y_on_length, x_on_length;
    double angle; // in radians, range (-pi, pi], if v is not the null vector

    // doing this first cause no point continuing if
    // the vector has no direction (plus no dividing by zero)
    if (v->x == 0 && v->y == 0) return NAN;
    
    v_length = = v2d_length(v);
    y_on_length = v->y / v_length; // =sin(angle)
    x_on_length = x->x / v_length; // =cos(angle)

    // before going on to do conditional logic based on the quadrant,
    // if the angle is not in any quadrant (i.e. x or y is zero), then
    // im just going to return teh results right away
    if (y_on_length == 1) return M_PI_2;
    else if (y_on_length == -1) return -M_PI_2;
    else if (x_on_length == 1) return 0;
    else if (x_on_length == -1) return M_PI; // so that we don't have -pi because i dont like that
    
    angle = asin(y_on_length);
    
    // im just adjusting the angle, easy to understand by plotting sin sideways
    // or considering the quadrants of a circle in trig
    if (v->x < 0 && v->y < 0) angle = -M_PI - angle; // 3rd quadrant
    else if (v->x < 0 && v->y >= 0) angle = M_PI - angle; // 2nd quadrant
    
    // if (angle == -0.) angle = 0; // pretty sure this isn't necessary anymore after the previous checks
    
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
