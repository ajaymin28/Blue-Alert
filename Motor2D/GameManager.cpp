#include "j1App.h"
#include "CardManager.h"
#include "Deck.h"
#include "EncounterNode.h"
#include "EncounterTree.h"
#include "StrategyBuilding.h"
#include "CardManager.h"
#include "EntityManager.h"

#include "GameManager.h"



GameManager::GameManager()
{

}


GameManager::~GameManager()
{
}

bool GameManager::Awake(pugi::xml_node &)
{

	return true;
}

bool GameManager::Start()
{
	encounter_tree = new EncounterTree();
	encounter_tree->CreateTree();

	CreatePlayerDeck();

	return true;
}

bool GameManager::CleanUp()
{
	collection.clear();
	encounter_tree->CleanTree();
	return true;
}

bool GameManager::PostUpdate()
{
	encounter_tree->UpdateTree();
	return true;
}

EncounterTree* GameManager::GetEncounterTree()
{
	return encounter_tree;
}

Deck * GameManager::GetPlayerDeck()
{
	return combat_deck;
}

bool GameManager::IsInPlayerDeck(Card * card)
{
	bool ret = false;

	Card* deck_card = combat_deck->GetCard(card->type);

	if (deck_card) {
		ret = true;
	}
	else {
		ret = false;
	}

	return ret;
}

void GameManager::CreatePlayerDeck()
{
	collection.push_back(App->card_manager->CreateCard(EntityType::G_I));
	collection.push_back(App->card_manager->CreateCard(EntityType::SNIPER));
	collection.push_back(App->card_manager->CreateCard(EntityType::GRIZZLY));
	collection.push_back(App->card_manager->CreateCard(EntityType::HARRIER));
	collection.push_back(App->card_manager->CreateCard(EntityType::ROBOT));

	combat_deck = new Deck();
	combat_deck->AddCard(GetCardFromCollection(EntityType::G_I));
	combat_deck->AddCard(GetCardFromCollection(EntityType::SNIPER));
	combat_deck->AddCard(GetCardFromCollection(EntityType::GRIZZLY));
	combat_deck->AddCard(GetCardFromCollection(EntityType::HARRIER));
}




Card * GameManager::GetCardFromCollection(EntityType card_type)
{
	Card* card = nullptr;
	for each (Card* c in collection)
	{
		if (c->type == card_type)
		{
			card = c;
		}
	}

	if (card != nullptr)
	{
		return card;
	}
	else {
		LOG("The card u tried to get is not existent in collection");
		return nullptr;
	}
}

void GameManager::AddCardToCollection(EntityType card_type)
{
	bool found = false;

	for each (Card* c in collection)
	{
		if (c->type == card_type)
		{
			found = true;
			c->Upgrade();
		}
	}

	if(!found) collection.push_back(App->card_manager->CreateCard(card_type));
	LOG("KAJAWOD");
}
