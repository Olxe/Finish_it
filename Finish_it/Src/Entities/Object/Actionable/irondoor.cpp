#include "irondoor.h"

IronDoor::IronDoor(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state)
	: Object(obj, tile, texturePath, frameSize)
{
	AddAnimation("OPENING", frameSize, 0.12f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(3, 0) }, false);
	AddAnimation("CLOSING", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(3, 0), sf::Vector2i(2, 0), sf::Vector2i(1, 0), sf::Vector2i(0, 0) }, false);

	currentState = state;
	if (currentState == StateObject::ON) {
		this->setTextureRect(sf::IntRect(3 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
	}
	else if (currentState == StateObject::OFF) {
		this->setTextureRect(sf::IntRect(0 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
	}
	display("te");
}

IronDoor::~IronDoor()
{
	display("r");
}

void IronDoor::OnAction()
{
	if (currentState == StateObject::OFF) {
		currentState = StateObject::ON;
		LunchAnimation("OPENING");
		m_b2Body->SetActive(false);
	}
	else if (currentState == StateObject::ON) {
		currentState = StateObject::OFF;
		LunchAnimation("CLOSING");
		m_b2Body->SetActive(true);
	}
}