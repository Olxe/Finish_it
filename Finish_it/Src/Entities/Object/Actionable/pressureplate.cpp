#include "pressureplate.h"

PressurePlate::PressurePlate(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize)
	: Object(obj, tile, texturePath, frameSize)
{
	AddAnimation("ON", frameSize, 0.f, std::vector<sf::Vector2i>{ sf::Vector2i(1, 0) }, false);
	AddAnimation("OFF", frameSize, 0.f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0) }, false);

	for (b2Fixture* f = m_b2Body->GetFixtureList(); f; f = f->GetNext())
	{
		b2Filter filter;
		filter.categoryBits = HitboxType::SENSOR;
		filter.maskBits = HitboxType::PLAYER_PHYSICAL;
		f->SetFilterData(filter);
	}
	display("created");
}

PressurePlate::~PressurePlate()
{
	display("test");
}

void PressurePlate::CheckSensorCollision(PhysicalEntity* pOther)
{
	currentState = StateObject::ON;
	LunchAnimation("ON");
}

void PressurePlate::CheckEndSensorContact(PhysicalEntity* pOther)
{
	currentState = StateObject::OFF;
	LunchAnimation("OFF");
}

void PressurePlate::OnAnimationFinished(std::string)
{
	for (auto it : m_dependentObjects) {
		it->OnAction();
	}
}
