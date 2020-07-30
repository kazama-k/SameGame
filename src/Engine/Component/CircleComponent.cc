#include <climits>
//
// Created by Kentaro KAZAMA on 2020/07/28.
//
// TODO: 「衝突検知のコンポーネント」に変更

#include <Engine/Core/Actor.h>
#include <Engine/Component/CircleComponent.h>

namespace engine
{
	__unused CircleComponent::CircleComponent(Actor* owner) : Component(owner), mRadius(0.0f)
	{
	}

	const math::Vector2& CircleComponent::GetCenter() const
	{
		return mOwner->GetPosition();
	}

	float CircleComponent::GetRadius() const
	{
		return mOwner->GetScale() * mRadius;
	}

	__unused bool Intersect(const CircleComponent& a, const CircleComponent& b)
	{
		//! 二乗距離の計算
		math::Vector2 diff = a.GetCenter() - b.GetCenter();
		//! 平方根をとる
		float distSq = diff.LengthSq();

		//! 二つの円のそれぞれの半径の二乗
		float radiiSq = a.GetRadius() + b.GetRadius();
		radiiSq *= radiiSq;

		return distSq <= radiiSq;
	}
}