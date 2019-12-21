#pragma once

#include <SFML/Graphics.hpp>

#include "../../Tools/utility.h"
#include "assetmanager.h"

class CSprite: public sf::Sprite
{
public:
	CSprite();
	virtual ~CSprite();

	sf::Vector2f GetSize() const { return static_cast<sf::Vector2f>(this->getTexture()->getSize()); }
	virtual void Draw(sf::RenderWindow& window);

protected:
	void SetTexture(std::string path, bool isSmooth = false);
	sf::Vector2f TransformOffsetPoint(sf::Vector2f offset, float rotation);

private:
	sf::Texture* m_texture;
};