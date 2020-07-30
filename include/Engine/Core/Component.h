//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_COMPONENT_H
#define SAMEGAME_INCLUDE_ENGINE_COMPONENT_H

#include <SDL.h>

namespace engine
{
	class Actor;

	/**
	 * アクターが持つコンポーネント
	 */
	class Component
	{
	public:
		/**
		 * コンストラクタ
		 * @param owner コンポーネントの所有者であるアクター
		 * @param updateOrder 更新順序．この値が小さいコンポーネントほど早く更新される
		 */
		explicit Component(Actor* owner, int updateOrder = 100);
		/**
		 * デストラクタ (virtual)
		 */
		virtual ~Component();

		/**
		 * このコンポーネントをデルタタイムで更新する (virtual)
		 * @param deltaTime デルタタイム
		 * @note オーバーライド可能
		 */
		virtual void Update(float deltaTime)
		{
		}
		/**
		 * このコンポーネントに対する入力を処理する
		 * @param keyState キー入力の状態
		 * @note オーバーライド可能
		 */
		virtual void ProcessInput(const uint8_t* keyState)
		{
		}

		int GetUpdateOrder() const
		{
			return mUpdateOrder;
		}

	protected:
		//! このコンポーネントを所有しているアクター
		Actor* mOwner;
		//! このコンポーネントの更新順序
		int mUpdateOrder;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_COMPONENT_H
