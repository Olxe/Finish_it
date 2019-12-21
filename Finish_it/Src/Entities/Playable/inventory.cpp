#include "inventory.h"

Inventory::Inventory()
{
	while (!m_items.empty()) {
		delete m_items.back();
		m_items.pop_back();
	}
}

Inventory::~Inventory()
{
}

void Inventory::AddItem(ItemType type)
{
	m_items.push_back(new Item(type));
	std::cout << "New item -> " << type << std::endl;
}

bool Inventory::RemoveItem(ItemType type)
{
	for (auto it = m_items.begin(); it != m_items.end(); ++it) {
		if ((*it)->Type() == type) {
			delete* it;
			*it = nullptr;
			it = m_items.erase(it);
			std::cout << "Item removed -> " << type << std::endl;
			return true;
		}
	}

	return false;
}

int Inventory::HaveItem(ItemType type)
{
	int amount = 0;

	for (auto item : m_items) {
		if (item->Type() == type) amount++;
	}
	return amount;
}
