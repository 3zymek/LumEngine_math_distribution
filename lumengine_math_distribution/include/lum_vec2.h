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
	} vec2f;

	inline void vec2f_zero(vec2f* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void vec2f_one(vec2f* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void vec2f_set(vec2f* v, float x, float y);

	inline void vec2f_add(const vec2f* a, const vec2f* b, vec2f* out);
	inline void vec2f_sub(const vec2f* a, const vec2f* b, vec2f* out);
	inline void vec2f_mul(const vec2f* a, const vec2f* b, vec2f* out);
	inline void vec2f_mul_scalar(vec2f* v, float s);
	inline void vec2f_div(const vec2f* a, const vec2f* b, vec2f* out);
	inline void vec2f_div_scalar(vec2f* v, float s);

	inline float vec2f_length(const vec2f* v);
	inline float vec2f_length_sq(const vec2f* v);
	inline float vec2f_dot(const vec2f* a, const vec2f* b);
	inline float vec2f_distance(const vec2f* a, const vec2f* b);
	inline float vec2f_distance_sq(const vec2f* a, const vec2f* b);
	inline void vec2f_lerp(const vec2f* a, const vec2f* b, vec2f* out, float t);

	inline bool vec2f_normalize(vec2f* v);
	inline void vec2f_print(vec2f* v);
	inline void vec2f_neg(vec2f* v);
	inline void vec2f_inverse(vec2f* v);
	inline void vec2f_clamp(vec2f* v, float min, float max);
	inline void vec2f_min(const vec2f* a, const vec2f* b, vec2f* out);
	inline void vec2f_max(const vec2f* a, const vec2f* b, vec2f* out);



	/////////////////////////////
	/// int
	/////////////////////////////

	typedef struct {
		int x, y;
	} vec2i;

	inline void vec2i_zero(vec2i* v);
	inline void vec2i_one(vec2i* v);
	inline void vec2i_set(vec2i* v, int x, int y);

	inline void vec2i_add(const vec2i* a, const vec2i* b, vec2i* out);
	inline void vec2i_sub(const vec2i* a, const vec2i* b, vec2i* out);
	inline void vec2i_mul(const vec2i* a, const vec2i* b, vec2i* out);
	inline void vec2i_mul_scalar(vec2i* v, int s);
	inline void vec2i_div(const vec2i* a, const vec2i* b, vec2i* out);
	inline void vec2i_div_scalar(vec2i* v, int s);

	inline float vec2i_length(const vec2i* v);
	inline float vec2i_length_sq(const vec2i* v);
	inline float vec2i_dot(const vec2i* a, const vec2i* b);
	inline float vec2i_distance(const vec2i* a, const vec2i* b);
	inline float vec2i_distance_sq(const vec2i* a, const vec2i* b);

	inline void vec2i_print(vec2i* v);
	inline void vec2i_neg(vec2i* v);
	inline void vec2i_clamp(vec2i* v, int min, int max);
	inline void vec2i_min(const vec2i* a, const vec2i* b, vec2i* out);
	inline void vec2i_max(const vec2i* a, const vec2i* b, vec2i* out);



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	typedef struct {
		unsigned int x, y;
	} vec2ui;

	inline void vec2ui_zero(vec2ui* v);
	inline void vec2ui_one(vec2ui* v);
	inline void vec2ui_set(vec2ui* v, unsigned int x, unsigned int y);

	inline void vec2ui_add(const vec2ui* a, const vec2ui* b, vec2ui* out);
	inline void vec2ui_sub(const vec2ui* a, const vec2ui* b, vec2ui* out);
	inline void vec2ui_mul(const vec2ui* a, const vec2ui* b, vec2ui* out);
	inline void vec2ui_mul_scalar(vec2ui* v, unsigned int s);
	inline void vec2ui_div(const vec2ui* a, const vec2ui* b, vec2ui* out);
	inline void vec2ui_div_scalar(vec2ui* v, unsigned int s);

	inline float vec2ui_length(const vec2ui* v);
	inline float vec2ui_length_sq(const vec2ui* v);
	inline float vec2ui_dot(const vec2ui* a, const vec2ui* b);
	inline float vec2ui_distance(const vec2ui* a, const vec2ui* b);
	inline float vec2ui_distance_sq(const vec2ui* a, const vec2ui* b);

	inline void vec2ui_print(vec2ui* v);
	inline void vec2ui_clamp(vec2ui* v, unsigned int min, unsigned int max);
	inline void vec2ui_min(const vec2ui* a, const vec2ui* b, vec2ui* out);
	inline void vec2ui_max(const vec2ui* a, const vec2ui* b, vec2ui* out);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	/////////////////////////////
	/// float
	/////////////////////////////

	inline void vec2f_set(vec2f* v, float x, float y) {
		v->x = x;
		v->y = y;
	}
	inline void vec2f_add(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void vec2f_sub(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
	}
	inline void vec2f_mul(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void vec2f_mul_scalar(vec2f* v, float s) {
		v->x *= s;
		v->y *= s;
	}
	inline void vec2f_div(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void vec2f_div_scalar(vec2f* v, float s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float vec2f_length(const vec2f* v) {
		return sqrtf(v->x * v->x + v->y * v->y);
	}
	inline float vec2f_length_sq(const vec2f* v) {
		return v->x * v->x + v->y * v->y;
	}
	inline float vec2f_dot(const vec2f* a, const vec2f* b) {
		return a->x * b->x + a->y * b->y;
	}
	inline float vec2f_distance(const vec2f* a, const vec2f* b) {
		return sqrtf((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}
	inline float vec2f_distance_sq(const vec2f* a, const vec2f* b) {
		return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y);
	}
	inline void vec2f_lerp(const vec2f* a, const vec2f* b, vec2f* out, float t) {
		out->x = a->x + (b->x - a->x) * t;
		out->y = a->y + (b->y - a->y) * t;
	}

	inline bool vec2f_normalize(vec2f* v) {
		float len_sq = (v->x * v->x + v->y * v->y);
		if (len_sq <= VEC_EPSILON) 
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v->x *= len_inv;
		v->y *= len_inv;
		return true;
	}
	inline void vec2f_print(vec2f* v) {
		printf("x: %f, y: %f", v->x, v->y);
	}
	inline void vec2f_neg(vec2f* v) {
		v->x = -v->x;
		v->y = -v->y;
	}
	inline void vec2f_inverse(vec2f* v) {
		v->x = 1.0f / v->x;
		v->y = 1.0f / v->y;
	}
	inline void vec2f_clamp(vec2f* v, float min, float max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void vec2f_min(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void vec2f_max(const vec2f* a, const vec2f* b, vec2f* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}



	/////////////////////////////
	/// int
	/////////////////////////////

	inline void vec2i_zero(vec2i* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void vec2i_one(vec2i* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void vec2i_set(vec2i* v, int x, int y) {
		v->x = x;
		v->y = y;
	}

	inline void vec2i_add(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void vec2i_sub(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
	}
	inline void vec2i_mul(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void vec2i_mul_scalar(vec2i* v, int s) {
		v->x *= s;
		v->y *= s;
	}
	inline void vec2i_div(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void vec2i_div_scalar(vec2i* v, int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float vec2i_length(const vec2i* v) {
		return sqrtf((float)(v->x * v->x + v->y * v->y));
	}
	inline float vec2i_length_sq(const vec2i* v) {
		return (float)(v->x * v->x + v->y * v->y);
	}
	inline float vec2i_dot(const vec2i* a, const vec2i* b) {
		return (float)(a->x * b->x + a->y * b->y);
	}
	inline float vec2i_distance(const vec2i* a, const vec2i* b) {
		return sqrtf((float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)));
	}
	inline float vec2i_distance_sq(const vec2i* a, const vec2i* b) {
		return (float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}

	inline void vec2i_print(vec2i* v) {
		printf("x: %d y: %d", v->x, v->y);
	}
	inline void vec2i_neg(vec2i* v) {
		v->x = -v->x;
		v->y = -v->y;
	}
	inline void vec2i_clamp(vec2i* v, int min, int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void vec2i_min(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void vec2i_max(const vec2i* a, const vec2i* b, vec2i* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	inline void vec2ui_zero(vec2ui* v) {
		v->x = 0;
		v->y = 0;
	}
	inline void vec2ui_one(vec2ui* v) {
		v->x = 1;
		v->y = 1;
	}
	inline void vec2ui_set(vec2ui* v, unsigned int x, unsigned int y) {
		v->x = x;
		v->y = y;
	}

	inline void vec2ui_add(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
	}
	inline void vec2ui_sub(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = (a->x > b->x) ? (a->x - b->x) : 0;
		out->y = (a->y > b->y) ? (a->y - b->y) : 0;
	}
	inline void vec2ui_mul(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
	}
	inline void vec2ui_mul_scalar(vec2ui* v, unsigned int s) {
		v->x *= s;
		v->y *= s;
	}
	inline void vec2ui_div(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
	}
	inline void vec2ui_div_scalar(vec2ui* v, unsigned int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
	}

	inline float vec2ui_length(const vec2ui* v) {
		return sqrtf((float)(v->x * v->x + v->y * v->y));
	}
	inline float vec2ui_length_sq(const vec2ui* v) {
		return (float)(v->x * v->x + v->y * v->y);
	}
	inline float vec2ui_dot(const vec2ui* a, const vec2ui* b) {
		return (float)(a->x * b->x + a->y * b->y);
	}
	inline float vec2ui_distance(const vec2ui* a, const vec2ui* b) {
		return sqrtf((float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)));
	}
	inline float vec2ui_distance_sq(const vec2ui* a, const vec2ui* b) {
		return (float)((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}

	inline void vec2ui_print(vec2ui* v) {
		printf("x: %d y: %d", v->x, v->y);
	}
	inline void vec2ui_clamp(vec2ui* v, unsigned int min, unsigned int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;
	}
	inline void vec2ui_min(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
	}
	inline void vec2ui_max(const vec2ui* a, const vec2ui* b, vec2ui* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
	}

#endif
#if defined(__cplusplus)
}
#endif