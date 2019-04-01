#include "j1App.h"
#include "Render.h"
#include "GUI.h"
#include "UIBar.h"
#include "Summoner.h"

UIBar::UIBar(iPoint pos, SDL_Rect sprite_rect, uint max, bool is_interactable)
{
	interactable = is_interactable;
	rect_box = { pos.x, pos.y, sprite_rect.w,sprite_rect.h };

	rect_sprite = sprite_rect;
	max_value = max;
	current_value = max_value;
}

void UIBar::DecreaseBar(uint value)
{
	uint height = (rect_box.h / max_value) * value;
	rect_sprite.h -= height;
	rect_box.y += height;
	current_value -= value;
}

void UIBar::IncreaseBar(uint value)
{
	uint height = (rect_box.h / max_value) * value;
	rect_sprite.h += height;
	rect_box.y -= height;
	current_value += value;
}

bool UIBar::UIBlit()
{
	iPoint screen_pos = GetScreenPos();
	if (clipping && parent)
		App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rect_sprite, 0.0F, 0.0, INT_MAX, INT_MAX, &parent->GetScreenRect());
	else
		App->render->Blit(App->gui->GetAtlas(), screen_pos.x, screen_pos.y, &rect_sprite, 0.0F, 0.0, INT_MAX, INT_MAX);
	return true;
}

uint UIBar::GetMaxValue() const
{
	return max_value;
}

uint UIBar::GetCurrentValue() const
{
	return current_value;
}
