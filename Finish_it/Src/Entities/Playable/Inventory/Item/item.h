#pragma once

#include <string>

enum ItemType
{
	IRON_KEY,
	GOLDEN_KEY,
	GOLD
};

class Item
{
public:
	Item(ItemType type);
	~Item();

	ItemType Type() const { return m_type; }

private:
	ItemType m_type;

};