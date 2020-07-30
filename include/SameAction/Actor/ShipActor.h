//
// Created by Kentaro KAZAMA on 2020/07/29.
//

#ifndef SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SHIPACTOR_H
#define SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SHIPACTOR_H

#include <Engine/Core/Actor.h>

namespace engine
{
	class GameCore;
}

namespace samegame
{
	class ShipActor : public engine::Actor
	{
	public:
		explicit ShipActor(engine::GameCore* game);

		void UpdateActor(float deltaTime) override;
		void ActorInput(const uint8_t* keyState) override;

	private:
		// レーザーの冷却時間
		float mLaserCoolDown;
	};
}

#endif //SAMEGAME_INCLUDE_SAMEACTION_ACTOR_SHIPACTOR_H
