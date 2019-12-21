#pragma once

#include "../object.h"

class Torch: public Object
{
public:
	Torch(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize);
	~Torch();

protected:
	void OnInteract() override;

};