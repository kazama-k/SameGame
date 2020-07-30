//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <Engine/Core/Actor.h>
#include <Engine/Core/GameCore.h>

#include <Engine/Component/SpriteComponent.h>

#include <Math/Random.h>

namespace engine
{
	GameCore::GameCore(int x, int y, int w, int h)
		: mX(x), mY(y), mW(w), mH(h), mWindow(nullptr), mRenderer(nullptr), mIsRunning(true), mIsUpdatingActors(false)
	{
	}

	GameCore::~GameCore() = default;

	void GameCore::Shutdown()
	{
		UnloadData();
		IMG_Quit();
		SDL_DestroyWindow(mWindow);
		SDL_DestroyRenderer(mRenderer);

		SDL_Quit();
	}

	/* --------------------------------------------- */

	bool GameCore::Initialize()
	{
		// SDLシステムの初期化
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		{
			SDL_Log("SDLを初期化できませんでした: %s", SDL_GetError());
			return false;
		}

		// ウインドウの初期化
		mWindow = SDL_CreateWindow("Test Game", mX, mY, mW, mH, 0);
		if (!mWindow)
		{
			SDL_Log("ウインドウを作成できませんでした: %s", SDL_GetError());
			return false;
		}

		// レンダラーの初期化
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!mRenderer)
		{
			SDL_Log("レンダラーを作成できませんでした: %s", SDL_GetError());
			return false;
		}

		// SDL_Imageの初期化
		if (IMG_Init(IMG_INIT_PNG) == 0)
		{
			SDL_Log("SDL_image を初期化できませんでした: %s", SDL_GetError());
			return false;
		}

		// 乱数初期化
		math::Random::Init();

		// ゲームデータの読み込み
		LoadData();

		// 現在のゲーム時間を取得して初期化
		mTicksCount = SDL_GetTicks();

