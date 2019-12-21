#pragma once

#include "../object.h"
#include "../../Playable/heroes.h"

class PikeTrap: public Object
{
public:
	PikeTrap(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize);
	~PikeTrap();

	void OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime) override;

protected:
	void OnAnimationFinished(std::string name) override;

private:
	float m_timeTick;
	float m_currentTime;

};