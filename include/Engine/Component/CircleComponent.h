//
// Created by Kentaro KAZAMA on 2020/07/28.
//
// TODO: 「衝突検知のコンポーネント」に変更

#ifndef SAMEGAME_INCLUDE_GAME_CIRCLECOMPONENT_H
#define SAMEGAME_INCLUDE_GAME_CIRCLECOMPONENT_H

#include <Engine/Core/Component.h>
#include <Math/Vector2.h>

namespace engine
{
	/**
	 * 円をなすアクターのコンポーネント
	 */
	class CircleComponent : public Component
	{
	public:
		__unused explicit CircleComponent(Actor* owner);

		float GetRadius() const;
		__unused void SetRadius(float radius) { mRadius = radius; }

		// 中心位置ベクトルの取得
		const math::Vector2& GetCenter() const;

	private:
		//! 円の半径
		float mRadius;
	};

	// 円が交差しているかどうか検証する
	__unused bool Intersect(const CircleComponent& a, const CircleComponent& b);
}

#endif //SAMEGAME_INCLUDE_GAME_CIRCLECOMPONENT_H
