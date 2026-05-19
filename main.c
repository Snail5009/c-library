#include "vec.h"
#include <stdio.h>

int main(void)
{
    Vec2D v = (Vec2D) { 0, 0 };
    printf("( %f %f )\n", v.x, v.y);
    printf("len: %f\n", v2d_length(&v));
    v2d_normalised(&v, &v);
    printf("norm: ( %f %f )\n", v.x, v.y);
    printf("dir: %f\n", v2d_direction(&v) / 3.1415926536 * 180);
}
