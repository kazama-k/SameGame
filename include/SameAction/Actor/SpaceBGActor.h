//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SPACEBGACTOR_H
#define SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SPACEBGACTOR_H

#include <Engine/Core/Actor.h>

namespace engine
{
	class GameCore;
}

namespace samegame
{
	class SpaceBGActor : public engine::Actor
	{
	public:
		explicit SpaceBGActor(engine::GameCore* game);
	};
}

#endif //SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SPACEBGACTOR_H
