#include <climits>
//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Math/Vector2.h>

namespace math
{
	const Vector2 Vector2::Zero(0.0f, 0.0f);
	__unused const Vector2 Vector2::UnitX(1.0f, 0.0f);
	__unused const Vector2 Vector2::UnitY(0.0f, 1.0f);
	__unused const Vector2 Vector2::NegUnitX(-1.0f, 0.0f);
	__unused const Vector2 Vector2::NegUnitY(0.0f, -1.0f);
}