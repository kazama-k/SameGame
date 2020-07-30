//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#include <SameAction/Game.h>
#include <SameAction/Actor/ShipActor.h>
#include <SameAction/Actor/StarBGActor.h>
#include <SameAction/Actor/SpaceBGActor.h>

namespace samegame
{
	bool SameActionGame::Initialize()
	{
		return engine::GameCore::Initialize();
	}

	void SameActionGame::Shutdown()
	{
		engine::GameCore::Shutdown();
	}

	void SameActionGame::RunLoop()
	{
		engine::GameCore::RunLoop();
	}

	void SameActionGame::LoadData()
	{
		// プレイヤーの宇宙船アクターを作成する
		new ShipActor(this);
		// 宇宙の背景を作成する
		new SpaceBGActor(this);
		// 星の背景を作成する
		new StarBGActor(this);
	}

	void SameActionGame::UnloadData()
	{
		engine::GameCore::UnloadData();
	}
}