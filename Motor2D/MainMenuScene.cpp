#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Map.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Core.h"
#include "CoreAI.h"
#include "PathFinding.h"
#include "UIAnimatedImage.h"
#include "UIButton.h"
#include "UIBar.h"
#include "GUI.h"
#include "Pathfinding.h"
#include "SceneManager.h"
#include "TransitionManager.h"
#include "CardManager.h"
#include "Deck.h"
#include "MainMenuScene.h"
#include "BattleScene.h"
#include "GameManager.h"
#include "EncounterTree.h"
#include "EncounterNode.h"
#include "UIImage.h"
#include "UILabel.h"
#include "GameManager.h"
#include "Stat.h"
#include <stdlib.h>
#include <time.h>


MainMenuScene::MainMenuScene() : Scene()
{

}

// Destructor
MainMenuScene::~MainMenuScene()
{}

// Called before the first frame
bool MainMenuScene::Start()
{
	
	//Initialize UI
	StartUI();

	return true;
}

// Called each loop iteration
bool MainMenuScene::PreUpdate()
{
	

	return true;
}

// Called each loop iteration
bool MainMenuScene::Update(float dt)
{
	

	return true;
}

// Called each loop iteration
bool MainMenuScene::PostUpdate()
{
	bool ret = true;

	
	return ret;
}

// Called before quitting
bool MainMenuScene::CleanUp()
{
	LOG("Freeing scene");

	

	return true;
}

bool MainMenuScene::GUIEvent(UIElement * element, GUI_Event gui_event)
{
	if (gui_event == GUI_Event::LEFT_CLICK_DOWN) {

		return true;
	}

}

void MainMenuScene::StartUI() {

	SDL_Rect large_button_rect[3];
	large_button_rect[0] = { 0,533,220,51 };
	large_button_rect[1] = { 0,585,220,51 };
	large_button_rect[2] = { 0,637,220,51 };

	MenuBackground = App->gui->CreateImage({ 0,0 }, { 1976,987,1024,768 },nullptr);

	exitbutton = App->gui->CreateButton({ 785,650 }, large_button_rect,MenuBackground);
	exitlabel = App->gui->CreateLabel({ 10,10 }, "", 20, "EXIT GAME", {0,0,0,0},0,exitbutton);
}
