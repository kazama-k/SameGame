//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Engine/Core/Actor.h>
#include <Engine/Core/Component.h>

namespace engine
{
	Component::Component(Actor* owner, int updateOrder) : mOwner(owner), mUpdateOrder(updateOrder)
	{
		// このコンポーネントを所有するアクターに自分自身を追加する
		mOwner->AddComponent(this);
	}

	Component::~Component()
	{
		// このコンポーネントを所有するアクターから自分自身を削除する
		mOwner->RemoveComponent(this);
	}
}