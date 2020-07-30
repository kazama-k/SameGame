//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Engine/Core/Actor.h>
#include <Engine/Component/MoveComponent.h>

namespace engine
{
	MoveComponent::MoveComponent(Actor* owner, int updateOrder) : Component(owner, updateOrder),
																  mRightSpeed(0.0f), mDownSpeed(0.0f)
	{
	}

	void MoveComponent::Update(float deltaTime)
	{
		// 前進速度が0よりも大きい場合
		if (!math::NearZero(mRightSpeed) || !math::NearZero(mDownSpeed))
		{
			//! アクターの中心位置
			math::Vector2 pos = mOwner->GetPosition();
			// 中心位置を速度とデルタタイムで更新して新たに設定
			pos.x += mRightSpeed * deltaTime;
			pos.y += mDownSpeed * deltaTime;

			if (pos.x < 25.0f)
			{ pos.x = 25.0f; }
			else if (pos.x > 999.0f)
			{ pos.x = 999.0f; }
			if (pos.y < 25.0f)
			{ pos.y = 25.0f; }
			else if (pos.y > 743.0f)
			{ pos.y = 743.0f; }

			mOwner->SetPosition(pos);
		}
	}
}