#pragma once
#include "lum_vec2.h"
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		float m[9];
	} mat3f;

	void mat3f_identity(mat3f* m);
	void mat3f_scale(mat3f* m, const vec2f* v);
	void mat3f_rotate(mat3f* m, float theta);
	void mat3f_translate(mat3f* m, const vec2f* v);

	void mat3f_mul_mat3f(mat3f* out, const mat3f* a, const mat3f* b);
	void mat3f_mul_vec2f(vec2f* out, const mat3f* m, const vec2f* v);

	void mat3f_print(const mat3f* m);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>
	void mat3f_identity(mat3f* m) {
		for (int i = 0; i < 9; i++) m->m[i] = 0;
		m->m[0] = 1;
		m->m[4] = 1;
		m->m[8] = 1;
	}
	void mat3f_scale(mat3f* m, const vec2f* v) {
		m->m[0] *= v->x;
		m->m[1] *= v->x;

		m->m[3] *= v->y;
		m->m[4] *= v->y;
	}
	void mat3f_rotate(mat3f* m, float theta) {
		float c = cosf(theta);
		float s = sinf(theta);

		float m0 = m->m[0] * c + m->m[3] * s;
		float m1 = m->m[1] * c + m->m[4] * s;
		float m3 = m->m[0] * -s + m->m[3] * c;
		float m4 = m->m[1] * -s + m->m[4] * c;

		m->m[0] = m0;
		m->m[1] = m1;
		m->m[3] = m3;
		m->m[4] = m4;
	}
	void mat3f_translate(mat3f* m, const vec2f* v) {
		m->m[6] += v->x;
		m->m[7] += v->y;
	}
	void mat3f_mul_mat3f(mat3f* out, const mat3f* a, const mat3f* b) {
		out->m[0] = a->m[0] * b->m[0] + a->m[1] * b->m[3] + a->m[2] * b->m[6];
		out->m[1] = a->m[0] * b->m[1] + a->m[1] * b->m[4] + a->m[2] * b->m[7];
		out->m[2] = a->m[0] * b->m[2] + a->m[1] * b->m[5] + a->m[2] * b->m[8];

		out->m[3] = a->m[3] * b->m[0] + a->m[4] * b->m[3] + a->m[5] * b->m[6];
		out->m[4] = a->m[3] * b->m[1] + a->m[4] * b->m[4] + a->m[5] * b->m[7];
		out->m[5] = a->m[3] * b->m[2] + a->m[4] * b->m[5] + a->m[5] * b->m[8];

		out->m[6] = a->m[6] * b->m[0] + a->m[7] * b->m[3] + a->m[8] * b->m[6];
		out->m[7] = a->m[6] * b->m[1] + a->m[7] * b->m[4] + a->m[8] * b->m[7];
		out->m[8] = a->m[6] * b->m[2] + a->m[7] * b->m[5] + a->m[8] * b->m[8];
	}

	void mat3f_print(const mat3f* m) {
		printf("[ %f, %f, %f ]\n", m->m[0], m->m[3], m->m[6]);
		printf("[ %f, %f, %f ]\n", m->m[1], m->m[4], m->m[7]);
		printf("[ %f, %f, %f ]\n", m->m[2], m->m[5], m->m[8]);
	}


#endif
#ifdef __cplusplus
}
#endif