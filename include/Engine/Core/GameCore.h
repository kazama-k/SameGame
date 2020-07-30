//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_ENGINE_CORE_GAMECORE_H
#define SAMEGAME_INCLUDE_ENGINE_CORE_GAMECORE_H

#include <string>
#include <unordered_map>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

namespace engine
{
	class Actor;
	class SpriteComponent;

	/**
	 * ゲームエンジンの基礎部分を定義するクラス
	 */
	class GameCore
	{
	public:
		GameCore(int x, int y, int w, int h);
		~GameCore();

		/* --------------------------------------------- */

		/**
		 * ゲームの初期化を行うメソッド
		 * @return 初期化が成功したかどうか
		 * @note オーバーライド可能
		 */
		virtual bool Initialize();
		/**
		 * ゲームをシャットダウンするメソッド
		 * @note オーバーライド可能
		 */
		virtual void Shutdown();
		/**
		 * ゲームをループさせるメソッド
		 * @note オーバーライド可能
		 */
		virtual void RunLoop();

		/* --------------------------------------------- */

		/**
		 * アクターをゲームに追加する
		 * @param actor 追加するアクターへのポインタ
		 * @note オーバーライド不可
		 */
		void AddActor(Actor* actor);
		/**
		 * アクターをゲームから削除する
		 * @param actor 削除するアクターへのポインタ
		 * @note オーバーライド不可
		 */
		void RemoveActor(Actor* actor);

		/* --------------------------------------------- */

		/**
		 * ゲームにスプライトコンポーネントを追加する
		 * @param sprite 追加するスプライトコンポーネントへのポインタ
		 * @note オーバーライド不可
		 */
		void AddSprite(SpriteComponent* sprite);
		/**
		 * ゲームからスプライトコンポーネントを削除する
		 * @param sprite 削除するスプライトコンポーネントへのポインタ
		 * @note オーバーライド不可
		 */
		void RemoveSprite(SpriteComponent* sprite);

		/* --------------------------------------------- */

		/**
		 * 画像のファイル名からテクスチャを読みこむ
		 * @param fileName PNGファイル名
		 * @return 読み込んだテクスチャへのポインタ (SDL_Texture*)
		 */
		SDL_Texture* GetTexture(const std::string& fileName);

		/* --------------------------------------------- */

	protected:
		/**
		 * ゲームワールドの全てのアクターを作成する
		 * @note 子クラスでオーバーライドして実装
		 */
		virtual void LoadData();
		/**
		 * ゲームワールドから全てのアクターを削除する
		 * @note オーバーライド可能
		 */
		virtual void UnloadData();

		/* --------------------------------------------- */

	private:
		// 入力を処理 (オーバーライド不可)
		void ProcessInput();
		// ゲームワールドの更新 (オーバーライド不可)
		void UpdateGame();
		// 出力の生成 (オーバーライド不可)
		void GenerateOutput();

		/* --------------------------------------------- */

	private:
		// ウインドウの左上隅のx座標
		int mX;
		// ウインドウの左上隅のy座標
		int mY;
		// ウインドウの横幅
		int mW;
		// ウインドウの縦幅
		int mH;

		// SDLのウインドウ
		SDL_Window* mWindow;
		// SDLのレンダラー
		SDL_Renderer* mRenderer;

		// 現在のゲーム時間
		Uint32 mTicksCount;

		// ゲームの続行を指示するかどうか
		bool mIsRunning;
		// アクターを更新しているかどうか
		bool mIsUpdatingActors;

		// ゲーム内の全てのアクター
		std::vector<Actor*> mActors;
		// 待ち状態のアクター
		std::vector<Actor*> mPendingActors;

		// 描写される全てのスプライトコンポーネント
		std::vector<SpriteComponent*> mSprites;

		// 読み込んだテクスチャのマップ (ファイル名, テクスチャ)
		std::unordered_map<std::string, SDL_Texture*> mTextures;
	};
}

#endif //SAMEGAME_INCLUDE_ENGINE_CORE_GAMECORE_H
