#ifndef _STRATEGY_MAP_H_
#define _STRATEGY_MAP_H_

#include "Scene.h"
#include "p2Point.h"
#include "EncounterTree.h"
#include "UIButton.h"
#include "UIImage.h"
#include "UIScrollBar.h"



struct SDL_Texture;

class StrategyMapScene :
	public Scene
{
public:
	StrategyMapScene();
	~StrategyMapScene();

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

	virtual bool GUIEvent(UIElement* element, GUI_Event gui_event);

	void AddCardToDeck(UIElement* element, uint num);

	void StartUI();

private:
	UIImage* banner;
	UIImage* options;
	UIImage* troops_background;
	UIImage* main_panel;
	UILabel* gold;
	UILabel* text_menu;
	UILabel* troops_text;
	UILabel* buildings_text;
	UILabel* back_cross_text;
	UILabel* musiclabel;
	UILabel* fxlabel;
	UILabel* savegamelabel;
	UILabel* resume_label;
	UIScrollBar* music_slider;
	UIScrollBar* fx_slider;
	UIButton* settings_button;

	UIButton* resume_settings_button;
	UIButton* menu_button;
	UIButton* backbutton_t_b;
	UIButton* troops_button;
	UIButton* buildings_button;
	UIButton* savegamebutton;
	UIButton* deck_buttons[4];
	UIButton* collection_buttons[9];

	UIButtonText* menu_button;
	UIButtonText* backbutton_t_b;
	UIButtonText* troops_button;
	UIButtonText* buildings_button;

	//Building Menu
	UIImage* buildings_background;
	UIImage* core_image;
	UILabel* core_title;
	UILabel* core_health;
	UILabel* core_energy;
	UILabel* core_lvl_up_health_cost;
	UILabel* core_lvl_up_energy_cost;
	UILabel* core_info;
	UIButton* core_lvl_up_health;
	UIButton* core_lvl_up_energy;

	UIImage* building_infantry_image = nullptr;
	UISelectableButton* building_infantry_button = nullptr;
	UILabel* building_infantry_info = nullptr;

	UIImage* building_aerial_image = nullptr;
	UISelectableButton* building_aerial_button = nullptr;
	UILabel* building_aerial_info = nullptr;

	UIImage* building_land_image = nullptr;
	UISelectableButton* building_land_button = nullptr;
	UILabel* building_land_info = nullptr;

	UIButton* level_up = nullptr;
	UILabel* building_title = nullptr;

	UILabel* buildings_title[3];
	
	// Troops Menu
	UIButton* deck_buttons[4];
	UIButton* collection_buttons_allies[9];
	UIButton* collection_buttons_enemies[9];
	UILabel* troops_title[3];
	UIButton* change_side_button;
	UILabel* side_label;

	//Info Showing
	UIImage* info_image = nullptr;
	UILabel* health_label = nullptr;
	UILabel* attack_label = nullptr;
	UILabel* defense_label = nullptr;
	UILabel* units_label = nullptr;
	UILabel* range_label = nullptr;
	UIBar*	 energy_bar = nullptr;


	float drag_threshhold = 0.2f;
	bool dragable = true;

	iPoint limit_center = {-480, 1117};
	int limit_radius = 700;

	iPoint last_camera_position;

};

#endif

