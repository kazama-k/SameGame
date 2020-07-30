//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <algorithm>

#include <Engine/Core/Actor.h>
#include <Engine/Core/Component.h>
#include <Engine/Core/GameCore.h>

namespace engine
{
	Actor::Actor(GameCore* game)
		: mState(EActive), mPosition(math::Vector2::Zero), mScale(1.0f), mRotation(0.0f), mGame(game)
	{
		// ゲームクラスにこのアクターを追加する
		mGame->AddActor(this);
	}

	Actor::~Actor()
	{
		// ゲームクラスからこのアクターを削除する
		mGame->RemoveActor(this);

		// このアクターが保有する全コンポーネントの削除が必要
		// (~Component が RemoveComponent メソッドを呼び出すため)
		while (!mComponents.empty())
		{
			delete mComponents.back();
		}
	}

	void Actor::Update(float deltaTime)
	{
		// 状態が Active の場合に限りアクターを更新
		if (mState == EActive)
		{
			// コンポーネントを更新
			UpdateComponents(deltaTime);
			// アクター独自の更新
			UpdateActor(deltaTime);
		}
	}

	void Actor::UpdateComponents(float deltaTime)
	{
		// 保有する全てのコンポーネントに対して
		for (auto comp: mComponents)
		{
			// それぞれのコンポーネント独自の更新
			comp->Update(deltaTime);
		}
	}

	void Actor::UpdateActor(float deltaTime)
	{
		// それぞれの子クラスでアクター独自の更新処理を実装
	}

	void Actor::AddComponent(Component* component)
	{
		// ソート済みの配列で挿入点を見つける
		// (それは自分よりも更新順序の高い最初の要素の位置)

		//! 追加するコンポーネントの更新順序
		int myOrder = component->GetUpdateOrder();

		//! 追加する全てのコンポーネントのイテレータ
		auto iter = mComponents.begin();
		for (; iter != mComponents.end(); ++iter)
		{
			// 自分よりも更新順序が高くなった要素の時点で break
			if (myOrder < (*iter)->GetUpdateOrder())
			{
				break;
			}
		}

		// 現在のイテレータの一つ前の位置にコンポーネントを追加
		mComponents.insert(iter, component);
	}

	void Actor::RemoveComponent(Component* component)
	{
		auto iter = std::find(mComponents.begin(), mComponents.end(), component);
		if (iter != mComponents.end()) // 削除対象のコンポーネントが mComponents に含まれている
		{
			mComponents.erase(iter);
		}
	}

	void Actor::ProcessInput(const uint8_t* keyState)
	{
		// 状態がアクティブの場合
		if (mState == EActive)
		{
			// 全てのコンポーネントに対する入力を各コンポーネントで処理する
			for (const auto comp: mComponents)
			{
				comp->ProcessInput(keyState);
			}
			// アクター独自の入力処理
			ActorInput(keyState);
		}
	}

	void Actor::ActorInput(const uint8_t* keyState)
	{
	}
}