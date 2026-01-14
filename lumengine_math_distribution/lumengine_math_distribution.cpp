#include <iostream>
#define LUM_MATH_IMPLEMENTATION
#include "include/lum_mat3.h"
#include "include/lum_vec2.h"
#include <stdio.h>

int main() {
	mat3f m;
	vec2f v;
	v.x = 100;
	v.y = 2123;
	mat3f_identity(&m);
	mat3f_translate(&m, &v);
	mat3f_print(&m);
}
