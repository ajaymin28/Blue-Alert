#ifndef _TESTING_SCENE_H_
#define _TESTING_SCENE_H_

#include "Scene.h"
#include "p2Point.h"

struct SDL_Texture;
struct UIButton;

class TestingScene :
	public Scene
{
public:
	TestingScene();
	~TestingScene();

	// Called before the first frame
	virtual bool Start();

	// Called before all Updates
	virtual bool PreUpdate();

	// Called each loop iteration
	virtual bool Update(float dt);

	// Called before all Updates
	virtual bool PostUpdate();

	// Called before quitting
	virtual bool CleanUp();

	virtual bool GUIEvent(UIElement* element, GUI_Event gui_event) { return true; };

private:
	SDL_Texture*	debug_tex;
	SDL_Texture*	ui_background;

	UIButton*		unit_button;
};

#endif
