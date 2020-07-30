//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Engine/Core/Actor.h>
#include <Engine/Component/BGSpriteComponent.h>

namespace engine
{
	BGSpriteComponent::BGSpriteComponent(Actor* owner, int drawOrder) : SpriteComponent(owner, drawOrder),
																		mScrollSpeed(0.0f)
	{
	}

	void BGSpriteComponent::Update(float deltaTime)
	{
		// スプライトコンポーネントを先に更新
		SpriteComponent::Update(deltaTime);
		// それぞれの背景テクスチャ構造体に対して
		for (auto& bg: mBGTextures)
		{
			// x のオフセットを更新
			bg.mOffset.x += mScrollSpeed * deltaTime;

			// もし画面から完全にでたら，オフセットを最後の背景テクスチャの右にリセットする
			if (bg.mOffset.x < -mScreenSize.x)
			{
				bg.mOffset.x = float(mBGTextures.size() - 1) * mScreenSize.x - 1;
			}
		}
	}

	void BGSpriteComponent::Draw(SDL_Renderer* renderer)
	{
		// それぞれの背景テクスチャ構造体に対して
		for (const auto& bg: mBGTextures)
		{
			SDL_Rect r;

			// 背景のサイズはスクリーンサイズと同じ
			r.w = static_cast<int>(mScreenSize.x);
			r.h = static_cast<int>(mScreenSize.y);

			// 矩形の中心を所有アクターの位置に合わせる
			r.x = static_cast<int>(mOwner->GetPosition().x - float(r.w) / 2 + bg.mOffset.x);
			r.y = static_cast<int>(mOwner->GetPosition().y - float(r.h) / 2 + bg.mOffset.y);

			// 背景を描写
			SDL_RenderCopy(
				renderer,
				bg.mTexture,
				nullptr,
				&r
			);
		}
	}

	void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture*>& textures)
	{
		int count = 0;

		// 設定するそれぞれの背景テクスチャに対して
		for (auto tex: textures)
		{
			BGTexture tmp;

			tmp.mTexture = tex;
			// それぞれのテクスチャは画面幅分のオフセットを持つ
			tmp.mOffset.x = float(count) * mScreenSize.x;
			tmp.mOffset.y = 0;

			mBGTextures.emplace_back(tmp);

			++count;
		}
	}
}