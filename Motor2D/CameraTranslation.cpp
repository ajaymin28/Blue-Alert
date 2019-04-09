#include "CameraTranslation.h"
#include "j1App.h"
#include "Render.h"
#include "p2Log.h"
#include "Window.h"
#include <cmath>


CameraTranslation::CameraTranslation(float transition_time, iPoint destination) : Transition(transition_time)
{
	uint w, h;
	App->win->GetWindowSize(w, h);

	origin = { App->render->camera.x, App->render->camera.y };
	this->destination = {(int)(destination.x + w * 0.5), -(int)(destination.y + h * 0.5)};
}

CameraTranslation::~CameraTranslation()
{

}

void CameraTranslation::Entering()
{
	Transition::Entering();
	LOG("ORIGIN %i , %i  :  DESTINATION %i , %i", origin.x, origin.y, destination.x, destination.y);


	float percent = current_time->ReadSec()*(1 / transition_time);

	LOG("percent %f", percent);

	iPoint step = Lerp(percent, origin, destination);


	App->render->camera.x = step.x;
	App->render->camera.y = step.y;

	LOG("Step %f , %f", step.x, step.y);
}

void CameraTranslation::SetOriginAndDestination(iPoint origin, iPoint destination)
{
	this->origin = origin;
	this->destination = destination;
}
