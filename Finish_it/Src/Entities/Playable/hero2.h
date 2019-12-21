#pragma once

#include "heroes.h"

class Hero2: public Heroes
{
public:
	Hero2(const ObjectNode* obj, const TileNode* tile, std::string texturePath, sf::Vector2f frameSize, Direction direction);
	virtual ~Hero2();
};