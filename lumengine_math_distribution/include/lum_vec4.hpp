#pragma once
#include "lum_math_common.hpp"
#include <type_traits>
#include <stdio.h>
#include <math.h>
namespace lumm {

	template<typename T>
	concept vector_type = requires { std::is_arithmetic_v<T>; };

	template<vector_type T>
	struct alignas(16) Vec4 {

		T x, y, z, w;

		Vec4() { x = 0; y = 0; z = 0; w = 0; }
		Vec4(T nx, T ny, T nz, T nw) { x = nx; y = nx; z = nz; w = nw; }
		Vec4(T val) { x = val; y = val; z = val; w = val; }

		inline constexpr Vec4 operator+	( const Vec4& other ) noexcept {
			Vec4 _new;
			_new.x = x + other.x;
			_new.y = y + other.y;
			_new.z = z + other.z;
			_new.w = w + other.w;
			return _new;
		}
		inline constexpr void operator+=( const Vec4& other ) noexcept {
			x += other.x; y += other.y; x += other.z; w += other.w;
		}
		inline constexpr Vec4 operator-	( const Vec4& other ) noexcept {
			Vec4 _new;
			_new.x = x - other.x;
			_new.y = y - other.y;
			_new.z = z - other.z;
			_new.w = w - other.w;
			return _new;
		}
		inline constexpr void operator-=( const Vec4& other ) noexcept {
			x -= other.x; y -= other.y; x -= other.z; w -= other.w;
		}
		inline constexpr Vec4 operator*	( const Vec4& other ) noexcept {
			Vec4 _new;
			_new.x = x * other.x;
			_new.y = y * other.y;
			_new.z = z * other.z;
			_new.w = w * other.w;
			return _new;
		}
		inline constexpr Vec4 operator*	( T scalar			) noexcept {
			Vec4 _new;
			_new.x = x * scalar;
			_new.y = y * scalar;
			_new.z = z * scalar;
			_new.w = w * scalar;
			return _new;
		}
		inline constexpr void operator*=( const Vec4& other ) noexcept {
			x *= other.x; y *= other.y; x *= other.z; w *= other.w;
		}
		inline constexpr void operator*=( T scalar			) noexcept {
			x *= scalar; y *= scalar; x *= scalar; w *= scalar;
		}
		inline constexpr Vec4 operator/	( const Vec4& other ) noexcept {
			Vec4 _new;
			_new.x = x / other.x;
			_new.y = y / other.y;
			_new.z = z / other.z;
			_new.w = w / other.w;
			return _new;
		}
		inline constexpr Vec4 operator/	( T scalar			) noexcept {
			Vec4 _new;
			_new.x = x / scalar;
			_new.y = y / scalar;
			_new.z = z / scalar;
			_new.w = w / scalar;
			return _new;
		}
		inline constexpr void operator/=( const Vec4& other ) noexcept {
			x /= other.x; y /= other.y; x /= other.z; w /= other.w;
		}
		inline constexpr void operator/=( T scalar			) noexcept {
			x /= scalar; y /= scalar; x /= scalar; w /= scalar;
		}

	};

	template<vector_type T>
	inline constexpr float length( const Vec4<T>& v ) noexcept {
		return sqrtf(static_cast<float>(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}
	template<vector_type T>
	inline constexpr float length_sq( const Vec4<T>& v ) noexcept {
		return static_cast<float>((v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}
	template<vector_type T>
	inline constexpr float dot( const Vec4<T>& a, const Vec4<T>& b ) noexcept {
		return static_cast<float>(a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}
	template<vector_type T>
	inline constexpr float distance( const Vec4<T>& a, const Vec4<T>& b ) noexcept {
		return
			sqrtf(static_cast<float>(
				(b.x - a.x) * (b.x - a.x) +
				(b.y - a.y) * (b.y - a.y) +
				(b.z - a.z) * (b.z - a.z) +
				(b.w - a.w) * (b.w - a.w)
				));
	}
	template<vector_type T>
	inline constexpr float distance_sq( const Vec4<T>& a, const Vec4<T>& b ) noexcept {
		return static_cast<float>(
			(b.x - a.x) * (b.x - a.x) +
			(b.y - a.y) * (b.y - a.y) +
			(b.z - a.z) * (b.z - a.z) +
			(b.w - a.w) * (b.w - a.w)
			);
	}
	template<vector_type T>
	inline constexpr bool normalize( Vec4<T>& v ) noexcept {
		float len_sq = length_sq(v);
		if (len_sq <= LUM_VECTOR_EPSILON)
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v.x *= len_inv;
		v.y *= len_inv;
		v.z *= len_inv;
		v.w *= len_inv;
		return true;
	}
	template<vector_type T>
	inline constexpr void negate( Vec4<T>& v ) noexcept {
		v.x = -v.x;
		v.y = -v.y;
		v.z = -v.z;
		v.w = -v.w;
	}
	template<vector_type T>
	inline constexpr void inverse( Vec4<T>& v ) noexcept {
		v.x = 1.0f / v.x;
		v.y = 1.0f / v.y;
		v.z = 1.0f / v.z;
		v.w = 1.0f / v.w;
	}
	template<vector_type T>
	inline constexpr void clamp( Vec4<T>& v, float min, float max ) noexcept {
		if (v.x < min) v.x = min;
		else if (v.x > max) v.x = max;

		if (v.y < min) v.y = min;
		else if (v.y > max) v.y = max;

		if (v.z < min) v.z = min;
		else if (v.z > max) v.z = max;

		if (v.w < min) v.w = min;
		else if (v.w > max) v.w = max;
	}

	template<vector_type T>
	inline constexpr Vec4<T> min( Vec4<T> a, const Vec4<T> b ) noexcept {
		Vec4<T> out;
		out.x = (a.x > b.x) ? b.x : a.x;
		out.y = (a.y > b.y) ? b.y : a.y;
		out.z = (a.z > b.z) ? b.z : a.z;
		out.w = (a.w > b.w) ? b.w : a.w;
		return out;
	}

	template<vector_type T>
	inline constexpr Vec4<T> max( Vec4<T> a, const Vec4<T> b ) noexcept {
		Vec4<T> out;
		out.x = (a.x < b.x) ? b.x : a.x;
		out.y = (a.y < b.y) ? b.y : a.y;
		out.z = (a.z < b.z) ? b.z : a.z;
		out.w = (a.w < b.w) ? b.w : a.w;
		return out;
	}

	template<typename T>
	inline constexpr void print( const Vec4<T>& v ) noexcept {
		printf("%g, %g, %g, %g", v.x, v.y, v.z, v.w);
	}

	using Vec4f = Vec4<float>;
	using Vec4i = Vec4<int>;

}