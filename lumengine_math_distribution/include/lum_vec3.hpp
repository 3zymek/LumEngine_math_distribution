#pragma once
#include "lum_math_common.hpp"
#include <type_traits>
#include <stdio.h>
#include <math.h>
namespace lumm {

	template<typename T>
	concept vector_type = requires { std::is_arithmetic_v<T>; };

	template<vector_type T>
	struct alignas(16) Vec3 {

		T x, y, z;

		Vec3( )					{ x = 0; y = 0; z = 0; }
		Vec3( T nx, T ny, T nz ){ x = nx; y = nx; z = nz; }
		Vec3( T val )			{ x = val; y = val; z = val; }

		inline constexpr Vec3 operator+	(const Vec3& other	) noexcept {
			Vec3 _new;
			_new.x = x + other.x;
			_new.y = y + other.y;
			_new.z = z + other.z;
			return _new;
		}
		inline constexpr void operator+=( const Vec3& other ) noexcept {
			x += other.x; y += other.y; x += other.z;
		}
		inline constexpr Vec3 operator-	( const Vec3& other ) noexcept {
			Vec3 _new;
			_new.x = x - other.x;
			_new.y = y - other.y;
			_new.z = z - other.z;
			return _new;
		}
		inline constexpr void operator-=( const Vec3& other ) noexcept {
			x -= other.x; y -= other.y; x -= other.z;
		}
		inline constexpr Vec3 operator*	( const Vec3& other ) noexcept {
			Vec3 _new;
			_new.x = x * other.x;
			_new.y = y * other.y;
			_new.z = z * other.z;
			return _new;
		}
		inline constexpr Vec3 operator*	( T scalar			) noexcept {
			Vec3 _new;
			_new.x = x * scalar;
			_new.y = y * scalar;
			_new.z = z * scalar;
			return _new;
		}
		inline constexpr void operator*=( const Vec3& other ) noexcept {
			x *= other.x; y *= other.y; x *= other.z;
		}
		inline constexpr void operator*=( T scalar			) noexcept {
			x *= scalar; y *= scalar; x *= scalar;
		}
		inline constexpr Vec3 operator/	( const Vec3& other ) noexcept {
			Vec3 _new;
			_new.x = x / other.x;
			_new.y = y / other.y;
			_new.z = z / other.z;
			return _new;
		}
		inline constexpr Vec3 operator/	( T scalar			) noexcept {
			Vec3 _new;
			_new.x = x / scalar;
			_new.y = y / scalar;
			_new.z = z / scalar;
			return _new;
		}
		inline constexpr void operator/=( const Vec3& other ) noexcept {
			x /= other.x; y /= other.y; x /= other.z;
		}
		inline constexpr void operator/=( T scalar			) {
			x /= scalar; y /= scalar; x /= scalar;
		}

	};

	template<vector_type T>
	inline constexpr float length( const Vec3<T>& v ) noexcept {
		return sqrtf(static_cast<float>(v.x * v.x + v.y * v.y + v.z * v.z));
	}
	template<vector_type T>
	inline constexpr float length_sq( const Vec3<T>& v ) noexcept {
		return static_cast<float>((v.x * v.x + v.y * v.y + v.z * v.z));
	}
	template<vector_type T>
	inline constexpr float dot( const Vec3<T>& a, const Vec3<T>& b ) noexcept {
		return static_cast<float>(a.x * b.x + a.y * b.y + a.z * b.z);
	}
	template<vector_type T>
	inline constexpr float distance( const Vec3<T>& a, const Vec3<T>& b ) noexcept {
		return
			sqrtf(static_cast<float>(
				(b.x - a.x) * (b.x - a.x) +
				(b.y - a.y) * (b.y - a.y) +
				(b.z - a.z) * (b.z - a.z)
			));
	}
	template<vector_type T>
	inline constexpr float distance_sq( const Vec3<T>& a, const Vec3<T>& b ) noexcept {
		return static_cast<float>(
			(b.x - a.x) * (b.x - a.x) +
			(b.y - a.y) * (b.y - a.y) +
			(b.z - a.z) * (b.z - a.z));
	}
	template<vector_type T>
	inline constexpr bool normalize( Vec3<T>& v ) noexcept {
		float len_sq = length_sq(v);
		if (len_sq <= LUM_VECTOR_EPSILON)
			return false;

		float len_inv = 1.0f / sqrtf(len_sq);

		v.x *= len_inv;
		v.y *= len_inv;
		v.z *= len_inv;
		return true;
	}
	template<vector_type T>
	inline constexpr void negate( Vec3<T>& v ) noexcept {
		v.x = -v.x;
		v.y = -v.y;
		v.z = -v.z;
	}
	template<vector_type T>
	inline constexpr void inverse( Vec3<T>& v ) noexcept {
		v.x = 1.0f / v.x;
		v.y = 1.0f / v.y;
		v.z = 1.0f / v.z;
	}
	template<vector_type T>
	inline constexpr void clamp( Vec3<T>& v, float min, float max ) noexcept {
		if (v.x < min) v.x = min;
		else if (v.x > max) v.x = max;

		if (v.y < min) v.y = min;
		else if (v.y > max) v.y = max;

		if (v.z < min) v.z = min;
		else if (v.z > max) v.z = max;
	}

	template<vector_type T>
	inline constexpr Vec3<T> min( Vec3<T> a, const Vec3<T> b ) noexcept {
		Vec3<T> out;
		out.x = (a.x > b.x) ? b.x : a.x;
		out.y = (a.y > b.y) ? b.y : a.y;
		out.z = (a.z > b.z) ? b.z : a.z;
		return out;
	}

	template<vector_type T>
	inline constexpr Vec3<T> max( Vec3<T> a, const Vec3<T> b ) noexcept {
		Vec3<T> out;
		out.x = (a.x < b.x) ? b.x : a.x;
		out.y = (a.y < b.y) ? b.y : a.y;
		out.z = (a.z < b.z) ? b.z : a.z;
		return out;
	}

	template<typename T>
	inline constexpr void print( const Vec3<T>& v ) noexcept {
		printf("%g, %g, %g", v.x, v.y, v.z);
	}

	using Vec3f = Vec3<float>;
	using Vec3i = Vec3<int>;

}