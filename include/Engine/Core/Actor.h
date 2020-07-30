//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_ACTOR_H
#define SAMEGAME_INCLUDE_ENGINE_ACTOR_H

#include <vector>

#include <Math/Vector2.h>

namespace engine
{
	class Component;
	class GameCore;

	/**
	 * ゲームオブジェクトのモデルとしての Actor クラス
	 */
	class Actor
	{
	public:
		/**
		 * アクターの状態管理用の Enum
		 */
		enum State
		{
			EActive, /**< アクターはアクティブである */
			EPaused __unused, /**< アクターは停止状態である */
			EDead /**< アクターは死んでしまった */
		};

		/* --------------------------------------------- */

		/**
		 * コンストラクタ
		 * @param [in] game ゲームクラスへのポインタ．これを用いて別のアクターを追加作成できる
		 */
		explicit Actor(GameCore* game);
		/**
		 * デストラクタ (仮想メンバ）
		 */
		virtual ~Actor();

		/* --------------------------------------------- */

		/**
		 * ゲームから呼び出される更新関数
		 * @param [in] deltaTime デルタタイム
		 * @note オーバーライド不可
		 */
		void Update(float deltaTime);
		/**
		 * アクターが持つ全コンポーネントを更新する
		 * @param [in] deltaTime デルタタイム
		 * @note オーバーライド不可
		 */
		void UpdateComponents(float deltaTime);
		/**
		 * アクター独自の更新処理を実装する (virtual)
		 * @param [in] deltaTime デルタタイム
		 * @note オーバーライド可能
		 */
		virtual void UpdateActor(float deltaTime);

		/* --------------------------------------------- */

		// Gameから呼び出される入力処理用の関数（オーバーライド不可）
		void ProcessInput(const uint8_t* keyState);
		// アクター独自の入力処理用関数（オーバーライド可能）
		virtual void ActorInput(const uint8_t* keyState);

		/* --------------------------------------------- */

		/**
		 * このアクターにコンポーネントを追加する
		 * @param component 追加するコンポーネントのポインタ
		 */
		void AddComponent(Component* component);
		/**
		 * このアクターからコンポーネントを削除する
		 * @param component 削除したいコンポーネントへのポインタ
		 */
		void RemoveComponent(Component* component);

		/* --------------------------------------------- */

		const math::Vector2& GetPosition() const
		{
			return mPosition;
		}
		void SetPosition(const math::Vector2& pos)
		{
			mPosition = pos;
		}
		float GetScale() const
		{
			return mScale;
		}
		void SetScale(float scale)
		{
			mScale = scale;
		}
		float GetRotation() const
		{
			return mRotation;
		}
		void SetRotation(float rotation)
		{
			mRotation = rotation;
		}

		__unused math::Vector2 GetForward() const
		{
			return math::Vector2(math::Cos(mRotation), -math::Sin(mRotation));
		}

		State GetState() const
		{
			return mState;
		}
		void SetState(State state)
		{
			mState = state;
		}

		class GameCore* GetGame()
		{
			return mGame;
		}

	private:
		//! アクターの現在の状態
		State mState;

		//! アクターの現在の中心位置
		math::Vector2 mPosition;
		//! アクターのスケール (1.0f が 100%)
		float mScale;
		//! アクターの回転角度 [rad]
		float mRotation;

		//! アクターが保持する全てのコンポーネント
		std::vector<Component*> mComponents;

		//! アクターが保持するゲームクラスのポインタ
		GameCore* mGame;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_ACTOR_H
