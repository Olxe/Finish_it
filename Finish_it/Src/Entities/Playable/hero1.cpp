#include "hero1.h"

Hero1::Hero1(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction)
	: Heroes(obj, tile, texturePath, frameSize, direction)
{
	AddAnimation("WALK_BACK", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 12), sf::Vector2i(1, 12), sf::Vector2i(2, 12), sf::Vector2i(3, 12) });
	AddAnimation("WALK_FRONT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 13), sf::Vector2i(1, 13), sf::Vector2i(2, 13), sf::Vector2i(3, 13) });
	AddAnimation("WALK_LEFT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 14), sf::Vector2i(1, 14), sf::Vector2i(2, 14), sf::Vector2i(3, 14) });
	AddAnimation("WALK_RIGHT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 15), sf::Vector2i(1, 15), sf::Vector2i(2, 15), sf::Vector2i(3, 15) });

	AddAnimation("IDLE_BACK", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 8), sf::Vector2i(1, 8), sf::Vector2i(2, 8), sf::Vector2i(3, 8) });
	AddAnimation("IDLE_FRONT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 9), sf::Vector2i(1, 9), sf::Vector2i(2, 9), sf::Vector2i(3, 9) });
	AddAnimation("IDLE_LEFT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 10), sf::Vector2i(1, 10), sf::Vector2i(2, 10), sf::Vector2i(3, 10) });
	AddAnimation("IDLE_RIGHT", frameSize, 0.15f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 11), sf::Vector2i(1, 11), sf::Vector2i(2, 11), sf::Vector2i(3, 11) });

	AddAnimation("ATTACK_BACK", frameSize, 0.05f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(3, 0) }, false, true);
	AddAnimation("ATTACK_FRONT", frameSize, 0.05f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1) }, false, true);
	AddAnimation("ATTACK_LEFT", frameSize, 0.05f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 2), sf::Vector2i(1, 2), sf::Vector2i(2, 2), sf::Vector2i(3, 2) }, false, true);
	AddAnimation("ATTACK_RIGHT", frameSize, 0.05f, std::vector<sf::Vector2i>{ sf::Vector2i(0, 3), sf::Vector2i(1, 3), sf::Vector2i(2, 3), sf::Vector2i(3, 3) }, false, true);

	LunchAnimation("IDLE_FRONT");
}

Hero1::~Hero1()
{
}

/*void Player::lookAt(const sf::Vector2f& pos, const float& speed)
{
	sf::Vector2f toTarget = pos - this->getPosition();
	float desiredAngle = std::atan2f(toTarget.y, toTarget.x);

	if (speed <= 0.f) {
		m_b2Body->SetTransform(m_b2Body->GetPosition(), desiredAngle);
	}

	desiredAngle *= 180.f / 3.14f;
	float totalRotation = desiredAngle - this->getRotation();

	while (totalRotation < -180) totalRotation += 360;
	while (totalRotation > 180) totalRotation -= 360;

	float speedRotation = speed / 180.f * 3.14f;

	float newAngle = m_b2Body->GetAngle() + std::min(speedRotation, std::max(-speedRotation, totalRotation / 180.f * 3.14f));
	m_b2Body->SetTransform(m_b2Body->GetPosition(), newAngle);
}*/