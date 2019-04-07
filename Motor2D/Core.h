#ifndef _CORE_H_
#define _CORE_H_

#include <map>

#include "p2Defs.h"
#include "StaticEntity.h"

class Deck;


class Core : public StaticEntity
{
public:
	Core(pugi::xml_node entity_config, fPoint position, Faction faction);
	~Core();

	bool Update(float dt);

	bool CleanUp();

	void UseCard(int number, fPoint position);
	void SetDeck(Deck* new_deck);
	Card* GetCard(int card_num) const;

	Stat* GetEnergy() const;

private:
	Deck* deck = nullptr;

	PerfTimer energy_timer;

};

#endif // _CORE_H_




