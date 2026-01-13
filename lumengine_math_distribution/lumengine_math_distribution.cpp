#include <iostream>
#include "include/lum_vec2.h"
int main()
{
    Vec2 vector;
    vector.x = 10;
    vector.y = 15;
    vec2_print(&vector);
    vec2_div_scalar(&vector, 4.123);
    vec2_print(&vector);
}