		return true;
	}

	void GameCore::RunLoop()
	{
		while (mIsRunning)
		{
			// 入力を処理
			ProcessInput();
			// ゲームワールドの更新
			UpdateGame();
			// 出力の生成
			GenerateOutput();
		}
	}

	/* --------------------------------------------- */

	void GameCore::AddActor(Actor* actor)
	{
		// アクターを更新している最中であれば待ち行列に追加
		if (mIsUpdatingActors)
		{
			mPendingActors.emplace_back(actor);
		}
		else
		{
			mActors.emplace_back(actor);
		}
	}

	void GameCore::RemoveActor(Actor* actor)
	{
		// actorは待ち行列に含まれているか？
		auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
		// 含まれていた場合，最後に移動してからpop
		if (iter != mPendingActors.end())
		{
			std::iter_swap(iter, mPendingActors.end() - 1);
			mPendingActors.pop_back();
		}

		// actorはゲーム内にすでに追加されているアクターか？
		iter = std::find(mActors.begin(), mActors.end(), actor);
		if (iter != mActors.end())
		{
			std::iter_swap(iter, mActors.end() - 1);
			mActors.pop_back();
		}
	}

	/* --------------------------------------------- */

	void GameCore::AddSprite(SpriteComponent* sprite)
	{
		// ソート済みの配列で挿入点を見つける
		// (それは自分よりも描写順序の高い最初の要素の位置)

		// 追加するスプライトの描写順序
		int myDrawOrder = sprite->GetDrawOrder();
		// 描写する全てのテクスチャのイテレータ
		auto iter = mSprites.begin();
		for (; iter != mSprites.end(); ++iter)
		{
			// 自分よりも描写順序が高くなった要素の時点でbreak
			if (myDrawOrder < (*iter)->GetDrawOrder())
			{
				break;
			}
		}

		// 現在のイテレータの一つ前の位置にスプライトを追加
		mSprites.insert(iter, sprite);
	}

	void GameCore::RemoveSprite(SpriteComponent* sprite)
	{
		// (mSpritesはソート済みなのでスワップは不要)
		// (AddSpriteですでにソートされた状態で全てのスプライトが追加されている)
		auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
		mSprites.erase(iter);
	}

	/* --------------------------------------------- */

	SDL_Texture* GameCore::GetTexture(const std::string& fileName)
	{
		// 読み込んだ画像のテクスチャへのポインタ
		SDL_Texture* texture = nullptr;

		// テクスチャがすでに読み込まれ，マップmTexturesに入っているか検証
		auto iter = mTextures.find(fileName);
		if (iter != mTextures.end())
		{
			// 入っていた場合対応するテクスチャをtextureに格納
			texture = iter->second;
		}
		else
		{
			// テクスチャが入っていない (読み込まれていない) 場合
			// ファイルから画像を読み込みSDL_Surfaceに格納
			SDL_Surface* surface = IMG_Load(fileName.c_str());
			if (!surface)
			{
				SDL_Log("テクスチャファイルの読み込みに失敗しました: %s", fileName.c_str());
				return nullptr;
			}

			// SDL_SurfaceからSDL_Textureを生成
			texture = SDL_CreateTextureFromSurface(mRenderer, surface);
			// SDL_Surfaceを開放
			SDL_FreeSurface(surface);

			if (!texture)
			{
				SDL_Log("SDL_Surfaceをテクスチャ型に変換できませんでした: %s", fileName.c_str());
				return nullptr;
			}

			// テクスチャマップに追加
			mTextures.emplace(fileName.c_str(), texture);
		}

		return texture;
	}

	/* --------------------------------------------- */

	void GameCore::LoadData()
	{
		// 子クラスの各ゲーム専用クラスでデータの読み込みを実装
	}

	void GameCore::UnloadData()
	{
		// 全てのアクターを削除する
		// NOTE: ~ActorはRemoveActorを呼ぶことに注意
		while (!mActors.empty())
		{
			delete mActors.back();
		}

		// テクスチャを放棄
		for (auto tex : mTextures)
		{
			SDL_DestroyTexture(tex.second);
		}
		mTextures.clear();
	}

	/* --------------------------------------------- */

	void GameCore::ProcessInput()
	{
		// SDLに対するイベントを格納する変数
		SDL_Event event;

		// キューにイベントがあれば繰り返す
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				mIsRunning = false;
				break;
			}
		}

		// 現在のキーボードの状態
		const Uint8* keyState = SDL_GetKeyboardState(nullptr);

		// [ESC] が押された場合でもゲームを終了させる
		if (keyState[SDL_SCANCODE_ESCAPE])
		{
			mIsRunning = false;
		}

		// 全アクターのProcessInputを呼び出す
		mIsUpdatingActors = true;
		for (const auto actor : mActors)
		{
			actor->ProcessInput(keyState);
		}
		mIsUpdatingActors = false;
	}

	void GameCore::UpdateGame()
	{
		// 最後のフレームから16ms待つ
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

		// 現在のデルタタイム
		float deltaTime = static_cast<float>(SDL_GetTicks() - mTicksCount) / 1000.0f;
		if (deltaTime > 0.05f)
		{
			deltaTime = 0.05f;
		}

		// 全てのアクターを更新中にする
		mIsUpdatingActors = true;
		for (const auto actor : mActors)
		{
			// アクターを更新
			actor->Update(deltaTime);
		}
		mIsUpdatingActors = false;

		// 待ち状態だったアクターをmActorsに移動
		for (const auto pending : mPendingActors)
		{
			mActors.emplace_back(pending);
		}
		mPendingActors.clear();

		// 死んだアクターを追加するための一時配列
		std::vector<Actor*> deadActors;
		for (const auto actor : mActors)
		{
			// 死んだアクターをdeadActorsに追加する
			if (actor->GetState() == Actor::EDead)
			{
				deadActors.emplace_back(actor);
			}
		}

		// 死んだアクターをmActorsからもろとも削除する
		for (auto actor : deadActors)
		{
			delete actor;
		}
	}

	void GameCore::GenerateOutput()
	{
		// 描写色を黒にセットする
		SDL_SetRenderDrawColor(
			mRenderer,
			0,
			0,
			0,
			255
		);
		// バックバッファを現在の描写色でクリアする
		SDL_RenderClear(mRenderer);

		// 全てのスプライトコンポーネントを描写する
		for (const auto sprite : mSprites)
		{
			sprite->Draw(mRenderer);
		}

		// フロントバッファとバックバッファの交換
		SDL_RenderPresent(mRenderer);
	}
}