#pragma once

#include "vec3.h"

namespace Maths::Containers {

	template <typename T>
	struct vec4
	{
		T X, Y, Z, W;

		vec4() = default;
		vec4(T scalar);
		vec4(const vec3<T>& vector, T w);
		vec4(T x, T y, T z, T w);

		vec4<T>& Add(const vec4<T>& other);
		vec4<T>& Subtract(const vec4<T>& other);
		vec4<T>& Multiply(const vec4<T>& other);
		vec4<T>& Divide(const vec4<T>& other);
		vec4<T>& Add(T scalar);
		vec4<T>& Subtract(T scalar);
		vec4<T>& Multiply(T scalar);
		vec4<T>& Divide(T scalar);

		bool operator == (const vec4<T>& other);
		bool operator != (const vec4<T>& other);

		vec4<T>& operator += (const vec4<T>& rhs);
		vec4<T>& operator -= (const vec4<T>& rhs);
		vec4<T>& operator *= (const vec4<T>& rhs);
		vec4<T>& operator /= (const vec4<T>& rhs);
		vec4<T>& operator += (T scalar);
		vec4<T>& operator -= (T scalar);
		vec4<T>& operator *= (T scalar);
		vec4<T>& operator /= (T scalar);

		static vec4<T> Cross(const vec4<T>& lhs, const vec4<T>& rhs);
		static T Dot(const vec4<T>& lhs, const vec4<T>& rhs);

		T Magnitude() const;
		vec4<T> Normalise() const;

		friend vec4<T> operator + (vec4<T> lhs, const vec4<T>& rhs)
		{
			return lhs.Add(rhs);
		}

		friend vec4<T> operator - (vec4<T> lhs, const vec4<T>& rhs)
		{
			return lhs.Subtract(rhs);
		}

		friend vec4<T> operator * (vec4<T> lhs, const vec4<T>& rhs)
		{
			return lhs.Multiply(rhs);
		}

		friend vec4<T> operator / (vec4<T> lhs, const vec4<T>& rhs)
		{
			return lhs.Divide(rhs);
		}

		friend vec4<T> operator + (vec4<T> lhs, T scalar)
		{
			return lhs.Add(scalar);
		}

		friend vec4<T> operator - (vec4<T> lhs, T scalar)
		{
			return lhs.Subtract(scalar);
		}

		friend vec4<T> operator * (vec4<T> lhs, T scalar)
		{
			return lhs.Multiply(scalar);
		}

		friend vec4<T> operator / (vec4<T> lhs, T scalar)
		{
			return lhs.Divide(scalar);
		}
	};

	template <typename T>
	vec4<T>::vec4(T scalar) : X(scalar), Y(scalar), Z(scalar), W(scalar)
	{

	}

	template <typename T>
	vec4<T>::vec4(const vec3<T>& vector, T w) : X(vector.X), Y(vector.Y), Z(vector.Z), W(w)
	{

	}

	template <typename T>
	vec4<T>::vec4(T x, T y, T z, T w) : X(x), Y(y), Z(z), W(w)
	{

	}

	template <typename T>
	vec4<T>& vec4<T>::Add(const vec4<T>& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		W += other.W;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Subtract(const vec4<T>& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		W -= other.W;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Multiply(const vec4<T>& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
		W *= other.W;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Divide(const vec4<T>& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
		W /= other.W;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Add(T scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;
		W += scalar;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Subtract(T scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;
		W -= scalar;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Multiply(T scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		W *= scalar;

		return *this;
	}

	template <typename T>
	vec4<T>& vec4<T>::Divide(T scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		W /= scalar;

		return *this;
	}

	template <typename T>
	bool vec4<T>::operator == (const vec4<T>& other)
	{
		return (X == other.X && Y == other.Y && Z == other.Z && W == other.W);
	}

	template <typename T>
	bool vec4<T>::operator != (const vec4<T>& other)
	{
		return !(*this == other);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator += (const vec4<T>& rhs)
	{
		return Add(rhs);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator -= (const vec4<T>& rhs)
	{
		return Subtract(rhs);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator *= (const vec4<T>& rhs)
	{
		return Multiply(rhs);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator /= (const vec4<T>& rhs)
	{
		return Divide(rhs);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator += (T scalar)
	{
		return Add(scalar);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator -= (T scalar)
	{
		return Subtract(scalar);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator *= (T scalar)
	{
		return Multiply(scalar);
	}

	template <typename T>
	vec4<T>& vec4<T>::operator /= (T scalar)
	{
		return Divide(scalar);
	}

	template <typename T>
	vec4<T> vec4<T>::Cross(const vec4<T>& lhs, const vec4<T>& rhs)
	{
		return vec4<T>(vec3<T>::Cross(vec3<T>(lhs.X, lhs.Y, lhs.Z), vec3<T>(rhs.X, rhs.Y, rhs.Z)), 1.0f);
	}

	template <typename T>
	T vec4<T>::Dot(const vec4<T>& lhs, const vec4<T>& rhs)
	{
		return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
	}

	template <typename T>
	T vec4<T>::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z + W * W);
	}

	template <typename T>
	vec4<T> vec4<T>::Normalise() const
	{
		T length = Magnitude();
		return vec4<T>(X / length, Y / length, Z / length, W / length);
	}

}