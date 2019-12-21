#pragma once

#include "../object.h"
#include "../../../Game/Window/command.h"

enum StairType
{
	STAIR_UP,
	STAIR_DOWN
};

class Stair: public Object
{
public:
	Stair(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, StairType type);
	~Stair();

	void OnInteract() override;

private:
	StairType m_type;

};