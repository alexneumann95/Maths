#pragma once

namespace Maths::Containers {

	template <typename T>
	struct vec2
	{
		T X, Y;

		vec2() = default;
		vec2(T scalar);
		vec2(T x, T y);

		vec2<T>& Add(const vec2<T>& other);
		vec2<T>& Subtract(const vec2<T>& other);
		vec2<T>& Multiply(const vec2<T>& other);
		vec2<T>& Divide(const vec2<T>& other);
		vec2<T>& Add(T scalar);
		vec2<T>& Subtract(T scalar);
		vec2<T>& Multiply(T scalar);
		vec2<T>& Divide(T scalar);

		bool operator == (const vec2<T>& other);
		bool operator != (const vec2<T>& other);

		vec2<T>& operator += (const vec2<T>& rhs);
		vec2<T>& operator -= (const vec2<T>& rhs);
		vec2<T>& operator *= (const vec2<T>& rhs);
		vec2<T>& operator /= (const vec2<T>& rhs);
		vec2<T>& operator += (T scalar);
		vec2<T>& operator -= (T scalar);
		vec2<T>& operator *= (T scalar);
		vec2<T>& operator /= (T scalar);

		T Magnitude() const;
		vec2<T> Normalise() const;

		friend vec2<T> operator + (vec2<T> lhs, const vec2<T>& rhs)
		{
			return lhs.Add(rhs);
		}

		friend vec2<T> operator - (vec2<T> lhs, const vec2<T>& rhs)
		{
			return lhs.Subtract(rhs);
		}

		friend vec2<T> operator * (vec2<T> lhs, const vec2<T>& rhs)
		{
			return lhs.Multiply(rhs);
		}

		friend vec2<T> operator / (vec2<T> lhs, const vec2<T>& rhs)
		{
			return lhs.Divide(rhs);
		}

		friend vec2<T> operator + (vec2<T> lhs, T scalar)
		{
			return lhs.Add(scalar);
		}

		friend vec2<T> operator - (vec2<T> lhs, T scalar)
		{
			return lhs.Subtract(scalar);
		}

		friend vec2<T> operator * (vec2<T> lhs, T scalar)
		{
			return lhs.Multiply(scalar);
		}

		friend vec2<T> operator / (vec2<T> lhs, T scalar)
		{
			return lhs.Divide(scalar);
		}
	};

	template <typename T>
	vec2<T>::vec2(T scalar) : X(scalar), Y(scalar)
	{

	}

	template <typename T>
	vec2<T>::vec2(T x, T y) : X(x), Y(y)
	{

	}

	template <typename T>
	vec2<T>& vec2<T>::Add(const vec2<T>& other)
	{
		X += other.X;
		Y += other.Y;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Subtract(const vec2<T>& other)
	{
		X -= other.X;
		Y -= other.Y;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Multiply(const vec2<T>& other)
	{
		X *= other.X;
		Y *= other.Y;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Divide(const vec2<T>& other)
	{
		X /= other.X;
		Y /= other.Y;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Add(T scalar)
	{
		X += scalar;
		Y += scalar;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Subtract(T scalar)
	{
		X -= scalar;
		Y -= scalar;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Multiply(T scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}

	template <typename T>
	vec2<T>& vec2<T>::Divide(T scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}

	template <typename T>
	bool vec2<T>::operator == (const vec2<T>& other)
	{
		return (X == other.X && Y == other.Y);
	}

	template <typename T>
	bool vec2<T>::operator != (const vec2<T>& other)
	{
		return !(*this == other);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator += (const vec2<T>& rhs)
	{
		return Add(rhs);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator -= (const vec2<T>& rhs)
	{
		return Subtract(rhs);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator *= (const vec2<T>& rhs)
	{
		return Multiply(rhs);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator /= (const vec2<T>& rhs)
	{
		return Divide(rhs);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator += (T scalar)
	{
		return Add(scalar);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator -= (T scalar)
	{
		return Subtract(scalar);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator *= (T scalar)
	{
		return Multiply(scalar);
	}

	template <typename T>
	vec2<T>& vec2<T>::operator /= (T scalar)
	{
		return Divide(scalar);
	}

	template <typename T>
	T vec2<T>::Magnitude() const
	{
		return sqrt(X * X + Y * Y);
	}

	template <typename T>
	vec2<T> vec2<T>::Normalise() const
	{
		T length = Magnitude();
		return vec2(X / length, Y / length);
	}

}