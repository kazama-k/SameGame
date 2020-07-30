//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <SameAction/Actor/LaserActor.h>

#include <Engine/Core/GameCore.h>

#include <Engine/Component/SpriteComponent.h>
#include <Engine/Component/MoveComponent.h>

namespace samegame
{
	LaserActor::LaserActor(engine::GameCore* game) : Actor(game), mDeathTimer(1.0f)
	{
		// SpriteComponentの作成
		auto sc = new engine::SpriteComponent(this);
		sc->SetTexture(game->GetTexture("../../asset/SameAction/Laser.png"));

		// MoveComponentにより前進速度を設定
		auto mc = new engine::MoveComponent(this);
		mc->SetRightSpeed(700.0f);
		mc->SetDownSpeed(700.0f);
	}

	void LaserActor::UpdateActor(float deltaTime)
	{
		// レーザーが自動的に消滅する
		mDeathTimer -= deltaTime;
		if (mDeathTimer <= 0.0f)
		{
			SetState(EDead);
		}
	}
}