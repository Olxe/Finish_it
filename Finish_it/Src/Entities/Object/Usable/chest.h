#pragma once

#include "../object.h"

enum ChestType
{
	GOLDEN_CHEST,
	ITEM_CHEST
};

class Chest: public Object
{
public:
	Chest(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, StateObject state, ChestType type);
	~Chest();

protected:
	void OnInteract() override;
	void OnAnimationFinished(std::string name) override;

private:
	ChestType m_type;
	bool isEmpty;

};
