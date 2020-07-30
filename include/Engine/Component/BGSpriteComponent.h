//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_BGSPRITECOMPONENT_H
#define SAMEGAME_INCLUDE_ENGINE_BGSPRITECOMPONENT_H

#include <vector>

#include <Engine/Component/SpriteComponent.h>

#include <Math/Vector2.h>

namespace engine
{
	/**
	 * 背景をスクロールさせるスプライトコンポーネント
	 */
	class BGSpriteComponent : public SpriteComponent
	{
	public:
		/**
		 * コンストラクタ
		 * @param owner コンポーネントの所有者であるアクター
		 * @param drawOrder 背景なので描写順序を小さくする
		 */
		explicit BGSpriteComponent(Actor* owner, int drawOrder = 10);

		void Update(float deltaTime) override;
		void Draw(SDL_Renderer* renderer) override;

		/**
		 * 背景用のテクスチャを設定する
		 * @param textures 背景に用いるテクスチャ一覧
		 */
		void SetBGTextures(const std::vector<SDL_Texture*>& textures);

		__unused float GetScrollSpeed() const
		{
			return mScrollSpeed;
		}
		void SetScrollSpeed(float speed)
		{
			mScrollSpeed = speed;
		}
		void SetScreenSize(const math::Vector2& size)
		{
			mScreenSize = size;
		}

	private:
		/**
		 * 個々の背景画像とオフセットをカプセル化する構造体
		 */
		struct BGTexture
		{
			//! 背景画像のテクスチャ
			SDL_Texture* mTexture{};
			//! 背景画像のオフセット
			math::Vector2 mOffset;
		};

		//! 背景画像とオフセットをカプセル化した構造体の配列
		std::vector<BGTexture> mBGTextures;

		//! 画面のスクリーンサイズ
		math::Vector2 mScreenSize;
		//! 背景のスクロール速度
		float mScrollSpeed;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_BGSPRITECOMPONENT_H
