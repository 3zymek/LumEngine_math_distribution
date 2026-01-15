#pragma once
#define VEC_EPSILON 1e-8f
#ifdef __cplusplus
extern "C" {
#endif

	/////////////////////////////
	/// float
	/////////////////////////////

	typedef struct {
		float x, y;
	} _vec2f;

	inline void _vec2f_zero(_vec2f* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void _vec2f_one(_vec2f* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void _vec2f_set(_vec2f* v, float x, float y);

	inline void _vec2f_add(const _vec2f* a, const _vec2f* b, _vec2f* out);
	inline void _vec2f_sub(const _vec2f* a, const _vec2f* b, _vec2f* out);
	inline void _vec2f_mul(const _vec2f* a, const _vec2f* b, _vec2f* out);
	inline void _vec2f_mul_scalar(_vec2f* v, float s);
	inline void _vec2f_div(const _vec2f* a, const _vec2f* b, _vec2f* out);
	inline void _vec2f_div_scalar(_vec2f* v, float s);

	inline float _vec2f_length(const _vec2f* v);
	inline float _vec2f_length_sq(const _vec2f* v);
	inline float _vec2f_dot(const _vec2f* a, const _vec2f* b);
	inline float _vec2f_distance(const _vec2f* a, const _vec2f* b);
	inline float _vec2f_distance_sq(const _vec2f* a, const _vec2f* b);
	inline void _vec2f_lerp(const _vec2f* a, const _vec2f* b, _vec2f* out, float t);

	inline bool _vec2f_normalize(_vec2f* v);
	inline void _vec2f_print(_vec2f* v);
	inline void _vec2f_neg(_vec2f* v);
	inline void _vec2f_inverse(_vec2f* v);
	inline void _vec2f_clamp(_vec2f* v, float min, float max);
	inline void _vec2f_min(const _vec2f* a, const _vec2f* b, _vec2f* out);
	inline void _vec2f_max(const _vec2f* a, const _vec2f* b, _vec2f* out);



	/////////////////////////////
	/// int
	/////////////////////////////

	typedef struct {
		int x, y;
	} _vec2i;

	inline void _vec2i_zero(_vec2i* v);
	inline void _vec2i_one(_vec2i* v);
	inline void _vec2i_set(_vec2i* v, int x, int y);

	inline void _vec2i_add(const _vec2i* a, const _vec2i* b, _vec2i* out);
	inline void _vec2i_sub(const _vec2i* a, const _vec2i* b, _vec2i* out);
	inline void _vec2i_mul(const _vec2i* a, const _vec2i* b, _vec2i* out);
	inline void _vec2i_mul_scalar(_vec2i* v, int s);
	inline void _vec2i_div(const _vec2i* a, const _vec2i* b, _vec2i* out);
	inline void _vec2i_div_scalar(_vec2i* v, int s);

	inline float _vec2i_length(const _vec2i* v);
	inline float _vec2i_length_sq(const _vec2i* v);
	inline float _vec2i_dot(const _vec2i* a, const _vec2i* b);
	inline float _vec2i_distance(const _vec2i* a, const _vec2i* b);
	inline float _vec2i_distance_sq(const _vec2i* a, const _vec2i* b);

	inline void _vec2i_print(_vec2i* v);
	inline void _vec2i_neg(_vec2i* v);
	inline void _vec2i_clamp(_vec2i* v, int min, int max);
	inline void _vec2i_min(const _vec2i* a, const _vec2i* b, _vec2i* out);
	inline void _vec2i_max(const _vec2i* a, const _vec2i* b, _vec2i* out);



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	typedef struct {
		unsigned int x, y;
	} _vec2ui;

	inline void _vec2ui_zero(_vec2ui* v);
	inline void _vec2ui_one(_vec2ui* v);
	inline void _vec2ui_set(_vec2ui* v, unsigned int x, unsigned int y);

	inline void _vec2ui_add(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);
	inline void _vec2ui_sub(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);
	inline void _vec2ui_mul(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);
	inline void _vec2ui_mul_scalar(_vec2ui* v, unsigned int s);
	inline void _vec2ui_div(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);
	inline void _vec2ui_div_scalar(_vec2ui* v, unsigned int s);

	inline float _vec2ui_length(const _vec2ui* v);
	inline float _vec2ui_length_sq(const _vec2ui* v);
	inline float _vec2ui_dot(const _vec2ui* a, const _vec2ui* b);
	inline float _vec2ui_distance(const _vec2ui* a, const _vec2ui* b);
	inline float _vec2ui_distance_sq(const _vec2ui* a, const _vec2ui* b);

	inline void _vec2ui_print(_vec2ui* v);
	inline void _vec2ui_clamp(_vec2ui* v, unsigned int min, unsigned int max);
	inline void _vec2ui_min(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);
	inline void _vec2ui_max(const _vec2ui* a, const _vec2ui* b, _vec2ui* out);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	/////////////////////////////
	/// float
	/////////////////////////////

	inline void _vec2f_set(_vec2f* v, float x, float y) {
		v->x = x;
		v->y = y;
	}
	inline void _vec2f_add(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void _vec2f_sub(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
	}
	inline void _vec2f_mul(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void _vec2f_mul_scalar(_vec2f* v, float s) {
		v->x *= s;
		v->y *= s;
	}
	inline void _vec2f_div(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void _vec2f_div_scalar(_vec2f* v, float s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float _vec2f_length(const _vec2f* v) {
		return sqrtf(v->x * v->x + v->y * v->y);
	}
	inline float _vec2f_length_sq(const _vec2f* v) {
		return v->x * v->x + v->y * v->y;
	}
	inline float _vec2f_dot(const _vec2f* a, const _vec2f* b) {
		return a->x * b->x + a->y * b->y;
	}
	inline float _vec2f_distance(const _vec2f* a, const _vec2f* b) {
		return sqrtf((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}
	inline float _vec2f_distance_sq(const _vec2f* a, const _vec2f* b) {
		return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y);
	}
	inline void _vec2f_lerp(const _vec2f* a, const _vec2f* b, _vec2f* out, float t) {
		out->x = a->x + (b->x - a->x) * t;
		out->y = a->y + (b->y - a->y) * t;
	}

	inline bool _vec2f_normalize(_vec2f* v) {
		float len_sq = (v->x * v->x + v->y * v->y);
		if (len_sq <= VEC_EPSILON) 
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v->x *= len_inv;
		v->y *= len_inv;
		return true;
	}
	inline void _vec2f_print(_vec2f* v) {
		printf("x: %f, y: %f", v->x, v->y);
	}
	inline void _vec2f_neg(_vec2f* v) {
		v->x = -v->x;
		v->y = -v->y;
	}
	inline void _vec2f_inverse(_vec2f* v) {
		v->x = 1.0f / v->x;
		v->y = 1.0f / v->y;
	}
	inline void _vec2f_clamp(_vec2f* v, float min, float max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void _vec2f_min(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void _vec2f_max(const _vec2f* a, const _vec2f* b, _vec2f* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}



	/////////////////////////////
	/// int
	/////////////////////////////

	inline void _vec2i_zero(_vec2i* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void _vec2i_one(_vec2i* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void _vec2i_set(_vec2i* v, int x, int y) {
		v->x = x;
		v->y = y;
	}

	inline void _vec2i_add(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void _vec2i_sub(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
	}
	inline void _vec2i_mul(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void _vec2i_mul_scalar(_vec2i* v, int s) {
		v->x *= s;
		v->y *= s;
	}
	inline void _vec2i_div(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void _vec2i_div_scalar(_vec2i* v, int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float _vec2i_length(const _vec2i* v) {
		return sqrtf((float)(v->x * v->x + v->y * v->y));
	}
	inline float _vec2i_length_sq(const _vec2i* v) {
		return (float)(v->x * v->x + v->y * v->y);
	}
	inline float _vec2i_dot(const _vec2i* a, const _vec2i* b) {
		return (float)(a->x * b->x + a->y * b->y);
	}
	inline float _vec2i_distance(const _vec2i* a, const _vec2i* b) {
		return sqrtf((float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)));
	}
	inline float _vec2i_distance_sq(const _vec2i* a, const _vec2i* b) {
		return (float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}

	inline void _vec2i_print(_vec2i* v) {
		printf("x: %d y: %d", v->x, v->y);
	}
	inline void _vec2i_neg(_vec2i* v) {
		v->x = -v->x;
		v->y = -v->y;
	}
	inline void _vec2i_clamp(_vec2i* v, int min, int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void _vec2i_min(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void _vec2i_max(const _vec2i* a, const _vec2i* b, _vec2i* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	inline void _vec2ui_zero(_vec2ui* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void _vec2ui_one(_vec2ui* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void _vec2ui_set(_vec2ui* v, unsigned int x, unsigned int y) {
		v->x = x;
		v->y = y;
	}

	inline void _vec2ui_add(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void _vec2ui_sub(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = (a->x > b->x) ? (a->x - b->x) : 0;
		out->y = (a->y > b->y) ? (a->y - b->y) : 0;
	}
	inline void _vec2ui_mul(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void _vec2ui_mul_scalar(_vec2ui* v, unsigned int s) {
		v->x *= s;
		v->y *= s;
	}
	inline void _vec2ui_div(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void _vec2ui_div_scalar(_vec2ui* v, unsigned int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float _vec2ui_length(const _vec2ui* v) {
		return sqrtf((float)(v->x * v->x + v->y * v->y));
	}
	inline float _vec2ui_length_sq(const _vec2ui* v) {
		return (float)(v->x * v->x + v->y * v->y);
	}
	inline float _vec2ui_dot(const _vec2ui* a, const _vec2ui* b) {
		return (float)(a->x * b->x + a->y * b->y);
	}
	inline float _vec2ui_distance(const _vec2ui* a, const _vec2ui* b) {
		return sqrtf((float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)));
	}
	inline float _vec2ui_distance_sq(const _vec2ui* a, const _vec2ui* b) {
		return (float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}

	inline void _vec2ui_print(_vec2ui* v) {
		printf("x: %d y: %d", v->x, v->y);
	}
	inline void _vec2ui_clamp(_vec2ui* v, unsigned int min, unsigned int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void _vec2ui_min(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void _vec2ui_max(const _vec2ui* a, const _vec2ui* b, _vec2ui* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}

#endif
#if defined(__cplusplus)
}
#endif