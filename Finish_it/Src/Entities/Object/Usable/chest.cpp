#include "chest.h"

Chest::Chest(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state, ChestType type)
	: Object(obj, tile, texturePath, frameSize)
	, m_type(type)
	, isEmpty(false)
{
	currentState = state;
	AddAnimation("OPENING", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0) }, false);
}

Chest::~Chest()
{
}

void Chest::OnAnimationFinished(std::string name)
{
	if (name == "OPENING") {
		
	}
}

void Chest::OnInteract()
{
	if (currentState == StateObject::OFF && !isEmpty) {
		currentState = StateObject::ON;
		LunchAnimation("OPENING");

		isEmpty = true;
		if (m_type == ChestType::GOLDEN_CHEST) {
			if (hero) {
				if (hero->IsMainHero) {
					hero->AddItem(ItemType::GOLD);
				}
			}
		}
		else if (m_type == ChestType::ITEM_CHEST) {
			if (hero) {
				if (hero->IsMainHero) {
					hero->AddItem(ItemType::GOLD);
				}
			}
		}
	}
}
