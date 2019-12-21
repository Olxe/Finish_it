#include "lever.h"

Lever::Lever(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state)
	: Object(obj, tile, texturePath, frameSize)
{
	AddAnimation("ON", frameSize, 0.08f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(3, 0) }, false);
	AddAnimation("OFF", frameSize, 0.08f, std::vector<sf::Vector2i>{ sf::Vector2i(3, 0), sf::Vector2i(2, 0), sf::Vector2i(1, 0), sf::Vector2i(0, 0) }, false);

	currentState = state;
	if (currentState == StateObject::OFF) {
		this->setTextureRect(sf::IntRect(0 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
	}
	else if (currentState == StateObject::ON) {
		this->setTextureRect(sf::IntRect(3 * (int)frameSize.x, 0 * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
	}
}

Lever::~Lever()
{
}

void Lever::OnInteract()
{
	if (!IsCurrentAnimationActive()) {
		if (currentState == StateObject::OFF) {
			currentState = StateObject::ON;
			LunchAnimation("ON");
		}
		else if (currentState == StateObject::ON) {
			currentState = StateObject::OFF;
			LunchAnimation("OFF");
		}
	}
}

void Lever::OnAnimationFinished(std::string name)
{
	for (auto it : m_dependentObjects) {
		it->OnAction();
	}
}
