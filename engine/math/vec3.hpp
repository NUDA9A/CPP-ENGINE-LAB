#pragma once

#include <cmath>

namespace engine::math {
	struct Vec3;

	constexpr float dot(const Vec3& a, const Vec3& b) noexcept;
	constexpr Vec3 operator/(const Vec3& a, const float scalar) noexcept;


	struct Vec3 {
		float x{};
		float y{};
		float z{};

		constexpr Vec3& operator+=(const Vec3& b) noexcept {
			x += b.x;
			y += b.y;
			z += b.z;

			return *this;
		}

		constexpr Vec3& operator-=(const Vec3& b) noexcept {
			x -= b.x;
			y -= b.y;
			z -= b.z;

			return *this;
		}

		constexpr Vec3& operator*=(const float scalar) noexcept {
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		constexpr Vec3& operator/=(const float scalar) noexcept {
			x /= scalar;
			y /= scalar;
			z /= scalar;

			return *this;
		}

		constexpr float length_squared() const noexcept {
			return dot(*this, *this);
		}

		float length() const noexcept {
			return std::sqrt(length_squared());
		}

		Vec3 normalized() const noexcept {
			return (*this) / length();
		}
	};

	constexpr Vec3 operator+(const Vec3& a, const Vec3& b) noexcept {
		return { a.x + b.x, a.y + b.y, a.z + b.z };
	}

	constexpr Vec3 operator-(const Vec3& a, const Vec3& b) noexcept {
		return { a.x - b.x, a.y - b.y, a.z - b.z };
	}

	constexpr Vec3 operator*(const Vec3& a, const float scalar) noexcept {
		return { a.x * scalar, a.y * scalar, a.z * scalar };
	}

	constexpr Vec3 operator*(const float scalar, const Vec3& a) noexcept {
		return a * scalar;
	}

	constexpr Vec3 operator/(const Vec3& a, const float scalar) noexcept {
		return { a.x / scalar, a.y / scalar, a.z / scalar };
	}

	constexpr bool operator==(const Vec3& a, const Vec3& b) noexcept {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	constexpr bool operator!=(const Vec3& a, const Vec3& b) noexcept {
		return !(a == b);
	}

	constexpr float dot(const Vec3& a, const Vec3& b) noexcept {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	constexpr Vec3 cross(const Vec3& a, const Vec3& b) noexcept {
		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	constexpr bool near_equal(const float a, const float b, const float eps = 1e-5f) noexcept {
		return (a > b ? a - b : b - a) <= eps;
	}

	constexpr bool near_equal(const Vec3& a, const Vec3& b, const float eps = 1e-5f) noexcept {
		return near_equal(a.x, b.x, eps) && near_equal(a.y, b.y, eps) && near_equal(a.z, b.z, eps);
	}
} // namespace engine::math

