#include <climits>
//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_MATH_RANDOM_H
#define SAMEGAME_INCLUDE_MATH_RANDOM_H

#include <random>

#include <Math/Vector2.h>

namespace math
{
	class Random
	{
	public:
		static void Init();

		// Seed the generator with the specified int
		// NOTE: You should generally not need to manually use this
		static void Seed(unsigned int seed);

		// Get a float between 0.0f and 1.0f
		static float GetFloat();

		// Get a float from the specified range
		static float GetFloatRange(float min, float max);

		// Get an int from the specified range
		__unused static int GetIntRange(int min, int max);

		// Get a random vector given the min/max bounds
		__unused static Vector2 GetVector(const Vector2& min, const Vector2& max);
//		static Vector3 GetVector(const Vector3& min, const Vector3& max);

	private:
		static std::mt19937 sGenerator;
	};
}

#endif //SAMEGAME_INCLUDE_MATH_RANDOM_H
