#pragma once

#include "../object.h"

class Lever: public Object
{
public:
	Lever(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state);
	~Lever();

protected:
	void OnInteract() override;
	void OnAnimationFinished(std::string name) override;

};