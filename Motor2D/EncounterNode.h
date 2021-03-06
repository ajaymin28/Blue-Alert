#ifndef _ENCOUNTER_NODE_H_
#define _ENCOUNTER_NODE_H_

#include <vector>
#include "p2Defs.h"
#include "PugiXml\src\pugixml.hpp"
#include "p2Point.h"

class UIButton;
class StrategyBuilding;

struct Encounter {
	int type = -1;
	std::vector<int> deck;
	int deck_size = 4;
	//BUFF
};


class EncounterNode
{
protected:
	std::vector<EncounterNode*> parents;
	std::vector<EncounterNode*> children;

	int id = 0;

	//------Encounter-----
	Encounter* encounter = nullptr;

	fPoint position = {0,0};

	UIButton* button;
	SDL_Rect button_rect;
	StrategyBuilding* entity;

public:
	EncounterNode(int id);
	~EncounterNode();

	void SetParent(EncounterNode * parent);
	std::vector<EncounterNode*> GetParents() const;

	EncounterNode * AddChild(EncounterNode * child);
	std::vector<EncounterNode*> GetChildren() const;

	void SetPosition(fPoint position);
	fPoint GetPosition();

	void FillEncounterDeck();
	void CreateNodeEntity();
	void CreateNode();

	UIButton* GetButton();
	StrategyBuilding* GetEntity();

	//-----Emcounter Accessors-----
	int EncounterNode::GetEncounterType() const;
	void SetEncounterType(int type);

	std::vector<int> GetEncounterDeck();

	SDL_Rect node_rect;

public:

	bool visited = false;

};

#endif // !_ENCOUNTER_NODE_H_