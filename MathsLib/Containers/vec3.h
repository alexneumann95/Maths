#pragma once

namespace Maths::Containers {

	template <typename T>
	struct vec3
	{
		T X, Y, Z;

		vec3() = default;
		vec3(T scalar);
		vec3(T x, T y, T z);

		vec3<T>& Add(const vec3<T>& other);
		vec3<T>& Subtract(const vec3<T>& other);
		vec3<T>& Multiply(const vec3<T>& other);
		vec3<T>& Divide(const vec3<T>& other);
		vec3<T>& Add(T scalar);
		vec3<T>& Subtract(T scalar);
		vec3<T>& Multiply(T scalar);
		vec3<T>& Divide(T scalar);

		bool operator == (const vec3<T>& other);
		bool operator != (const vec3<T>& other);

		vec3<T>& operator += (const vec3<T>& rhs);
		vec3<T>& operator -= (const vec3<T>& rhs);
		vec3<T>& operator *= (const vec3<T>& rhs);
		vec3<T>& operator /= (const vec3<T>& rhs);
		vec3<T>& operator += (T scalar);
		vec3<T>& operator -= (T scalar);
		vec3<T>& operator *= (T scalar);
		vec3<T>& operator /= (T scalar);

		static vec3<T> Cross(const vec3<T>& lhs, const vec3<T>& rhs);
		static T Dot(const vec3<T>& lhs, const vec3<T>& rhs);

		T Magnitude() const;
		vec3<T> Normalise() const;

		friend vec3<T> operator + (vec3<T> lhs, const vec3<T>& rhs)
		{
			return lhs.Add(rhs);
		}

		friend vec3<T> operator - (vec3<T> lhs, const vec3<T>& rhs)
		{
			return lhs.Subtract(rhs);
		}

		friend vec3<T> operator * (vec3<T> lhs, const vec3<T>& rhs)
		{
			return lhs.Multiply(rhs);
		}

		friend vec3<T> operator / (vec3<T> lhs, const vec3<T>& rhs)
		{
			return lhs.Divide(rhs);
		}

		friend vec3<T> operator + (vec3<T> lhs, T scalar)
		{
			return lhs.Add(scalar);
		}

		friend vec3<T> operator - (vec3<T> lhs, T scalar)
		{
			return lhs.Subtract(scalar);
		}

		friend vec3<T> operator * (vec3<T> lhs, T scalar)
		{
			return lhs.Multiply(scalar);
		}

		friend vec3<T> operator / (vec3<T> lhs, T scalar)
		{
			return lhs.Divide(scalar);
		}

		friend bool operator == (const vec3<T>& lhs, const vec3<T>& rhs)
		{
			return (lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z);
		}

		friend bool operator != (const vec3<T>& lhs, const vec3<T>& rhs)
		{
			return !(lhs == rhs);
		}
	};

	template <typename T>
	vec3<T>::vec3(T scalar) : X(scalar), Y(scalar), Z(scalar)
	{

	}

	template <typename T>
	vec3<T>::vec3(T x, T y, T z) : X(x), Y(y), Z(z)
	{

	}

	template <typename T>
	vec3<T>& vec3<T>::Add(const vec3<T>& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Subtract(const vec3<T>& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Multiply(const vec3<T>& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Divide(const vec3<T>& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Add(T scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Subtract(T scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Multiply(T scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;

		return *this;
	}

	template <typename T>
	vec3<T>& vec3<T>::Divide(T scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;

		return *this;
	}

	template <typename T>
	bool vec3<T>::operator == (const vec3<T>& other)
	{
		return (X == other.X && Y == other.Y && Z == other.Z);
	}

	template <typename T>
	bool vec3<T>::operator != (const vec3<T>& other)
	{
		return !(*this == other);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator += (const vec3<T>& rhs)
	{
		return Add(rhs);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator -= (const vec3<T>& rhs)
	{
		return Subtract(rhs);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator *= (const vec3<T>& rhs)
	{
		return Multiply(rhs);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator /= (const vec3<T>& rhs)
	{
		return Divide(rhs);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator += (T scalar)
	{
		return Add(scalar);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator -= (T scalar)
	{
		return Subtract(scalar);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator *= (T scalar)
	{
		return Multiply(scalar);
	}

	template <typename T>
	vec3<T>& vec3<T>::operator /= (T scalar)
	{
		return Divide(scalar);
	}

	template <typename T>
	vec3<T> vec3<T>::Cross(const vec3<T>& lhs, const vec3<T>& rhs)
	{
		vec3<T> result;
		result.X = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
		result.Y = lhs.Z * rhs.X - lhs.X * rhs.Z;
		result.Z = lhs.X * rhs.Y - lhs.Y * rhs.X;
		return result;
	}

	template <typename T>
	T vec3<T>::Dot(const vec3<T>& lhs, const vec3<T>& rhs)
	{
		return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
	}

	template <typename T>
	T vec3<T>::Magnitude() const
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	template <typename T>
	vec3<T> vec3<T>::Normalise() const
	{
		T length = Magnitude();
		return vec3<T>(X / length, Y / length, Z / length);
	}

}