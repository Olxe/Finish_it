#include "stair.h"

Stair::Stair(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, StairType type)
	: Object(obj, tile, texturePath)
	, m_type(type)
{
}

Stair::~Stair()
{
}

void Stair::OnInteract()
{
	if (m_type == StairType::STAIR_DOWN) Command::Instance()->SetCommand("NEXT_LEVEL");
	if (m_type == StairType::STAIR_UP) Command::Instance()->SetCommand("PREVIOUS_LEVEL");
}