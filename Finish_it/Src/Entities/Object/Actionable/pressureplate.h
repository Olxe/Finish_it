#pragma once

#include "../object.h"
#include "../../Playable/heroes.h"

class PressurePlate: public Object
{
public:
	PressurePlate(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize);
	~PressurePlate();

	void CheckSensorCollision(PhysicalEntity* pOther) override;
	void CheckEndSensorContact(PhysicalEntity* pOther) override;
	void t();
protected:
	void OnAnimationFinished(std::string name) override;

};