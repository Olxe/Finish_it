#pragma once

#include "../Physic/physicalentity.h"
#include "../Physic/physicalentity.h"

class PhysicalTile: public PhysicalEntity
{
public:
	PhysicalTile(const TileNode* tile, std::string textureFile, sf::Vector2i sizeTile, sf::Vector2f position);
	~PhysicalTile();

	virtual void OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime) { ; }
	virtual void CheckCollision(PhysicalEntity* pOther) { ; }
	virtual void CheckEndContact(PhysicalEntity* pOther) { ; }
	void CheckSensorCollision(PhysicalEntity* pOther) override;
	void CheckEndSensorContact(PhysicalEntity* pOther) override;

private:

};

