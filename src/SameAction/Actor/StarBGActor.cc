//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <Engine/Core/GameCore.h>
#include <Engine/Component/BGSpriteComponent.h>

#include <SameAction/Actor/StarBGActor.h>

namespace samegame
{
	StarBGActor::StarBGActor(engine::GameCore* game) : Actor(game)
	{
		// 位置を設定
		SetPosition(math::Vector2(512.0f, 384.0f));

		// BGSpriteComponentを作成して背景をスクロール
		// 最も近い背景なので order は小さい値で50
		auto bg = new engine::BGSpriteComponent(this, 50);
		bg->SetScreenSize(math::Vector2(1024.0f, 768.0f));
		std::vector<SDL_Texture*> bgTexs = {
			game->GetTexture("../../asset/SameAction/Stars.png"),
			game->GetTexture("../../asset/SameAction/Stars.png")
		};
		bg->SetBGTextures(bgTexs);
		bg->SetScrollSpeed(-200.0f);  // 近い背景を高速で動かすようにすることで視差効果
	}
}