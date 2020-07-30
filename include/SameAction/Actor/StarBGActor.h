//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_SAMEACTION_ACTOR_STARBGACTOR_H
#define SAMEGAME_INCLUDE_SAMEACTION_ACTOR_STARBGACTOR_H

#include <Engine/Core/Actor.h>

namespace engine
{
	class GameCore;
}

namespace samegame
{
	class StarBGActor : public engine::Actor
	{
	public:
		explicit StarBGActor(engine::GameCore* game);
	};
}

#endif //SAMEGAME_INCLUDE_SAMEACTION_ACTOR_STARBGACTOR_H
