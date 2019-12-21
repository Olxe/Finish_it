#ifndef __POLYLINE__
#define __POLYLINE__

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string.h>

#include "../tinyxml2.h"
#include "point.h"

class Polyline
{
public:
	Polyline(sf::Vector2f position);
	~Polyline();

	void Parse(const tinyxml2::XMLNode* node);

	sf::Vector2f GetPosition() const { return m_position; }
	const std::vector< Point >& GetPoints() const { return m_points; }

private:
	std::vector< Point > m_points;
	sf::Vector2f m_position;

};

#endif
