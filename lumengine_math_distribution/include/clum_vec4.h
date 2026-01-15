#pragma once
#define VEC_EPSILON 1e-8f
#ifdef __cplusplus
extern "C" {
#endif

	/////////////////////////////
	/// float
	/////////////////////////////

	typedef struct alignas(16) {
		float x, y, z, w;
	} _vec4f;

	inline void _vec4f_zero(_vec4f* v);
	inline void _vec4f_one(_vec4f* v);
	inline void _vec4f_set(_vec4f* v, float x, float y, float z, float w);

	inline void _vec4f_add(const _vec4f* a, const _vec4f* b, _vec4f* out);
	inline void _vec4f_sub(const _vec4f* a, const _vec4f* b, _vec4f* out);
	inline void _vec4f_mul(const _vec4f* a, const _vec4f* b, _vec4f* out);
	inline void _vec4f_mul_scalar(_vec4f* v, float s);
	inline void _vec4f_div(const _vec4f* a, const _vec4f* b, _vec4f* out);
	inline void _vec4f_div_scalar(_vec4f* v, float s);

	inline float _vec4f_length(const _vec4f* v);
	inline float _vec4f_length_sq(const _vec4f* v);
	inline float _vec4f_dot(const _vec4f* a, const _vec4f* b);
	inline float _vec4f_distance(const _vec4f* a, const _vec4f* b);
	inline float _vec4f_distance_sq(const _vec4f* a, const _vec4f* b);
	inline void _vec4f_lerp(const _vec4f* a, const _vec4f* b, _vec4f* out, float t);

	inline bool _vec4f_normalize(_vec4f* v);
	inline void _vec4f_print(_vec4f* v);
	inline void _vec4f_neg(_vec4f* v);
	inline void _vec4f_inverse(_vec4f* v);
	inline void _vec4f_clamp(_vec4f* v, float min, float max);
	inline void _vec4f_min(const _vec4f* a, const _vec4f* b, _vec4f* out);
	inline void _vec4f_max(const _vec4f* a, const _vec4f* b, _vec4f* out);



	/////////////////////////////
	/// int
	/////////////////////////////

	typedef struct alignas(16) {
		int x, y, z, w;
	} _vec4i;

	inline void _vec4i_zero(_vec4i* v);
	inline void _vec4i_one(_vec4i* v);
	inline void _vec4i_set(_vec4i* v, int x, int y, int z, int w);

	inline void _vec4i_add(const _vec4i* a, const _vec4i* b, _vec4i* out);
	inline void _vec4i_sub(const _vec4i* a, const _vec4i* b, _vec4i* out);
	inline void _vec4i_mul(const _vec4i* a, const _vec4i* b, _vec4i* out);
	inline void _vec4i_mul_scalar(_vec4i* v, int s);
	inline void _vec4i_div(const _vec4i* a, const _vec4i* b, _vec4i* out);
	inline void _vec4i_div_scalar(_vec4i* v, int s);

	inline float _vec4i_length(const _vec4i* v);
	inline float _vec4i_length_sq(const _vec4i* v);
	inline float _vec4i_dot(const _vec4i* a, const _vec4i* b);
	inline float _vec4i_distance(const _vec4i* a, const _vec4i* b);
	inline float _vec4i_distance_sq(const _vec4i* a, const _vec4i* b);

	inline void _vec4i_print(_vec4i* v);
	inline void _vec4i_neg(_vec4i* v);
	inline void _vec4i_clamp(_vec4i* v, int min, int max);
	inline void _vec4i_min(const _vec4i* a, const _vec4i* b, _vec4i* out);
	inline void _vec4i_max(const _vec4i* a, const _vec4i* b, _vec4i* out);



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	typedef struct alignas(16) {
		unsigned int x, y, z, w;
	} _vec4ui;

	inline void _vec4ui_zero(_vec4ui* v);
	inline void _vec4ui_one(_vec4ui* v);
	inline void _vec4ui_set(_vec4ui* v, unsigned int x, unsigned int y, unsigned int z, unsigned int w);

	inline void _vec4ui_add(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);
	inline void _vec4ui_sub(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);
	inline void _vec4ui_mul(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);
	inline void _vec4ui_mul_scalar(_vec4ui* v, unsigned int s);
	inline void _vec4ui_div(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);
	inline void _vec4ui_div_scalar(_vec4ui* v, unsigned int s);

	inline float _vec4ui_length(const _vec4ui* v);
	inline float _vec4ui_length_sq(const _vec4ui* v);
	inline float _vec4ui_dot(const _vec4ui* a, const _vec4ui* b);
	inline float _vec4ui_distance(const _vec4ui* a, const _vec4ui* b);
	inline float _vec4ui_distance_sq(const _vec4ui* a, const _vec4ui* b);

	inline void _vec4ui_print(_vec4ui* v);
	inline void _vec4ui_clamp(_vec4ui* v, unsigned int min, unsigned int max);
	inline void _vec4ui_min(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);
	inline void _vec4ui_max(const _vec4ui* a, const _vec4ui* b, _vec4ui* out);

#ifndef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	/////////////////////////////
	/// float
	/////////////////////////////

	inline void _vec4f_zero(_vec4f* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
		v->w = 0;
	}
	inline void _vec4f_one(_vec4f* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
		v->w = 1;
	}
	inline void _vec4f_set(_vec4f* v, float x, float y, float z, float w) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
	}
	inline void _vec4f_add(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
		out->w = a->w + b->w;
	}
	inline void _vec4f_sub(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
		out->z = a->z - b->z;
		out->w = a->w - b->w;
	}
	inline void _vec4f_mul(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * b->z;
		out->w = a->w * b->w;
	}
	inline void _vec4f_mul_scalar(_vec4f* v, float s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
		v->w *= s;
	}
	inline void _vec4f_div(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
		out->w = a->w / b->w;
	}
	inline void _vec4f_div_scalar(_vec4f* v, float s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
		v->w /= s;
	}

	inline float _vec4f_length(const _vec4f* v) {
		return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
	}
	inline float _vec4f_length_sq(const _vec4f* v) {
		return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
	}
	inline float _vec4f_dot(const _vec4f* a, const _vec4f* b) {
		return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
	}
	inline float _vec4f_distance(const _vec4f* a, const _vec4f* b) {
		return
			sqrtf(
				(b->x - a->x) * (b->x - a->x) +
				(b->y - a->y) * (b->y - a->y) +
				(b->z - a->z) * (b->z - a->z) +
				(b->w - a->w) * (b->w - a->w)
			);
	}
	inline float _vec4f_distance_sq(const _vec4f* a, const _vec4f* b) {
		return
			(b->x - a->x) * (b->x - a->x) +
			(b->y - a->y) * (b->y - a->y) +
			(b->z - a->z) * (b->z - a->z) +
			(b->w - a->w) * (b->w - a->w);
	}
	inline void _vec4f_lerp(const _vec4f* a, const _vec4f* b, _vec4f* out, float t) {
		out->x = a->x + (b->x - a->x) * t;
		out->y = a->y + (b->y - a->y) * t;
		out->z = a->z + (b->z - a->z) * t;
		out->w = a->w + (b->w - a->w) * t;
	}

	inline bool _vec4f_normalize(_vec4f* v) {
		float len_sq = (v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
		if (len_sq <= VEC_EPSILON)
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v->x *= len_inv;
		v->y *= len_inv;
		v->z *= len_inv;
		v->w *= len_inv;
		return true;
	}
	inline void _vec4f_print(_vec4f* v) {
		printf("x: %f, y: %f, z: %f, w: %f", v->x, v->y, v->z, v->w);
	}
	inline void _vec4f_neg(_vec4f* v) {
		v->x = -v->x;
		v->y = -v->y;
		v->z = -v->z;
		v->w = -v->w;
	}
	inline void _vec4f_inverse(_vec4f* v) {
		v->x = 1.0f / v->x;
		v->y = 1.0f / v->y;
		v->z = 1.0f / v->z;
		v->w = 1.0f / v->w;
	}
	inline void _vec4f_clamp(_vec4f* v, float min, float max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;

		if (v->w < min) v->w = min;
		else if (v->w > max) v->w = max;
	}
	inline void _vec4f_min(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
		out->w = (a->w > b->w) ? b->w : a->w;
	}
	inline void _vec4f_max(const _vec4f* a, const _vec4f* b, _vec4f* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
		out->w = (a->w < b->w) ? b->w : a->w;
	}



	/////////////////////////////
	/// int
	/////////////////////////////

	inline void _vec4i_zero(_vec4i* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
		v->w = 0;
	}
	inline void _vec4i_one(_vec4i* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
		v->w = 1;
	}
	inline void _vec4i_set(_vec4i* v, int x, int y, int z, int w) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
	}

	inline void _vec4i_add(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
		out->w = a->w + b->w;
	}
	inline void _vec4i_sub(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
		out->z = a->z - b->z;
		out->w = a->w - b->w;
	}
	inline void _vec4i_mul(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * a->z;
		out->w = a->w * a->w;
	}
	inline void _vec4i_mul_scalar(_vec4i* v, int s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
		v->w *= s;
	}
	inline void _vec4i_div(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
		out->w = a->w / b->w;
	}
	inline void _vec4i_div_scalar(_vec4i* v, int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
		v->w /= s;
	}

	inline float _vec4i_length(const _vec4i* v) {
		return
			sqrtf((float)(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
	}
	inline float _vec4i_length_sq(const _vec4i* v) {
		return (float)(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
	}
	inline float _vec4i_dot(const _vec4i* a, const _vec4i* b) {
		return (float)(a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
	}
	inline float _vec4i_distance(const _vec4i* a, const _vec4i* b) {
		return
			sqrtf(
				(float)(
					(b->x - a->x) * (b->x - a->x) +
					(b->y - a->y) * (b->y - a->y) +
					(b->z - a->z) * (b->z - a->z) +
					(b->w - a->w) * (b->w - a->w)
					)
			);
	}
	inline float _vec4i_distance_sq(const _vec4i* a, const _vec4i* b) {
		return
			(float)(
				(b->x - a->x) * (b->x - a->x) +
				(b->y - a->y) * (b->y - a->y) +
				(b->z - a->z) * (b->z - a->z) +
				(b->w - a->w) * (b->w - a->w)
				);
	}

	inline void _vec4i_print(_vec4i* v) {
		printf("x: %d, y: %d, z: %d, w: %d", v->x, v->y, v->z, v->w);
	}
	inline void _vec4i_neg(_vec4i* v) {
		v->x = -v->x;
		v->y = -v->y;
		v->z = -v->z;
		v->w = -v->w;
	}
	inline void _vec4i_clamp(_vec4i* v, int min, int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;

		if (v->w < min) v->w = min;
		else if (v->w > max) v->w = max;
	}
	inline void _vec4i_min(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
		out->w = (a->w > b->w) ? b->w : a->w;
	}
	inline void _vec4i_max(const _vec4i* a, const _vec4i* b, _vec4i* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
		out->w = (a->w < b->w) ? b->w : a->w;
	}



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	inline void _vec4ui_zero(_vec4ui* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
		v->w = 0;
	}
	inline void _vec4ui_one(_vec4ui* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
		v->w = 1;
	}
	inline void _vec4ui_set(_vec4ui* v, unsigned int x, unsigned int y, unsigned int z, unsigned int w) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
	}

	inline void _vec4ui_add(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
		out->w = a->w + b->w;
	}
	inline void _vec4ui_sub(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = (a->x > b->x) ? (a->x - b->x) : 0;
		out->y = (a->y > b->y) ? (a->y - b->y) : 0;
		out->z = (a->y > b->z) ? (a->z - b->z) : 0;
		out->w = (a->w > b->w) ? (a->w - b->w) : 0;
	}
	inline void _vec4ui_mul(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * b->z;
		out->w = a->w * b->w;
	}
	inline void _vec4ui_mul_scalar(_vec4ui* v, unsigned int s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
		v->w *= s;
	}
	inline void _vec4ui_div(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
		out->w = a->w / b->w;
	}
	inline void _vec4ui_div_scalar(_vec4ui* v, unsigned int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
		v->w /= s;
	}

	inline float _vec4ui_length(const _vec4ui* v) {
		return
			sqrtf((float)(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w));
	}
	inline float _vec4ui_length_sq(const _vec4ui* v) {
		return (float)(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
	}
	inline float _vec4ui_dot(const _vec4ui* a, const _vec4ui* b) {
		return (float)(a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
	}
	inline float _vec4ui_distance(const _vec4ui* a, const _vec4ui* b) {
		return
			sqrtf(
				(float)(
					(b->x - a->x) * (b->x - a->x) +
					(b->y - a->y) * (b->y - a->y) +
					(b->z - a->z) * (b->z - a->z) +
					(b->w - a->w) * (b->w - a->w)
					)
			);
	}
	inline float _vec4ui_distance_sq(const _vec4ui* a, const _vec4ui* b) {
		return
			(float)(
				(b->x - a->x) * (b->x - a->x) +
				(b->y - a->y) * (b->y - a->y) +
				(b->z - a->z) * (b->z - a->z) +
				(b->w - a->w) * (b->w - a->w)
				);
	}

	inline void _vec4ui_print(_vec4ui* v) {
		printf("x: %d, y: %d, z: %d, w: %d", v->x, v->y, v->z, v->w);
	}
	inline void _vec4ui_clamp(_vec4ui* v, unsigned int min, unsigned int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;

		if (v->w < min) v->w = min;
		else if (v->w > max) v->w = max;
	}
	inline void _vec4ui_min(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
		out->w = (a->w > b->w) ? b->w : a->w;
	}
	inline void _vec4ui_max(const _vec4ui* a, const _vec4ui* b, _vec4ui* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
		out->w = (a->w < b->w) ? b->w : a->w;
	}

#endif
#if defined(__cplusplus)
}
#endif