#pragma once
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		float x, y;
	} Vec2;

	void vec2_set(Vec2* v, float x, float y);
	void vec2_add(Vec2* v, const Vec2* other);
	void vec2_sub(Vec2* v, const Vec2* other);
	void vec2_mul_scalar(Vec2* v, float s);
	void vec2_div_scalar(Vec2* v, float s);

	float vec2_length(const Vec2* v);
	float vec2_length_sq(const Vec2* v); // Dlugosc do kwadratu
	float vec2_dot(const Vec2* a, const Vec2* b);
	float vec2_distance(const Vec2* a, const Vec2* b);
	float vec2_distance_sq(const Vec2* a, const Vec2* b); // odleglosc do kwadratu
	Vec2 vec2_lerp(const Vec2* a, const Vec2* b, float t);

	void vec2_normalize(Vec2* v);

	void vec2_print(Vec2* v);

#ifndef LUM_MATH_IMPLEMENTATION
#include <stdio.h>
#include <math.h>

	void vec2_set(Vec2* v, float x, float y) {
		v->x = x;
		v->y = y;
	}
	void vec2_add(Vec2* v, const Vec2* other) {
		v->x += other->x;
		v->y += other->y;
	}
	void vec2_sub(Vec2* v, const Vec2* other) {
		v->x -= other->x;
		v->y -= other->y;
	}
	void vec2_mul_scalar(Vec2* v, float s) {
		v->x *= s;
		v->y *= s;
	}
	void vec2_div_scalar(Vec2* v, float s) {
		v->x /= s;
		v->y /= s;
	}
	void vec2_normalize(Vec2* v) {
		float length = sqrtf(v->x * v->x + v->y * v->y);
		if (length > 0.0f) {
			v->x / length;
			v->y / length;
		}
	}
	void vec2_print(Vec2* v) {
		printf("x: %f, y: %f", v->x, v->y);
	}

	float vec2_length(const Vec2* v) {
		return sqrtf(v->x * v->x + v->y * v->y);
	}
	float vec2_length_sq(const Vec2* v) {
		return v->x * v->x + v->y * v->y;
	}
	float vec2_dot(const Vec2* a, const Vec2* b) {
		return a->x * b->x + a->y * b->y;
	}
	float vec2_distance(const Vec2* a, const Vec2* b) {
		return sqrtf(b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
	}
	float vec2_distance_sq(const Vec2* a, const Vec2* b); // odleglosc do kwadratu
	Vec2 vec2_lerp(const Vec2* a, const Vec2* b, float t);



#endif


#if defined(__cplusplus)
}
#endif