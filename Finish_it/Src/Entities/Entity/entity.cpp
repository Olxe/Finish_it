#include "entity.h"

Entity::Entity(int gid, std::string name, std::string type)
    : m_gid(gid)
    , m_name(name)
	, m_type(type)
{
}

Entity::~Entity()
{
}

void Entity::InitEntity(std::string texturePath, sf::Vector2f frameSize, sf::Vector2i posFrame, sf::Vector2f position, float rotation)
{
	this->SetTexture(texturePath, true);
	if (frameSize == sf::Vector2f(0.f, 0.f)) frameSize = this->GetSize();

	sf::Vector2f origin = sf::Vector2f(frameSize) / 2.0f;
	position += TransformOffsetPoint(sf::Vector2f(origin.x, -origin.y), rotation);

	
	this->setTextureRect(sf::IntRect(posFrame.x * (int)frameSize.x, posFrame.y * (int)frameSize.y, (int)frameSize.x, (int)frameSize.y));
	this->setOrigin(origin);
	this->setPosition(position);
	this->setRotation(rotation);
}

int Entity::GetGid() const
{
	//probelem display(m_gid);
	return m_gid;
}

float Entity::EarnLife(const float& amount)
{
	return AddLife(amount);
}

void Entity::OnDammageTaken(const float& amount)
{
	RemoveLife(amount);
}

void Entity::KillEntity()
{
	SetLife(0.f);
}

