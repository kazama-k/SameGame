//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_SAMEACTION_GAME_H
#define SAMEGAME_INCLUDE_SAMEACTION_GAME_H

#include <Engine/Core/GameCore.h>

namespace samegame
{
	class SameActionGame : public engine::GameCore
	{
	public:
		SameActionGame(int x, int y, int w, int h) : engine::GameCore(x, y, w, h)
		{
		}
		~SameActionGame()
		{
		}

		/* --------------------------------------------- */

		bool Initialize() override;
		void Shutdown() override;
		void RunLoop() override;

		/* --------------------------------------------- */

	protected:
		void LoadData() override;
		void UnloadData() override;
	};
}

#endif //SAMEGAME_INCLUDE_SAMEACTION_GAME_H
