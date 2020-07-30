//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_GAME_INPUTCOMPONENT_H
#define SAMEGAME_INCLUDE_GAME_INPUTCOMPONENT_H

#include <cstdint>

#include <Engine/Component/MoveComponent.h>

namespace engine
{
	/**
	 * キー入力で所有アクターの運動と回転を制御するためのコンポーネント
	 */
	class InputComponent : public MoveComponent
	{
	public:
		explicit InputComponent(Actor* owner);

		void ProcessInput(const uint8_t* keyState) override;

		__unused float GetMaxSpeed() const
		{
			return mMaxSpeed;
		}
		__unused int GetRightKey() const
		{
			return mRightKey;
		}
		__unused int GetLeftKey() const
		{
			return mLeftKey;
		}
		__unused int GetUpKey() const
		{
			return mUpKey;
		}
		__unused int GetDownKey() const
		{
			return mDownKey;
		}
		void SetMaxSpeed(float speed)
		{
			mMaxSpeed = speed;
		}
		void SetLeftKey(int key)
		{
			mLeftKey = key;
		}
		void SetRightKey(int key)
		{
			mRightKey = key;
		}
		void SetUpKey(int key)
		{
			mUpKey = key;
		}
		void SetDownKey(int key)
		{
			mDownKey = key;
		}

	private:
		// 速度の最大値
		float mMaxSpeed;
		// 左右運動のキー
		int mRightKey;
		int mLeftKey;
		// 上下運動のキー
		int mUpKey;
		int mDownKey;
	};
}

#endif //SAMEGAME_INCLUDE_GAME_INPUTCOMPONENT_H
