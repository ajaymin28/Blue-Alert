#include "TransitionManager.h"
#include "j1App.h"
#include "Render.h"
#include "Window.h"
#include "p2Log.h"

TransitionManager::TransitionManager()
{

}


TransitionManager::~TransitionManager()
{

}

bool TransitionManager::Awake(pugi::xml_node &)
{
	LOG("Awakening Transition Manager");
	return true;
}

bool TransitionManager::Start()
{
	LOG("Starting Transition Manager");

	return true;
}

bool TransitionManager::PreUpdate()
{
	//TODO
	return true;
}

bool TransitionManager::Update(float dt)
{
	for each(Transition* t in active_transitions)
	{
		t->Update();
	}

	return true;
}

bool TransitionManager::PostUpdate()
{
	for each(Transition* t in active_transitions)
	{
		t->PostUpdate();
	}

	return true;
}

bool TransitionManager::CleanUp()
{
	//TODO
	return true;
}

void TransitionManager::CreateTransition(Transition::TransitionType type, float transition_time, bool is_scene_change, int scene_to_transition)
{
	active_transitions.push_back(new Transition(type, transition_time, is_scene_change, scene_to_transition));
}

void TransitionManager::CreateFadeTransition(float transition_time, bool is_scene_change, int scene_to_transition, Color color)
{
	active_transitions.push_back(new Transition(Transition::TransitionType::FADE, transition_time, is_scene_change, scene_to_transition));
	active_transitions.back()->SetColor(color);
}

void TransitionManager::CreateZoomTransition(float transition_time, bool is_scene_change, int scene_to_transition, float scale)
{
	active_transitions.push_back(new Transition(Transition::TransitionType::ZOOM, transition_time, is_scene_change, scene_to_transition));
	active_transitions.back()->SetScale(scale);
}

void TransitionManager::CreateCameraTranslation(float transition_time, iPoint origin, iPoint destination)
{
	active_transitions.push_back(new Transition(Transition::TransitionType::TRANSLATION, transition_time));
	active_transitions.back()->SetOriginAndDestination(origin, destination);
}

void TransitionManager::DestroyTransition(Transition * transition_to_destroy)
{
	active_transitions.remove(transition_to_destroy);
	delete transition_to_destroy;
}
