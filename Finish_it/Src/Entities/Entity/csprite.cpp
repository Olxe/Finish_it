#include "csprite.h"

CSprite::CSprite()
	: m_texture(nullptr)
{
}

CSprite::~CSprite()
{
}

void CSprite::Draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

void CSprite::SetTexture(std::string path, bool isSmooth)
{
	m_texture = AssetManager::GetInstance()->GetTexture(path);
	m_texture->setSmooth(isSmooth);
	this->setTexture(*m_texture);
}

sf::Vector2f CSprite::TransformOffsetPoint(sf::Vector2f offset, float rotation)
{
	sf::Transform transform;
	transform.rotate(rotation);
	sf::Vector2f offsetTransformed = transform.transformPoint(offset);

	return offsetTransformed;
}