#ifndef _COREAI_H_
#define _COREAI_H_H

#include "Core.h"

const uint THINK_DELAY = 1.0F;

class CoreAI : public Core
{
public:
	CoreAI(pugi::xml_node entity_config, fPoint position, Faction faction);
	~CoreAI();

	virtual bool Update(float dt);
	virtual bool CleanUp();

private:
	enum class AIState {
		WAITING,
		THINKING,
		ACTING
	};

	AIState ai_state = AIState::WAITING;

	bool CanPlay();

	float dt_sum = THINK_DELAY;
};

#endif // !_COREAI_H_


