//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_SAMEACTION_ACTOR_LASERACTOR_H
#define SAMEGAME_INCLUDE_SAMEACTION_ACTOR_LASERACTOR_H

#include <Engine/Core/Actor.h>

namespace engine
{
	class GameCore;
}

namespace samegame
{
	class LaserActor : public engine::Actor
	{
	public:
		explicit LaserActor(engine::GameCore* game);

		void UpdateActor(float deltaTime) override;

	private:
		// この時間が経過すると自動的にレーザーは消える
		float mDeathTimer;
	};
}

#endif //SAMEGAME_INCLUDE_SAMEACTION_ACTOR_LASERACTOR_H
