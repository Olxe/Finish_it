#include "physicaltile.h"

PhysicalTile::PhysicalTile(const TileNode* tile, std::string textureFile, sf::Vector2i sizeTile, sf::Vector2f position)
	: PhysicalEntity(0, "", tile->GetType())
{
	InitEntity(textureFile, (sf::Vector2f)sizeTile, sf::Vector2i(0, 0), position, 0.f);
	this->setTextureRect(sf::IntRect(tile->GetCoordTextureX() * sizeTile.x, tile->GetCoordTextureY() * sizeTile.y, sizeTile.x, sizeTile.y));

	InitBody(tile, position, 0.f, this->getOrigin(), this);
}

PhysicalTile::~PhysicalTile()
{
}

void PhysicalTile::CheckSensorCollision(PhysicalEntity* pOther)
{
	if (PhysicalEntity * entity = static_cast<PhysicalEntity*>(pOther)) {
		this->setColor(sf::Color(255, 255, 255, 150));
	}
}

void PhysicalTile::CheckEndSensorContact(PhysicalEntity* pOther)
{
	if(PhysicalEntity * entity = static_cast<PhysicalEntity*>(pOther)){
		this->setColor(sf::Color(255, 255, 255, 255));
	}
}