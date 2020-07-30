//
// Created by Kentaro KAZAMA on 2020/07/28.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_ANIMSPRITECOMPONENT_H
#define SAMEGAME_INCLUDE_ENGINE_ANIMSPRITECOMPONENT_H

#include <vector>

#include <Engine/Component/SpriteComponent.h>

namespace engine
{
	/**
	 * スプライトアニメーションを実現するためのコンポーネント
	 * 2D 画像を素早く切り替えて表示する「パタパタアニメ」で実装する
	 */
	class AnimSpriteComponent : public SpriteComponent
	{
	public:
		/**
		 * コンストラクタ
		 * @param owner このコンポーネントの所有者であるアクター
		 * @param drawOrder 描写順序．この値が小さいほどスプライトは遠くに置かれる
		 */
		explicit AnimSpriteComponent(Actor* owner, int drawOrder = 100);

		/**
		 * フレームごとにアニメーションを更新する
		 * @see Component
		 * @param deltaTime 更新時のデルタタイム
		 */
		void Update(float deltaTime) override;
		/**
		 * アニメーションに使うテクスチャを設定する
		 * @param textures アニメーションするテクスチャの一覧としての配列
		 */
		void SetAnimTextures(const std::vector<SDL_Texture*>& textures);

		__unused float GetAnimFPS() const
		{
			return mAnimFPS;
		}
		__unused void SetAnimFPS(float fps)
		{
			mAnimFPS = fps;
		}

	private:
		//! アニメーションする全てのテクスチャ
		std::vector<SDL_Texture*> mAnimTextures;

		//! 現在表示しているフレーム
		float mCurrentFrame;
		//! アニメーションのフレームレート (FPS)
		float mAnimFPS;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_ANIMSPRITECOMPONENT_H
