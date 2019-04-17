#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <map>

#include "p2Defs.h"
#include "p2Point.h"
#include "Animation.h"
#include "PugiXml\src\pugixml.hpp"

struct SDL_Texture;
class Stat;
enum EntityType;

enum Faction {
	FACTION_NONE = -1,
	FACTION_RUSSIAN,
	FACTION_AMERICAN,
};

class Entity
{
public:
	Entity();
	Entity(pugi::xml_node entity_node, fPoint position, Faction faction);
	~Entity();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt) { return true; };
	virtual bool PostUpdate();
	virtual bool CleanUp() { return true; };
	virtual bool Start() { return true; };

	void DecreaseLife(float damage);
	void SetDebug(bool value);
	bool IsAlive();

protected:
	void LoadAnimations(pugi::xml_node anim_config);
	void LoadSprite(pugi::xml_node node);
	virtual void Die() {};
	virtual void Draw();

public:
	Faction faction;
	EntityType type;
	fPoint position;

protected:
	std::map<std::string, Animation> animations;
	Animation* current_animation = nullptr;
	SDL_Rect current_frame;
	SDL_Texture* sprite = nullptr;

	bool debug = false;
	std::map<std::string, Stat*> stats;

};
#endif // _ENTITY_H_