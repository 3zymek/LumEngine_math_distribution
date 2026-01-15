#pragma once
#include "clum_vec3.h"
#include "clum_vec4.h"
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct alignas(16) {
		float m[16];
	} _mat4f;

	void _mat4f_identity(_mat4f* m);
	void _mat4f_scale(_mat4f* out, const _vec3f* v);
	void _mat4f_scale_inplace(_mat4f* out, const _vec3f* v);
	void _mat4f_rotate(_mat4f* out, float theta);
	void _mat4f_rotate_inplace(_mat4f* out, float theta);
	void _mat4f_translate(_mat4f* out, const _vec3f* v);
	void _mat4f_translate_inplace(_mat4f* out, const _vec3f* v);

	void _mat4f_mul_mat4f(_mat4f* out, const _mat4f* a, const _mat4f* b);
	void _mat4f_mul_vec3f(_vec3f* out, const _mat4f* m, const _vec3f* v);
	void _mat4f_mul_vec4f(_vec4f* out, const _mat4f* m, const _vec4f* v);

	void _mat4f_print(const _mat4f* m);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	void _mat4f_identity(_mat4f* m) {
		for (int i = 0; i < 15; i++) m->m[i] = 0;
		m->m[0] = 1;
		m->m[5] = 1;
		m->m[10] = 1;
		m->m[15] = 1;
	}
	void _mat4f_scale(_mat4f* out, const _vec3f* v) {
		_mat4f_identity(out);
		out->m[0] = v->x;
		out->m[5] = v->y;
		out->m[10] = v->z;
	}
	void _mat4f_scale_inplace(_mat4f* out, const _vec3f* v) {
		out->m[0] *= v->x;
		out->m[5] *= v->y;
		out->m[10] *= v->z;
	}
	void _mat4f_rotate(_mat4f* out, float theta) {
		float c = cosf(theta);
		float s = sinf(theta);
		_mat4f_identity(out);
		out->m[0] = c;
		out->m[1] = s;
		out->m[4] = -s;
		out->m[5] = c;
	}
	void _mat4f_rotate_inplace(_mat4f* out, float theta) {
		float c = cosf(theta);
		float s = sinf(theta);

		out->m[0] *= c;
		out->m[1] *= s;
		out->m[4] *= -s;
		out->m[5] *= c;
	}
	void _mat4f_translate(_mat4f* out, const _vec3f* v) {
		_mat4f_identity(out);
		out->m[12] = v->x;
		out->m[13] = v->y;
		out->m[14] = v->z;
	}
	void _mat4f_translate_inplace(_mat4f* out, const _vec3f* v) {
		out->m[12] += v->x;
		out->m[13] += v->y;
		out->m[14] += v->z;
	} 
	void _mat4f_mul_mat4f(_mat4f* out, const _mat4f* a, const _mat4f* b) {
		out->m[0] = a->m[0] * b->m[0] + a->m[1] * b->m[4] + a->m[2] * b->m[8] + a->m[3] * b->m[12];
		out->m[1] = a->m[0] * b->m[1] + a->m[1] * b->m[5] + a->m[2] * b->m[9] + a->m[3] * b->m[13];
		out->m[2] = a->m[0] * b->m[2] + a->m[1] * b->m[6] + a->m[2] * b->m[10] + a->m[3] * b->m[14];
		out->m[3] = a->m[0] * b->m[3] + a->m[1] * b->m[7] + a->m[2] * b->m[11] + a->m[3] * b->m[15];


		out->m[4] = a->m[4] * b->m[0] + a->m[5] * b->m[4] + a->m[6] * b->m[8] + a->m[7] * b->m[12];
		out->m[5] = a->m[4] * b->m[1] + a->m[5] * b->m[5] + a->m[6] * b->m[9] + a->m[7] * b->m[13];
		out->m[6] = a->m[4] * b->m[2] + a->m[5] * b->m[6] + a->m[6] * b->m[10] + a->m[7] * b->m[14];
		out->m[7] = a->m[4] * b->m[3] + a->m[5] * b->m[7] + a->m[6] * b->m[11] + a->m[7] * b->m[15];


		out->m[8] = a->m[8] * b->m[0] + a->m[9] * b->m[4] + a->m[10] * b->m[8] + a->m[11] * b->m[12];
		out->m[9] = a->m[8] * b->m[1] + a->m[9] * b->m[5] + a->m[10] * b->m[9] + a->m[11] * b->m[13];
		out->m[10] = a->m[8] * b->m[2] + a->m[9] * b->m[6] + a->m[10] * b->m[10] + a->m[11] * b->m[14];
		out->m[11] = a->m[8] * b->m[3] + a->m[9] * b->m[7] + a->m[10] * b->m[11] + a->m[11] * b->m[15];


		out->m[12] = a->m[12] * b->m[0] + a->m[13] * b->m[4] + a->m[14] * b->m[8] + a->m[15] * b->m[12];
		out->m[13] = a->m[12] * b->m[1] + a->m[13] * b->m[5] + a->m[14] * b->m[9] + a->m[15] * b->m[13];
		out->m[14] = a->m[12] * b->m[2] + a->m[13] * b->m[6] + a->m[14] * b->m[10] + a->m[15] * b->m[14];
		out->m[15] = a->m[12] * b->m[3] + a->m[13] * b->m[7] + a->m[14] * b->m[11] + a->m[15] * b->m[15];

	}
	void _mat4f_mul_vec3f(_vec3f* out, const _mat4f* m, const _vec3f* v) {
		out->x = v->x * m->m[0] + v->y * m->m[4] + 1 * v->z * m->m[8] + 1 *m->m[12];
		out->y = v->x * m->m[1] + v->y * m->m[5] + 1 * v->z * m->m[9] + 1 * m->m[13];
		out->z = v->x * m->m[2] + v->y * m->m[6] + 1 * v->z * m->m[10] + 1 * m->m[14];
	}
	void _mat4f_mul_vec4f(_vec4f* out, const _mat4f* m, const _vec4f* v) {
		out->x = v->x * m->m[0] + v->y * m->m[4] + 1 * v->z * m->m[8] + 1 * v->w * m->m[12];
		out->y = v->x * m->m[1] + v->y * m->m[5] + 1 * v->z * m->m[9] + 1 * v->w * m->m[13];
		out->z = v->x * m->m[2] + v->y * m->m[6] + 1 * v->z * m->m[10] + 1 * v->w * m->m[14];
		out->w = v->x * m->m[3] + v->y * m->m[7] + 1 * v->z * m->m[11] + 1 * v->w * m->m[15];
	}
	void _mat4f_print(const _mat4f* m) {
		printf("[ %f, %f, %f, %f ]\n", m->m[0], m->m[4], m->m[8], m->m[12]);
		printf("[ %f, %f, %f, %f ]\n", m->m[1], m->m[5], m->m[9], m->m[13]);
		printf("[ %f, %f, %f, %f ]\n", m->m[2], m->m[6], m->m[10], m->m[14]);
		printf("[ %f, %f, %f, %f ]\n", m->m[3], m->m[7], m->m[11], m->m[15]);
	}

#endif
#ifdef __cplusplus
}
#endif