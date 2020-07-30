//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_GAME_MOVECOMPONENT_H
#define SAMEGAME_INCLUDE_GAME_MOVECOMPONENT_H

#include <Engine/Core/Component.h>

namespace engine
{
	/**
	 * 運動のコンポーネントクラス
	 */
	class MoveComponent : public Component
	{
	public:
		/**
		 * コンストラクタ
		 * @param owner 所有アクター
		 * @param updateOrder 運動を行うので他のほとんどのコンポーネントよりも先に更新される
		 */
		MoveComponent(Actor* owner, int updateOrder = 10);

		void Update(float deltaTime) override;

	public:
		__unused float GetRightSpeed() const
		{
			return mRightSpeed;
		}
		__unused float GetDownSpeed() const
		{
			return mDownSpeed;
		}
		void SetRightSpeed(float speed)
		{
			mRightSpeed = speed;
		}
		void SetDownSpeed(float speed)
		{
			mDownSpeed = speed;
		}

	private:
		// 左右の速度 [単位長/s]
		float mRightSpeed;
		// 上下の速度 [単位長/s]
		float mDownSpeed;

		//! 質量
		__unused float mMass;
		//! 力の合計
		__unused float mSumNeutons;
		//! 速度
		__unused float mVelocity;
	};
}

#endif //SAMEGAME_INCLUDE_GAME_MOVECOMPONENT_H
