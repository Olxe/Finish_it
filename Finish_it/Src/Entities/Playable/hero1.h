#pragma once

#include "heroes.h"

class Hero1 : public Heroes
{
public:
	Hero1(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction);
	virtual ~Hero1();

};