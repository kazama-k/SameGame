//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <SameAction/Actor/ShipActor.h>
#include <SameAction/Actor/LaserActor.h>

#include <Engine/Core/Actor.h>
#include <Engine/Core/GameCore.h>

#include <Engine/Component/AnimSpriteComponent.h>
#include <Engine/Component/InputComponent.h>

namespace samegame
{
	ShipActor::ShipActor(engine::GameCore* game) : Actor(game), mLaserCoolDown(0.0f)
	{
		// 宇宙船の位置とスケールを設定
		SetPosition(math::Vector2(100.0f, 384.0f));
		SetScale(1.5f);

		// AnimSpriteComponentの作成（アニメーション）
		auto asc = new engine::AnimSpriteComponent(this, 150);
		std::vector<SDL_Texture*> anims = {
			game->GetTexture("../../asset/SameAction/Ship01.png"),
			game->GetTexture("../../asset/SameAction/Ship02.png"),
			game->GetTexture("../../asset/SameAction/Ship03.png"),
			game->GetTexture("../../asset/SameAction/Ship04.png")
		};
		asc->SetAnimTextures(anims);

		// InputComponentを作成してキーと速度を設定
		auto ic = new engine::InputComponent(this);
		ic->SetUpKey(SDL_SCANCODE_W);
		ic->SetDownKey(SDL_SCANCODE_S);
		ic->SetLeftKey(SDL_SCANCODE_A);
		ic->SetRightKey(SDL_SCANCODE_D);
		ic->SetMaxSpeed(200.0f);
	}

	void ShipActor::UpdateActor(float deltaTime)
	{
		// デルタタイムでレーザーを冷却
		mLaserCoolDown -= deltaTime;
	}

	void ShipActor::ActorInput(const uint8_t* keyState)
	{
		// スペースキーを押していてかつレーザーが完全に冷却されている場合
		if (keyState[SDL_SCANCODE_SPACE] && mLaserCoolDown <= 0.0f)
		{
			// レーザーを作成して位置と回転角を宇宙船と合わせる
			auto laser = new LaserActor(GetGame());
			laser->SetPosition(GetPosition());
			laser->SetRotation(GetRotation());

			// レーザーの冷却時間を0.5秒間リセット
			mLaserCoolDown = 0.5f;
		}
	}
}