
#pragma once

#define v2d_dot_product(dest, a, b) v2d_scalar_product(dest, a, b)

typedef struct Vec2D Vec2D;
struct Vec2D
{
    double x,y;
};

double v2d_length(const Vec2D *v);
void v2d_normalised(Vec2D *dest, const Vec2D *a);
void v2d_negated(Vec2D *dest, const Vec2D *a);
double v2d_direction(const Vec2D *v);

/* The dot product in other words. */
double v2d_scalar_product(const Vec2D *a, const Vec2D *b);

void v2d_times_scalar(Vec2D *dest, const Vec2D *a, double b);
/* i.e. pairwise multiplication where a_x * b_x -> dest_x and so on for y. */
void v2d_times_v2d(Vec2D *dest, const Vec2D *a, const Vec2D *b);

void v2d_plus_scalar(Vec2D *dest, const Vec2D *a, double b);
void v2d_plus_v2d(Vec2D *dest, const Vec2D *a, const Vec2D *b);
