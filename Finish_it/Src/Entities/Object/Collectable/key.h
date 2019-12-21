#pragma once

#include "../object.h"
#include "../../Playable/heroes.h"

/*enum KeyType
{
	IRON_KEY,
	GOLDEN_KEY
};*/

class Key: public Object
{
public:
	Key(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, ItemType type);
	~Key();

	void CheckSensorCollision(PhysicalEntity* pOther) override;
	void Draw(sf::RenderWindow& window) override;

private:
	ItemType m_type;

};