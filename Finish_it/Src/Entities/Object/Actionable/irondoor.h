#pragma once

#include "../object.h"

class IronDoor: public Object
{
public:
	IronDoor(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state);
	~IronDoor();

	void OnAction() override;
	
};