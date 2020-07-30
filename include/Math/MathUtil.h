//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_MATH_MATHUTIL_H
#define SAMEGAME_INCLUDE_MATH_MATHUTIL_H

#include <cmath>
#include <memory.h>
#include <limits>

namespace math
{
	const float Pi = 3.1415926535f;
	__unused const float Infinity = std::numeric_limits<float>::infinity();

	__unused inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		return fabs(val) <= epsilon;
	}

	template <typename T>
	T Max(const T& a, const T& b)
	{
		return (a < b ? b : a);
	}

	template <typename T>
	T Min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}

	template <typename T>
	__unused T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min(upper, Max(lower, value));
	}

	__unused inline float Abs(float value)
	{
		return fabs(value);
	}

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	__unused inline float Acos(float value)
	{
		return acosf(value);
	}

	__unused inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	__unused inline float Cot(float angle)
	{
		return 1.0f / Tan(angle);
	}

	__unused inline float Lerp(float a, float b, float f)
	{
		return a + f * (b - a);
	}

	inline float Sqrt(float value)
	{
		return sqrtf(value);
	}

	__unused inline float Fmod(float numer, float denom)
	{
		return fmod(numer, denom);
	}
}

#endif //SAMEGAME_INCLUDE_MATH_MATHUTIL_H
