#include "piketrap.h"

PikeTrap::PikeTrap(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize)
	: Object(obj, tile, texturePath, frameSize)
	, m_timeTick(0.7f)
	, m_currentTime(0.f)
{
	AddAnimation("OFF", frameSize, 1.5f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0) }, false);
	AddAnimation("ON", frameSize, 1.5f, std::vector<sf::Vector2i>{ sf::Vector2i(1, 0) }, false);

	currentState = StateObject::ON;
	if (const PropertiesNode * properties = tile->GetProperties()) {
		bool isOn = properties->GetProperty("isOn").ToBool(true);
		if (isOn) currentState = StateObject::ON;
		else currentState = StateObject::OFF;
	}

	if (currentState == StateObject::ON) LunchAnimation("ON");
	else if (currentState == StateObject::OFF) LunchAnimation("OFF");


	for (b2Fixture* f = m_b2Body->GetFixtureList(); f; f = f->GetNext())
	{
		b2Filter filter;
		filter.categoryBits = HitboxType::SENSOR;
		filter.maskBits = HitboxType::PLAYER_PHYSICAL;
		f->SetFilterData(filter);
	}
}

PikeTrap::~PikeTrap()
{
}

void PikeTrap::OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime >= m_timeTick) {
		if (currentState == StateObject::ON) {
			if (hero && hero->GetIsAlive()) {
				m_currentTime = 0.f;
				hero->OnDammageTaken(hero->GetMaxLife() / 10.f);
			}
		}
	}

	UpdateAnimation(deltaTime);
}

void PikeTrap::OnAnimationFinished(std::string name)
{
	if (currentState == StateObject::ON) {
		LunchAnimation("OFF");
		currentState = StateObject::OFF;
	}
	else if (currentState == StateObject::OFF) {
		LunchAnimation("ON");
		currentState = StateObject::ON;
	}
}
