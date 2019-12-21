#include "key.h"

Key::Key(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, ItemType type)
	: Object(obj, tile, texturePath)
	, m_type(type)
{
}

Key::~Key()
{
}

void Key::CheckSensorCollision(PhysicalEntity* pOther)
{
	if(GetIsAlive()){
		if (Heroes * hero = static_cast<Heroes*>(pOther)) {
			if (hero->IsMainHero) {
				hero->AddItem(m_type);
				this->SetIsAlive(false);
			}
		}
	}
}

void Key::Draw(sf::RenderWindow& window)
{
	if (GetIsAlive()) {
		window.draw(*this);
	}
}
