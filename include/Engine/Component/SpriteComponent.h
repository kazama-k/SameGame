//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_SPRITECOMPONENT_H
#define SAMEGAME_INCLUDE_ENGINE_SPRITECOMPONENT_H

#include <Engine/Core/Component.h>

namespace engine
{
	/**
	 * 画家のアルゴリズムによって「奥から手前の順序」でスプライトを描写するコンポーネント
	 */
	class SpriteComponent : public Component
	{
	public:
		/**
		 * コンストラクタ
		 * @param owner コンポーネントの所有者であるアクター
		 * @param drawOrder 描写順序．この値が小さいほどスプライトは遠くに置かれる
		 */
		explicit SpriteComponent(Actor* owner, int drawOrder = 100);
		/**
		 * デストラクタ
		 */
		~SpriteComponent() override;

		/**
		 * 受け取ったレンダラーを用いてスプライトを描写する (virtual)
		 * @param renderer 描写する対象のレンダラー
		 */
		virtual void Draw(SDL_Renderer* renderer);
		/**
		 * 受け取ったテクスチャからテクスチャの幅と高さを求める
		 * @param texture 求める対象のテクスチャ
		 */
		virtual void SetTexture(SDL_Texture* texture);

		int GetDrawOrder() const
		{
			return mDrawOrder;
		}
		__unused int GetTextureWidth() const
		{
			return mTextureWidth;
		}
		__unused int GetTextureHeight() const
		{
			return mTextureHeight;
		}

	protected:
		//! 描写するテクスチャ
		SDL_Texture* mTexture;

		//! 画家のアルゴリズムで使う描写順序
		int mDrawOrder;

		//! テクスチャの幅
		int mTextureWidth;
		//! テクスチャの高さ
		int mTextureHeight;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_SPRITECOMPONENT_H
