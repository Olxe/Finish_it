#pragma once

#include "../Physic/physicalentity.h"
#include "inventory.h"
#include "Inventory/Item/item.h"

enum Direction
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

class Heroes: public PhysicalEntity, public Inventory
{
public:
	Heroes(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction);
	virtual ~Heroes();

	virtual void OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime) override;
	virtual void OnDammageTaken(const float& amount) override;

	virtual void OnMove(const sf::Vector2i& velocity, const float& deltaTime);

	virtual void OnLeftClickPressed(const sf::Vector2f& mousePosition);
	virtual void OnLeftClickReleased(const sf::Vector2f& mousePosition);
	virtual void OnLeftClick(const sf::Vector2f& mousePosition);

	virtual void OnRightClickPressed(const sf::Vector2f& mousePosition);
	virtual void OnRightClickReleased(const sf::Vector2f& mousePosition);
	virtual void OnRightClick(const sf::Vector2f& mousePosition);

	virtual void CheckCollision(PhysicalEntity* pOther) { ; }
	virtual void CheckSensorCollision(PhysicalEntity* pOther) { ; }
	virtual void CheckEndContact(PhysicalEntity* pOther) { ; }
	virtual void CheckEndSensorContact(PhysicalEntity* pOther) { ; }

	bool IsMainHero;

protected:
	void OnAnimationFinished(std::string name) override;

protected:
	Direction currentDirection;
	sf::Vector2i lastVelocity;
	const float minimum = 0.00001f;
	
};
