#pragma once

#include "vec3.h"
#include "mat4.h"

#include <cstring>

namespace Maths::Containers {

	template <typename T>
	struct mat3
	{
		union
		{
			T Elements[9];
			vec3<T> Cols[3];
		};

		mat3();
		mat3(T diagonal);
		mat3(const vec3<T>& col0, const vec3<T>& col1, const vec3<T>& col2);
		mat3(const mat4<T>& matrix);

		mat3<T>& Multiply(const mat3<T>& other);

		mat3<T>& operator *= (const mat3<T>& other);

		static mat3<T> Identity();
		static mat3<T> Transpose(const mat3<T>& matrix);
		static mat3<T> Inverse(const mat3<T>& matrix);

		friend mat3<T> operator * (mat3<T> lhs, const mat3<T>& rhs)
		{
			return lhs.Multiply(rhs);
		}

		friend std::ostream& operator << (std::ostream& os, const mat3<T>& matrix)
		{
			for (int i = 0; i < 9; i++)
			{
				os << matrix.Elements[i] << "\t";
				if (i == 2 || i == 5 || i == 8)
					os << "\n";
			}
			return os;
		}
	};

	template <typename T>
	mat3<T>::mat3()
	{
		memset(Elements, 0, 9 * sizeof(T));
	}

	template <typename T>
	mat3<T>::mat3(T diagonal)
	{
		memset(Elements, 0, 9 * sizeof(T));
		Elements[0] = diagonal;
		Elements[4] = diagonal;
		Elements[8] = diagonal;
	}

	template <typename T>
	mat3<T>::mat3(const vec3<T>& col0, const vec3<T>& col1, const vec3<T>& col2)
	{
		Cols[0] = col0;
		Cols[1] = col1;
		Cols[2] = col2;
	}

	template <typename T>
	mat3<T>::mat3(const mat4<T>& matrix)
	{
		Cols[0] = vec3<T>(matrix.Cols[0].X, matrix.Cols[0].Y, matrix.Cols[0].Z);
		Cols[1] = vec3<T>(matrix.Cols[1].X, matrix.Cols[1].Y, matrix.Cols[1].Z);
		Cols[2] = vec3<T>(matrix.Cols[2].X, matrix.Cols[2].Y, matrix.Cols[2].Z);
	}

	template <typename T>
	mat3<T>& mat3<T>::Multiply(const mat3<T>& other)
	{
		float data[9];
		for (int col = 0; col < 3; col++)
		{
			for (int row = 0; row < 3; row++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 3; i++)
					sum += Elements[i * 3 + row] * other.Elements[i + col * 3];
				data[row + col * 3] = sum;
			}
		}
		memcpy(Elements, data, 9 * sizeof(T));
		return *this;
	}

	template <typename T>
	mat3<T>& mat3<T>::operator *= (const mat3<T>& other)
	{
		return Multiply(other);
	}

	template <typename T>
	mat3<T> mat3<T>::Identity()
	{
		return mat3<T>(1.0f);
	}

	template <typename T>
	mat3<T> mat3<T>::Transpose(const mat3<T>& matrix)
	{
		mat3<T> result;

		result.Elements[0] = matrix.Elements[0];
		result.Elements[1] = matrix.Elements[3];
		result.Elements[2] = matrix.Elements[6];
		result.Elements[3] = matrix.Elements[1];
		result.Elements[4] = matrix.Elements[4];
		result.Elements[5] = matrix.Elements[7];
		result.Elements[6] = matrix.Elements[2];
		result.Elements[7] = matrix.Elements[5];
		result.Elements[8] = matrix.Elements[8];

		return result;
	}

	template <typename T>
	mat3<T> mat3<T>::Inverse(const mat3<T>& matrix)
	{
		mat3<T> result;

		// Calculate matrix of cofactors
		result.Elements[0] = matrix.Elements[4] * matrix.Elements[8] - matrix.Elements[5] * matrix.Elements[7];
		result.Elements[1] = T(-1.0f) * (matrix.Elements[3] * matrix.Elements[8] - matrix.Elements[5] * matrix.Elements[6]);
		result.Elements[2] = matrix.Elements[3] * matrix.Elements[7] - matrix.Elements[4] * matrix.Elements[6];
		result.Elements[3] = T(-1.0f) * (matrix.Elements[1] * matrix.Elements[8] - matrix.Elements[2] * matrix.Elements[7]);
		result.Elements[4] = matrix.Elements[0] * matrix.Elements[8] - matrix.Elements[2] * matrix.Elements[6];
		result.Elements[5] = T(-1.0f) * (matrix.Elements[0] * matrix.Elements[7] - matrix.Elements[1] * matrix.Elements[6]);
		result.Elements[6] = matrix.Elements[1] * matrix.Elements[5] - matrix.Elements[2] * matrix.Elements[4];
		result.Elements[7] = T(-1.0f) * (matrix.Elements[0] * matrix.Elements[5] - matrix.Elements[2] * matrix.Elements[3]);
		result.Elements[8] = matrix.Elements[0] * matrix.Elements[4] - matrix.Elements[1] * matrix.Elements[3];

		// Calculate Adjugate (Adjoint)
		result = mat3<T>::Transpose(result);

		// Calculate Determinat
		float a = matrix.Elements[0] * (matrix.Elements[4] * matrix.Elements[8] - matrix.Elements[5] * matrix.Elements[7]);
		float b = matrix.Elements[1] * (matrix.Elements[3] * matrix.Elements[8] - matrix.Elements[5] * matrix.Elements[6]);
		float c = matrix.Elements[2] * (matrix.Elements[3] * matrix.Elements[7] - matrix.Elements[4] * matrix.Elements[6]);
		float det = a - b + c;

		// Multiply by 1/Determinat
		result *= (1 / det);

		return result;
	}

}