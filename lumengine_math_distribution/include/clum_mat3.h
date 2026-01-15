#pragma once
#include "clum_vec2.h"
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct alignas(16) {
		float m[12];
	} _mat3f;
	
	void _mat3f_identity(_mat3f* m);
	void _mat3f_scale(_mat3f* out, const _vec2f* v);
	void _mat3f_scale_inplace(_mat3f* out, const _vec2f* v);
	void _mat3f_rotate(_mat3f* out, float theta);
	void _mat3f_rotate_inplace(_mat3f* out, float theta);
	void _mat3f_translate(_mat3f* out, const _vec2f* v);
	void _mat3f_translate_inplace(_mat3f* out, const _vec2f* v);

	void _mat3f_mul_mat3f(_mat3f* out, const _mat3f* a, const _mat3f* b);
	void _mat3f_mul_vec2f(_vec2f* out, const _mat3f* m, const _vec2f* v);

	void _mat3f_print(const _mat3f* m);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	void _mat3f_identity(_mat3f* m) {
		for (int i = 0; i < 9; i++) m->m[i] = 0;
		m->m[0] = 1;
		m->m[4] = 1;
		m->m[8] = 1;
	}
	void _mat3f_scale(_mat3f* out, const _vec2f* v) {
		_mat3f_identity(out);
		out->m[0] = v->x;
		out->m[4] = v->y;
	}
	void _mat3f_scale_inplace(_mat3f* out, const _vec2f* v) {
		out->m[0] *= v->x;
		out->m[4] *= v->y;
	}
	void _mat3f_rotate(_mat3f* out, float theta) {
		float c = cosf(theta);
		float s = sinf(theta);
		_mat3f_identity(out);
		out->m[0] = c;
		out->m[1] = s;
		out->m[3] = -s;
		out->m[4] = c;
	}
	void _mat3f_rotate_inplace(_mat3f* out, float theta) {
		float c = cosf(theta);
		float s = sinf(theta);

		out->m[0] *= c;
		out->m[1] *= s;
		out->m[3] *= -s;
		out->m[4] *= c;
	}
	void _mat3f_translate(_mat3f* out, const _vec2f* v) {
		_mat3f_identity(out);
		out->m[6] = v->x;
		out->m[7] = v->y;
	}
	void _mat3f_translate_inplace(_mat3f* out, const _vec2f* v) {
		out->m[6] += v->x;
		out->m[7] += v->y;
	}
	void _mat3f_mul_mat3f(_mat3f* out, const _mat3f* a, const _mat3f* b) {
		out->m[0] = a->m[0] * b->m[0] + a->m[3] * b->m[1] + a->m[6] * b->m[2];
		out->m[1] = a->m[1] * b->m[0] + a->m[4] * b->m[1] + a->m[7] * b->m[2];
		out->m[2] = a->m[2] * b->m[0] + a->m[5] * b->m[1] + a->m[8] * b->m[2];
		
		out->m[3] = a->m[0] * b->m[3] + a->m[3] * b->m[4] + a->m[6] * b->m[5];
		out->m[4] = a->m[1] * b->m[3] + a->m[4] * b->m[4] + a->m[7] * b->m[5];
		out->m[5] = a->m[2] * b->m[3] + a->m[5] * b->m[4] + a->m[8] * b->m[5];
		
		out->m[6] = a->m[0] * b->m[6] + a->m[3] * b->m[7] + a->m[6] * b->m[8];
		out->m[7] = a->m[1] * b->m[6] + a->m[4] * b->m[7] + a->m[7] * b->m[8];
		out->m[8] = a->m[2] * b->m[6] + a->m[5] * b->m[7] + a->m[8] * b->m[8];
	}
	void _mat3f_mul_vec2f(_vec2f* out, const _mat3f* m, const _vec2f* v) {
		out->x = v->x * m->m[0] + v->y * m->m[3] + 1 * m->m[6];
		out->y = v->x * m->m[1] + v->y * m->m[4] + 1 * m->m[7];
	}
	void _mat3f_print(const _mat3f* m) {
		printf("[ %f, %f, %f ]\n", m->m[0], m->m[3], m->m[6]);
		printf("[ %f, %f, %f ]\n", m->m[1], m->m[4], m->m[7]);
		printf("[ %f, %f, %f ]\n", m->m[2], m->m[5], m->m[8]);
	}

#endif
#ifdef __cplusplus
}
#endif