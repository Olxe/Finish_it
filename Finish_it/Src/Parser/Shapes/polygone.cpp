#include "polygone.h"

Polygone::Polygone(sf::Vector2f position)
    : m_points()
    , m_position(position)
{
}

Polygone::~Polygone()
{
}

void Polygone::Parse(const tinyxml2::XMLNode* node)
{
	char* token = _strdup(node->ToElement()->Attribute("points"));
	char* nextToken = nullptr;

	token = strtok_s(token, " ", &nextToken);

	while (token) {
		Point point;
		sscanf_s(token, "%f,%f", &point.x, &point.y);
		m_points.push_back(point);
		
		token = strtok_s(NULL, " ", &nextToken);
	}

	free(token);
}