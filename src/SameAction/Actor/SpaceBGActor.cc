//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <Engine/Core/GameCore.h>
#include <Engine/Component/BGSpriteComponent.h>

#include <SameAction/Actor/SpaceBGActor.h>

namespace samegame
{
	SpaceBGActor::SpaceBGActor(engine::GameCore* game) : Actor(game)
	{
		// 位置を設定
		SetPosition(math::Vector2(512.0f, 384.0f));

		// BGSpriteComponentを作成して背景をスクロール
		auto bg = new engine::BGSpriteComponent(this);
		bg->SetScreenSize(math::Vector2(1024.0f, 768.0f));
		std::vector<SDL_Texture*> bgTexs = {
			game->GetTexture("../../asset/SameAction/Farback01.png"),
			game->GetTexture("../../asset/SameAction/Farback02.png")
		};
		bg->SetBGTextures(bgTexs);
		bg->SetScrollSpeed(-100.0f);
	}
}