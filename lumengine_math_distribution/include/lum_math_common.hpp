#pragma once
#define LUM_MATH_IMPLEMENTATION

namespace lumm {

	inline constexpr float LUM_PI = 3.14159265358979323846f;
	inline constexpr float LUM_VECTOR_EPSILON = 1e-8f;

	inline constexpr float radians(float degrees) noexcept {
		return degrees * (LUM_PI / 180);
	}
	inline constexpr float degrees(float radians) noexcept {
		return radians * (180 / LUM_PI);
	}
	inline constexpr float inverse(float val) noexcept {
		return 1.0f / val;
	}
 
}