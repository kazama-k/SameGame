//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Engine/Component/AnimSpriteComponent.h>

namespace engine
{
	AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder) : SpriteComponent(owner, drawOrder),
																			mCurrentFrame(0.0f), mAnimFPS(24.0f)
	{
	}

	void AnimSpriteComponent::Update(float deltaTime)
	{
		// スプライトコンポーネントの更新を先に行う
		SpriteComponent::Update(deltaTime);

		// アニメーションするテクスチャの数が1以上ある場合アニメーション処理を行う
		if (mAnimTextures.size() > 0)
		{
			// 現在のフレームをFPSとデルタタイムをもとに更新する
			mCurrentFrame += mAnimFPS * deltaTime;

			// 必要に応じて現在のフレームを巻き戻す
			while (mCurrentFrame >= mAnimTextures.size())
			{
				mCurrentFrame -= mAnimTextures.size();
			}

			// 現在のテクスチャを設定する
			SetTexture(mAnimTextures[static_cast<int>(mCurrentFrame)]);
		}
	}

	void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
	{
		mAnimTextures = textures;

		// アニメーションするテクスチャの数が1以上ある場合
		if (mAnimTextures.size() > 0)
		{
			// 最初のフレームを定義
			mCurrentFrame = 0.0f;
			SetTexture(mAnimTextures[0]);
		}
	}
}