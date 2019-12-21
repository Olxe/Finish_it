#pragma once

#include <vector>
#include <iostream>

#include "Inventory/Item/item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void AddItem(ItemType type);
	bool RemoveItem(ItemType type);
	//return amount of item stocked
	int HaveItem(ItemType type);

private:
	std::vector<Item*> m_items;

};