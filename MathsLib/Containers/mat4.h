#pragma once

#include "vec3.h"
#include "vec4.h"

#include <cstring>

namespace Maths::Containers {

	template <typename T>
	struct mat4
	{
		union
		{
			T Elements[16];
			vec4<T> Cols[4];
		};

		mat4();
		mat4(T diagonal);
		mat4(const vec4<T>& col0, const vec4<T>& col1, const vec4<T>& col2, const vec4<T>& col3);

		mat4<T>& Multiply(const mat4<T>& other);

		mat4<T>& operator *= (const mat4<T>& other);

		static mat4<T> Identity();
		static mat4<T> Translation(const vec3<T>& translation);
		static mat4<T> Scale(const vec3<T>& scale);
		static mat4<T> Rotation(float angle, const vec3<T>& axis);
		static mat4<T> LookAt(const vec3<T>& position, const vec3<T>& centre, const vec3<T>& up = vec3(0.0f, 1.0f, 0.0f));
		static mat4<T> Perspective(float fov, float aspectRatio, float n, float f);

		friend mat4<T> operator * (mat4<T> lhs, const mat4<T>& rhs)
		{
			return lhs.Multiply(rhs);
		}

		friend std::ostream& operator << (std::ostream& os, const mat4<T>& matrix)
		{
			for (int i = 0; i < 16; i++)
			{
				os << matrix.Elements[i] << "\t";
				if (i == 3 || i == 7 || i == 11 || i == 15)
					os << "\n";
			}
			return os;
		}
	};

	template <typename T>
	mat4<T>::mat4()
	{
		memset(Elements, 0, 16 * sizeof(T));
	}

	template <typename T>
	mat4<T>::mat4(T diagonal)
	{
		memset(Elements, 0, 16 * sizeof(T));
		Elements[0] = diagonal;
		Elements[5] = diagonal;
		Elements[10] = diagonal;
		Elements[15] = diagonal;
	}

	template <typename T>
	mat4<T>::mat4(const vec4<T>& col0, const vec4<T>& col1, const vec4<T>& col2, const vec4<T>& col3)
	{
		Cols[0] = col0;
		Cols[1] = col1;
		Cols[2] = col2;
		Cols[3] = col3;
	}

	template <typename T>
	mat4<T>& mat4<T>::Multiply(const mat4<T>& other)
	{
		float data[16];
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; i++)
					sum += Elements[i * 4 + row] * other.Elements[i + col * 4];
				data[row + col * 4] = sum;
			}
		}
		memcpy(Elements, data, 16 * sizeof(T));
		return *this;
	}

	template <typename T>
	mat4<T>& mat4<T>::operator *= (const mat4<T>& other)
	{
		return Multiply(other);
	}

	template <typename T>
	mat4<T> mat4<T>::Identity()
	{
		return mat4(T(1.0f));
	}

	template <typename T>
	mat4<T> mat4<T>::Translation(const vec3<T>& translation)
	{
		mat4<T> result(1.0f);

		result.Elements[12] = translation.X;
		result.Elements[13] = translation.Y;
		result.Elements[14] = translation.Z;

		return result;
	}

	template <typename T>
	mat4<T> mat4<T>::Scale(const vec3<T>& scale)
	{
		mat4<T> result(1.0f);

		result.Elements[0] = scale.X;
		result.Elements[5] = scale.Y;
		result.Elements[10] = scale.Z;

		return result;
	}

	template <typename T>
	mat4<T> mat4<T>::Rotation(float angle, const vec3<T>& axis)
	{
		float c = cos(angle * 0.0174533f);
		float s = sin(angle * 0.0174533f);
		float omc = 1 - c;
		float x = axis.Normalise().X;
		float y = axis.Normalise().Y;
		float z = axis.Normalise().Z;

		mat4 result{
			vec4<T>(c + x * x*omc, y*x*omc + z * s, z*x*omc - y * s, 0.0f),
			vec4<T>(x*y*omc - z * s, c + y * y*omc, z*y*omc + x * s, 0.0f),
			vec4<T>(x*z*omc + y * s, y*z*omc - x * s, c + z * z*omc, 0.0f),
			vec4<T>(0.0f, 0.0f, 0.0f, 1.0f)
		};

		return result;
	}

	template <typename T>
	mat4<T> mat4<T>::LookAt(const vec3<T>& position, const vec3<T>& centre, const vec3<T>& up)
	{
		vec3<T> f = (centre - position).Normalise();
		vec3<T> r = vec3<T>::Cross(f, up).Normalise();
		vec3<T> u = vec3<T>::Cross(r, f).Normalise();

		mat4<T> ViewMatrix{
			vec4<T>(r.X, u.X, -f.X, 0.0f),
			vec4<T>(r.Y, u.Y, -f.Y, 0.0f),
			vec4<T>(r.Z, u.Z, -f.Z, 0.0f),
			vec4<T>(-vec3<T>::Dot(r, position), -vec3<T>::Dot(u, position), vec3<T>::Dot(f, position), 1.0f)
		};

		return ViewMatrix;
	}

	template <typename T>
	mat4<T> mat4<T>::Perspective(float fov, float aspectRatio, float n, float f)
	{
		float t = n * (float)tan(0.5 * fov * 0.0174533f);
		float r = t * aspectRatio;

		mat4<T> perspectiveMatrix = {
			vec4<T>(n / r, 0.0f, 0.0f, 0.0f),
			vec4<T>(0.0f, n / t, 0.0f, 0.0f),
			vec4<T>(0.0f, 0.0f, -(f + n) / (f - n), -1.0f),
			vec4<T>(0.0f, 0.0f, (-2.0f*f*n) / (f - n), 0.0f)
		};

		return perspectiveMatrix;
	}

}