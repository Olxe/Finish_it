#pragma once

#include "../Physic/physicalbody.h"

class PhysicalShape: public PhysicalBody
{
public:
	PhysicalShape(const ObjectNode* obj, b2BodyType bodyType = b2BodyType::b2_staticBody, bool isFixedRotation = true);
	~PhysicalShape();

	const std::string& Name() const { return m_name; }
	const sf::Vector2f& Pos() const { return m_pos; }
	const sf::Vector2f& Size() const { return m_size; }

private:
	std::string m_name;
	sf::Vector2f m_pos;
	sf::Vector2f m_size;

};