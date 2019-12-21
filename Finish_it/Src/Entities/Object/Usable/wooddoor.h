#pragma once

#include "../object.h"

enum DoorType
{
	SIMPLE_DOOR,
	DOUBLE_DOOR
};

class WoodDoor: public Object
{
public:
	WoodDoor(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state, DoorType type);
	virtual ~WoodDoor();

protected:
	void OnAnimationFinished(std::string name) override;
	void OnInteract() override;
	void OnAction() override;

private:
	DoorType m_type;

};