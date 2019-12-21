#include "heroes.h"

Heroes::Heroes(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction)
	: PhysicalEntity(obj->GetGid(), obj->GetName(), tile->GetType())
	, currentDirection(direction)
	, lastVelocity(sf::Vector2f(0.f, 0.f))
	, IsMainHero(false)
{
	InitStats(tile->GetProperties());
	InitEntity(texturePath, frameSize, sf::Vector2i(0, 0), obj->GetPosition(), obj->GetRotation());
	InitBody(tile, this->getPosition(), this->getRotation(), this->getOrigin(), this);

	for (b2Fixture* f = m_b2Body->GetFixtureList(); f; f = f->GetNext())
	{
		if (f->IsSensor()) {
			b2Filter filter;
			filter.categoryBits = HitboxType::PLAYER_SENSOR;
			filter.maskBits = HitboxType::SENSOR;
			f->SetFilterData(filter);
		}
		else {
			b2Filter filter;
			filter.categoryBits = HitboxType::PLAYER_PHYSICAL;
			filter.maskBits = HitboxType::PHYSICAL | HitboxType::SENSOR;
			f->SetFilterData(filter);
		}
	}

	std::cout << this << " -> Hero" << std::endl;
}

Heroes::~Heroes()
{
}

void Heroes::OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime)
{
	UpdateAnimation(deltaTime);

	if (!m_b2Body || !GetIsAlive()) return;
	this->setPosition(m_b2Body->GetPosition().x * SCALE, m_b2Body->GetPosition().y * SCALE);
}

void Heroes::OnDammageTaken(const float& amount)
{
	if (!m_b2Body || !GetIsAlive()) return;

	RemoveLife(amount);
	if (GetIsAlive()) {
		display(amount);
		if (currentDirection == Direction::UP) LunchAnimation("HURT_BACK");
		if (currentDirection == Direction::DOWN) LunchAnimation("HURT_FRONT");
		if (currentDirection == Direction::LEFT) LunchAnimation("HURT_LEFT");
		if (currentDirection == Direction::RIGHT) LunchAnimation("HURT_RIGHT");
	}
	else {
		if (currentDirection == Direction::UP) LunchAnimation("DEAD_BACK");
		if (currentDirection == Direction::DOWN) LunchAnimation("DEAD_FRONT");
		if (currentDirection == Direction::LEFT) LunchAnimation("DEAD_LEFT");
		if (currentDirection == Direction::RIGHT) LunchAnimation("DEAD_RIGHT");
	}
}

void Heroes::OnMove(const sf::Vector2i& velocity, const float& deltaTime)
{
	if (!m_b2Body || !GetIsAlive()) return;

	b2Vec2 vel = b2Vec2(m_b2Body->GetLinearVelocity().x * deltaTime, m_b2Body->GetLinearVelocity().y * deltaTime);

	if (velocity.x == 0 || velocity.y == 0) lastVelocity = sf::Vector2i(0, 0);
	if (lastVelocity.y > velocity.y) currentDirection = Direction::UP;
	if (lastVelocity.y < velocity.y) currentDirection = Direction::DOWN;
	if (lastVelocity.x > velocity.x) currentDirection = Direction::LEFT;
	if (lastVelocity.x < velocity.x) currentDirection = Direction::RIGHT;
	lastVelocity = velocity;

	if ((velocity.x == 0 && velocity.y == 0) || (fabs(vel.x) < minimum && fabs(vel.y) < minimum))
	{
		if (currentDirection == Direction::UP) LunchAnimation("IDLE_BACK");
		if (currentDirection == Direction::DOWN) LunchAnimation("IDLE_FRONT");
		if (currentDirection == Direction::LEFT) LunchAnimation("IDLE_LEFT");
		if (currentDirection == Direction::RIGHT) LunchAnimation("IDLE_RIGHT");
	}
	else
	{
		if (currentDirection == 1) LunchAnimation("WALK_BACK");
		if (currentDirection == 2) LunchAnimation("WALK_FRONT");
		if (currentDirection == 3) LunchAnimation("WALK_LEFT");
		if (currentDirection == 4) LunchAnimation("WALK_RIGHT");
	}

	vel *= 0 * deltaTime;
	if (!VelocityCanceled()){// || true) {
		float speed = GetMaxSpeed();
		if (abs(velocity.x) == 1 && abs(velocity.y) == 1) speed /= 1.3f;//pythagore speed
		vel.x = velocity.x * speed * deltaTime;
		vel.y = velocity.y * speed * deltaTime;
	}
	m_b2Body->SetLinearVelocity(b2Vec2(vel.x, vel.y));
}

void Heroes::OnLeftClickPressed(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
}

void Heroes::OnLeftClickReleased(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
	if (Animation * anim = CurrentAnimation()) {
		anim->Stop();
	}
}

void Heroes::OnLeftClick(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
	sf::Vector2f vecDirection = mousePosition - this->getPosition();
	float angle = std::atan2f(vecDirection.y, vecDirection.x) * 180.f / 3.14f;

	if (angle < 0.0f) angle = 360.0f + angle;
	else if (angle > 360.0f) angle -= 360.0f;

	if (angle >= 225.f && angle <= 315.f) {
		if (LunchAnimation("ATTACK_BACK")) currentDirection = Direction::UP;
	}
	if (angle >= 45.f && angle <= 135.f) {
		if (LunchAnimation("ATTACK_FRONT")) currentDirection = Direction::DOWN;
	}
	if (angle > 135.f && angle < 225.f) {
		if (LunchAnimation("ATTACK_LEFT")) currentDirection = Direction::LEFT;
	}
	if ((angle > 315.f && angle <= 360.f) || (angle >= 0.f && angle < 45.f)) {
		if (LunchAnimation("ATTACK_RIGHT")) currentDirection = Direction::RIGHT;
	}

}

void Heroes::OnRightClickPressed(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
	m_b2Body->SetTransform(b2Vec2(mousePosition.x / SCALE, mousePosition.y / SCALE), m_b2Body->GetAngle());
}

void Heroes::OnRightClickReleased(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
}

void Heroes::OnRightClick(const sf::Vector2f& mousePosition)
{
	if (!m_b2Body || !GetIsAlive()) return;
}

void Heroes::OnAnimationFinished(std::string name)
{	
	if (!m_b2Body || !GetIsAlive()) return;
}
