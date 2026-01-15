#pragma once
#define VEC_EPSILON 1e-8f
#ifdef __cplusplus
extern "C" {
#endif

	/////////////////////////////
	/// float
	/////////////////////////////

	typedef struct alignas(16) {
		float x, y, z;
		float _w;
	} _vec3f;

	inline void _vec3f_zero(_vec3f* v);
	inline void _vec3f_one(_vec3f* v);
	inline void _vec3f_set(_vec3f* v, float x, float y, float z);

	inline void _vec3f_add(const _vec3f* a, const _vec3f* b, _vec3f* out);
	inline void _vec3f_sub(const _vec3f* a, const _vec3f* b, _vec3f* out);
	inline void _vec3f_mul(const _vec3f* a, const _vec3f* b, _vec3f* out);
	inline void _vec3f_mul_scalar(_vec3f* v, float s);
	inline void _vec3f_div(const _vec3f* a, const _vec3f* b, _vec3f* out);
	inline void _vec3f_div_scalar(_vec3f* v, float s);

	inline float _vec3f_length(const _vec3f* v);
	inline float _vec3f_length_sq(const _vec3f* v);
	inline float _vec3f_dot(const _vec3f* a, const _vec3f* b);
	inline float _vec3f_distance(const _vec3f* a, const _vec3f* b);
	inline float _vec3f_distance_sq(const _vec3f* a, const _vec3f* b);
	inline void _vec3f_lerp(const _vec3f* a, const _vec3f* b, _vec3f* out, float t);

	inline bool _vec3f_normalize(_vec3f* v);
	inline void _vec3f_print(_vec3f* v);
	inline void _vec3f_neg(_vec3f* v);
	inline void _vec3f_inverse(_vec3f* v);
	inline void _vec3f_clamp(_vec3f* v, float min, float max);
	inline void _vec3f_min(const _vec3f* a, const _vec3f* b, _vec3f* out);
	inline void _vec3f_max(const _vec3f* a, const _vec3f* b, _vec3f* out);



	/////////////////////////////
	/// int
	/////////////////////////////

	typedef struct alignas(16){
		int x, y, z;
		float _padding;
	} _vec3i;

	inline void _vec3i_zero(_vec3i* v);
	inline void _vec3i_one(_vec3i* v);
	inline void _vec3i_set(_vec3i* v, int x, int y, int z);

	inline void _vec3i_add(const _vec3i* a, const _vec3i* b, _vec3i* out);
	inline void _vec3i_sub(const _vec3i* a, const _vec3i* b, _vec3i* out);
	inline void _vec3i_mul(const _vec3i* a, const _vec3i* b, _vec3i* out);
	inline void _vec3i_mul_scalar(_vec3i* v, int s);
	inline void _vec3i_div(const _vec3i* a, const _vec3i* b, _vec3i* out);
	inline void _vec3i_div_scalar(_vec3i* v, int s);

	inline float _vec3i_length(const _vec3i* v);
	inline float _vec3i_length_sq(const _vec3i* v);
	inline float _vec3i_dot(const _vec3i* a, const _vec3i* b);
	inline float _vec3i_distance(const _vec3i* a, const _vec3i* b);
	inline float _vec3i_distance_sq(const _vec3i* a, const _vec3i* b);

	inline void _vec3i_print(_vec3i* v);
	inline void _vec3i_neg(_vec3i* v);
	inline void _vec3i_clamp(_vec3i* v, int min, int max);
	inline void _vec3i_min(const _vec3i* a, const _vec3i* b, _vec3i* out);
	inline void _vec3i_max(const _vec3i* a, const _vec3i* b, _vec3i* out);



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	typedef struct alignas(16) {
		unsigned int x, y, z;
		float _padding;
	} _vec3ui;

	inline void _vec3ui_zero(_vec3ui* v);
	inline void _vec3ui_one(_vec3ui* v);
	inline void _vec3ui_set(_vec3ui* v, unsigned int x, unsigned int y, unsigned int z);

	inline void _vec3ui_add(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);
	inline void _vec3ui_sub(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);
	inline void _vec3ui_mul(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);
	inline void _vec3ui_mul_scalar(_vec3ui* v, unsigned int s);
	inline void _vec3ui_div(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);
	inline void _vec3ui_div_scalar(_vec3ui* v, unsigned int s);

	inline float _vec3ui_length(const _vec3ui* v);
	inline float _vec3ui_length_sq(const _vec3ui* v);
	inline float _vec3ui_dot(const _vec3ui* a, const _vec3ui* b);
	inline float _vec3ui_distance(const _vec3ui* a, const _vec3ui* b);
	inline float _vec3ui_distance_sq(const _vec3ui* a, const _vec3ui* b);

	inline void _vec3ui_print(_vec3ui* v);
	inline void _vec3ui_clamp(_vec3ui* v, unsigned int min, unsigned int max);
	inline void _vec3ui_min(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);
	inline void _vec3ui_max(const _vec3ui* a, const _vec3ui* b, _vec3ui* out);

#ifdef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	/////////////////////////////
	/// float
	/////////////////////////////
	
	inline void _vec3f_zero(_vec3f* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	inline void _vec3f_one(_vec3f* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
	}
	inline void _vec3f_set(_vec3f* v, float x, float y, float z) {
		v->x = x;
		v->y = y;
		v->z = z;
	}
	inline void _vec3f_add(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
	}
	inline void _vec3f_sub(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
		out->z = a->z - b->z;
	}
	inline void _vec3f_mul(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * b->z;
	}
	inline void _vec3f_mul_scalar(_vec3f* v, float s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
	}
	inline void _vec3f_div(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
	}
	inline void _vec3f_div_scalar(_vec3f* v, float s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
	}

	inline float _vec3f_length(const _vec3f* v) {
		return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
	}
	inline float _vec3f_length_sq(const _vec3f* v) {
		return v->x * v->x + v->y * v->y + v->z * v->z;
	}
	inline float _vec3f_dot(const _vec3f* a, const _vec3f* b) {
		return a->x * b->x + a->y * b->y + a->z * b->z;
	}
	inline float _vec3f_distance(const _vec3f* a, const _vec3f* b) {
		return 
			sqrtf(
			(b->x - a->x) * (b->x - a->x) + 
			(b->y - a->y) * (b->y - a->y) + 
			(b->z - a->z) * (b->z - a->z)
		);
	}
	inline float _vec3f_distance_sq(const _vec3f* a, const _vec3f* b) {
		return 
			(b->x - a->x) * (b->x - a->x) + 
			(b->y - a->y) * (b->y - a->y) + 
			(b->z - a->z) * (b->z - a->z);
	}
	inline void _vec3f_lerp(const _vec3f* a, const _vec3f* b, _vec3f* out, float t) {
		out->x = a->x + (b->x - a->x) * t;
		out->y = a->y + (b->y - a->y) * t;
		out->z = a->z + (b->z - a->z) * t;
	}

	inline bool _vec3f_normalize(_vec3f* v) {
		float len_sq = (v->x * v->x + v->y * v->y + v->z * v->z);
		if (len_sq <= VEC_EPSILON)
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v->x *= len_inv;
		v->y *= len_inv;
		v->z *= len_inv;
		return true;
	}
	inline void _vec3f_print(_vec3f* v) {
		printf("x: %f, y: %f, z: %f", v->x, v->y, v->z);
	}
	inline void _vec3f_neg(_vec3f* v) {
		v->x = -v->x;
		v->y = -v->y;
		v->z = -v->z;
	}
	inline void _vec3f_inverse(_vec3f* v) {
		v->x = 1.0f / v->x;
		v->y = 1.0f / v->y;
		v->z = 1.0f / v->z;
	}
	inline void _vec3f_clamp(_vec3f* v, float min, float max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;
	}
	inline void _vec3f_min(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
	}
	inline void _vec3f_max(const _vec3f* a, const _vec3f* b, _vec3f* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
	}



	/////////////////////////////
	/// int
	/////////////////////////////

	inline void _vec3i_zero(_vec3i* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	inline void _vec3i_one(_vec3i* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
	}
	inline void _vec3i_set(_vec3i* v, int x, int y, int z) {
		v->x = x;
		v->y = y;
		v->z = z;
	}

	inline void _vec3i_add(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
	}
	inline void _vec3i_sub(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = a->x - b->x;
		out->y = a->y - b->y;
		out->z = a->z - b->z;
	}
	inline void _vec3i_mul(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * a->z;
	}
	inline void _vec3i_mul_scalar(_vec3i* v, int s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
	}
	inline void _vec3i_div(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
	}
	inline void _vec3i_div_scalar(_vec3i* v, int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
	}

	inline float _vec3i_length(const _vec3i* v) {
		return 
			sqrtf((float)(v->x * v->x + v->y * v->y + v->z * v->z));
	}
	inline float _vec3i_length_sq(const _vec3i* v) {
		return (float)(v->x * v->x + v->y * v->y + v->z * v->z);
	}
	inline float _vec3i_dot(const _vec3i* a, const _vec3i* b) {
		return (float)(a->x * b->x + a->y * b->y + a->z * b->z);
	}
	inline float _vec3i_distance(const _vec3i* a, const _vec3i* b) {
		return 
			sqrtf(
				(float)(
					(b->x - a->x) * (b->x - a->x) + 
					(b->y - a->y) * (b->y - a->y) + 
					(b->z - a->z) * (b->z - a->z)
					)
			);
	}
	inline float _vec3i_distance_sq(const _vec3i* a, const _vec3i* b) {
		return 
			(float)(
				(b->x - a->x) * (b->x - a->x) + 
				(b->y - a->y) * (b->y - a->y) +
				(b->z - a->z) * (b->z - a->z)
				);
	}

	inline void _vec3i_print(_vec3i* v) {
		printf("x: %d, y: %d, z: %d", v->x, v->y, v->z);
	}
	inline void _vec3i_neg(_vec3i* v) {
		v->x = -v->x;
		v->y = -v->y;
		v->z = -v->z;
	}
	inline void _vec3i_clamp(_vec3i* v, int min, int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;
	}
	inline void _vec3i_min(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
	}
	inline void _vec3i_max(const _vec3i* a, const _vec3i* b, _vec3i* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
	}



	/////////////////////////////
	/// unsigned int
	/////////////////////////////

	inline void _vec3ui_zero(_vec3ui* v) {
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	inline void _vec3ui_one(_vec3ui* v) {
		v->x = 1;
		v->y = 1;
		v->z = 1;
	}
	inline void _vec3ui_set(_vec3ui* v, unsigned int x, unsigned int y, unsigned int z) {
		v->x = x;
		v->y = y;
		v->z = z;
	}

	inline void _vec3ui_add(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = a->x + b->x;
		out->y = a->y + b->y;
		out->z = a->z + b->z;
	}
	inline void _vec3ui_sub(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = (a->x > b->x) ? (a->x - b->x) : 0;
		out->y = (a->y > b->y) ? (a->y - b->y) : 0;
		out->z = (a->y > b->z) ? (a->z - b->z) : 0;
	}
	inline void _vec3ui_mul(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = a->x * b->x;
		out->y = a->y * b->y;
		out->z = a->z * b->z;
	}
	inline void _vec3ui_mul_scalar(_vec3ui* v, unsigned int s) {
		v->x *= s;
		v->y *= s;
		v->z *= s;
	}
	inline void _vec3ui_div(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = a->x / b->x;
		out->y = a->y / b->y;
		out->z = a->z / b->z;
	}
	inline void _vec3ui_div_scalar(_vec3ui* v, unsigned int s) {
		if (s == 0) return;
		v->x /= s;
		v->y /= s;
		v->z /= s;
	}

	inline float _vec3ui_length(const _vec3ui* v) {
		return 
			sqrtf((float)(v->x * v->x + v->y * v->y + v->z * v->z));
	}
	inline float _vec3ui_length_sq(const _vec3ui* v) {
		return (float)(v->x * v->x + v->y * v->y + v->z * v->z);
	}
	inline float _vec3ui_dot(const _vec3ui* a, const _vec3ui* b) {
		return (float)(a->x * b->x + a->y * b->y + a->z * b->z);
	}
	inline float _vec3ui_distance(const _vec3ui* a, const _vec3ui* b) {
		return 
			sqrtf(
				(float)(
					(b->x - a->x) * (b->x - a->x) + 
					(b->y - a->y) * (b->y - a->y) +
					(b->z - a->z) * (b->z - a->z)
					)
			); 
	}
	inline float _vec3ui_distance_sq(const _vec3ui* a, const _vec3ui* b) {
		return 
			(float)(
				(b->x - a->x) * (b->x - a->x) + 
				(b->y - a->y) * (b->y - a->y) +
				(b->z - a->z) * (b->z - a->z)
				);
	}

	inline void _vec3ui_print(_vec3ui* v) {
		printf("x: %d, y: %d, z: %d", v->x, v->y, v->z);
	}
	inline void _vec3ui_clamp(_vec3ui* v, unsigned int min, unsigned int max) {
		if (v->x < min) v->x = min;
		else if (v->x > max) v->x = max;

		if (v->y < min) v->y = min;
		else if (v->y > max) v->y = max;

		if (v->z < min) v->z = min;
		else if (v->z > max) v->z = max;
	}
	inline void _vec3ui_min(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = (a->x > b->x) ? b->x : a->x;
		out->y = (a->y > b->y) ? b->y : a->y;
		out->z = (a->z > b->z) ? b->z : a->z;
	}
	inline void _vec3ui_max(const _vec3ui* a, const _vec3ui* b, _vec3ui* out) {
		out->x = (a->x < b->x) ? b->x : a->x;
		out->y = (a->y < b->y) ? b->y : a->y;
		out->z = (a->z < b->z) ? b->z : a->z;
	}

#endif
#if defined(__cplusplus)
}
#endif