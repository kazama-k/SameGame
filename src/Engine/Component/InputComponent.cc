//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <Engine/Core/Actor.h>
#include <Engine/Component/InputComponent.h>

namespace engine
{
	InputComponent::InputComponent(Actor* owner)
		: MoveComponent(owner), mLeftKey(0), mRightKey(0), mUpKey(0), mDownKey(0),
		  mMaxSpeed(0.0f)
	{
	}

	void InputComponent::ProcessInput(const uint8_t* keyState)
	{
		// MoveComponentのために左右運動を計算
		float rightSpeed = 0.0f;
		if (keyState[mRightKey])
		{
			rightSpeed += mMaxSpeed;
		}
		if (keyState[mLeftKey])
		{
			rightSpeed -= mMaxSpeed;
		}
		SetRightSpeed(rightSpeed);

		// MoveComponentのために上下速度を計算
		float downSpeed = 0.0f;
		if (keyState[mDownKey])
		{
			downSpeed += mMaxSpeed;
		}
		if (keyState[mUpKey])
		{
			downSpeed -= mMaxSpeed;
		}
		SetDownSpeed(downSpeed);
	}
}