#include "wooddoor.h"

WoodDoor::WoodDoor(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state, DoorType type)
	: Object(obj, tile, texturePath, frameSize)
	, m_type(type)
{
	AddAnimation("CLOSING", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(2, 0), sf::Vector2i(1, 0), sf::Vector2i(0, 0) }, false);
	AddAnimation("OPENING", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0) }, false);

	currentState = state;
	if (currentState == StateObject::OFF) {
		this->setTextureRect(sf::IntRect(0 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
		m_b2Body->SetActive(true);
	}
	else if (currentState == StateObject::ON) {
		this->setTextureRect(sf::IntRect(2 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
		m_b2Body->SetActive(false);
	}
}

WoodDoor::~WoodDoor()
{
}

void WoodDoor::OnInteract()
{
	if (currentState == StateObject::OFF) {
		if (hero)
		{
			if (m_type == DoorType::SIMPLE_DOOR) {
				if (hero->HaveItem(ItemType::IRON_KEY) > 0) {
					if (hero->RemoveItem(ItemType::IRON_KEY)) {
						currentState = StateObject::ON;
						LunchAnimation("OPENING");
					}
				}
			}
			else if (m_type == DOUBLE_DOOR) {
				if (hero->HaveItem(ItemType::GOLDEN_KEY) > 0) {
					if (hero->RemoveItem(ItemType::GOLDEN_KEY)) {
						currentState = StateObject::ON;
						LunchAnimation("OPENING");
					}
				}
			}
		}
	}
}

void WoodDoor::OnAction()
{
	if (currentState == StateObject::OFF) {
		currentState = StateObject::ON;
		LunchAnimation("OPENING");
	}
	else if (currentState == StateObject::ON) {
		currentState = StateObject::OFF;
		LunchAnimation("CLOSING");
	}
}

void WoodDoor::OnAnimationFinished(std::string name)
{
	if(name == "OPENING") m_b2Body->SetActive(false);
	if(name == "CLOSING") m_b2Body->SetActive(true);
}
