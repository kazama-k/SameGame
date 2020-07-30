//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#include <Engine/Core/Actor.h>
#include <Engine/Core/GameCore.h>
#include <Engine/Component/SpriteComponent.h>

#include <Math/MathUtil.h>

namespace engine
{
	SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
		: Component(owner), mTexture(nullptr), mDrawOrder(drawOrder), mTextureHeight(0), mTextureWidth(0)
	{
		// これを保有するアクター経由でゲームクラスにこのスプライトコンポーネントを追加する
		mOwner->GetGame()->AddSprite(this);
	}

	SpriteComponent::~SpriteComponent()
	{
		// これを保有するアクター経由でゲームクラスからこのスプライトコンポーネントを削除する
		mOwner->GetGame()->RemoveSprite(this);
	}

	void SpriteComponent::Draw(SDL_Renderer* renderer)
	{
		// スプライトコンポーネント内にテクスチャが存在する場合のみ描写
		if (mTexture)
		{
			//! 描写するスプライトとしての矩形
			SDL_Rect r;

			// 幅と高さを所有アクターのスケールで拡大縮小する
			r.w = static_cast<int>(float(mTextureWidth) * mOwner->GetScale());
			r.h = static_cast<int>(float(mTextureHeight) * mOwner->GetScale());

			// 矩形の中心を所有アクターの位置に合わせる
			r.x = static_cast<int>(mOwner->GetPosition().x - float(r.w) / 2);
			r.y = static_cast<int>(mOwner->GetPosition().y - float(r.h) / 2);

			// 受け取ったレンダラーに対して矩形を描写する
			SDL_RenderCopyEx(
				renderer,                                                    // レンダラー
				mTexture,                                                    // 描写したいテクスチャ
				nullptr,                                            // 描写したいテクスチャの範囲 (全部なら nullptr)
				&r,                                                        // 描写する矩形のポインタ
				-math::ToDegrees(mOwner->GetRotation()),    // ラジアンから度に変換された回転角度
				nullptr,                                            // 回転中心 (中央なら nullptr)
				SDL_FLIP_NONE                                            // テクスチャを反転しない
			);
		}
	}

	void SpriteComponent::SetTexture(SDL_Texture* texture)
	{
		// テクスチャをコンポーネントに設定
		mTexture = texture;
		// テクスチャの幅と高さを求めて設定
		SDL_QueryTexture(texture, nullptr, nullptr, &mTextureWidth, &mTextureHeight);
	}
}