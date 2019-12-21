#include "objectlayout.h"

ObjectLayout::ObjectLayout()
{
}

ObjectLayout::~ObjectLayout()
{
	m_entities.clear();
	clearVector(m_shapes);
}

void ObjectLayout::Load(const ObjectGroupNode* objGrp, const std::vector< TileNode* >& tiles, const std::string& directory)
{
	m_entities.clear();
	clearVector(m_shapes);

	for (auto it : objGrp->GetObjects()) {
		const TileNode* tile = nullptr;

		for (auto t : tiles) {
			if (it->GetGid() == t->GetGid()) {
				tile = t;
			}
		}

		if (!tile) {
			m_shapes.push_back(new PhysicalShape(it, b2BodyType::b2_staticBody, true));//if no collision with camera -> death -> camera physical body?
		}
		else
		{
			std::string type = tile->GetType();

			if (type == "HERO1") m_entities.push_back(std::shared_ptr<Hero1>(new Hero1(it, tile, "Res/Textures/Characters/Heroes/Hero_1/hero1.png", sf::Vector2f(163, 107), Direction::DOWN)));
			else if (type == "HERO2") m_entities.push_back(std::shared_ptr<Hero2>(new Hero2(it, tile, "Res/Textures/Characters/Heroes/Hero_2/hero2.png", sf::Vector2f(117, 78), Direction::DOWN)));
			else if (type == "TORCH") m_entities.push_back(std::shared_ptr<Torch>(new Torch(it, tile, "Res/Textures/Lightings/torch.png", sf::Vector2f(69, 62))));
			else if (type == "WINDOW_TORCH") m_entities.push_back(std::shared_ptr<Torch>(new Torch(it, tile, "Res/Textures/Lightings/windowTorch.png", sf::Vector2f(40, 72))));
			else if (type == "STAIR_UP") m_entities.push_back(std::shared_ptr<Stair>(new Stair(it, tile, "Res/Textures/stair_up.png", StairType::STAIR_UP)));
			else if (type == "STAIR_DOWN") m_entities.push_back(std::shared_ptr<Stair>(new Stair(it, tile, "Res/Textures/stair_down.png", StairType::STAIR_DOWN)));
			else if (type == "LEVER") m_entities.push_back(std::shared_ptr<Lever>(new Lever(it, tile, "Res/Textures/FloorButtons/lever.png", sf::Vector2f(104, 73), StateObject::OFF)));
			else if (type == "IRON_DOOR") m_entities.push_back(std::shared_ptr<IronDoor>(new IronDoor(it, tile, "Res/Textures/Doors/ironDoor.png", sf::Vector2f(64, 135), StateObject::OFF)));
			else if (type == "GOLDEN_KEY") m_entities.push_back(std::shared_ptr<Key>(new Key(it, tile, "Res/Textures/Objects/Collectable/golden_key.png", ItemType::GOLDEN_KEY)));
			else if (type == "IRON_KEY") m_entities.push_back(std::shared_ptr<Key>(new Key(it, tile, "Res/Textures/Objects/Collectable/iron_key.png", ItemType::IRON_KEY)));
			else if (type == "WOOD_DOOR") m_entities.push_back(std::shared_ptr<WoodDoor>(new WoodDoor(it, tile, "Res/Textures/Doors/woodDoor.png", sf::Vector2f(64, 168), StateObject::OFF, DoorType::SIMPLE_DOOR)));
			else if (type == "DOUBLE_WOOD_DOOR") m_entities.push_back(std::shared_ptr<WoodDoor>(new WoodDoor(it, tile, "Res/Textures/Doors/doubleWoodDoor.png", sf::Vector2f(128, 167), StateObject::OFF, DoorType::DOUBLE_DOOR)));
			else if (type == "GOLDEN_CHEST") m_entities.push_back(std::shared_ptr<Chest>(new Chest(it, tile, "Res/Textures/Chests/goldenChest.png", sf::Vector2f(76, 73), StateObject::OFF, ChestType::GOLDEN_CHEST)));
			else if (type == "ITEM_CHEST") m_entities.push_back(std::shared_ptr<Chest>(new Chest(it, tile, "Res/Textures/Chests/itemChest.png", sf::Vector2f(76, 73), StateObject::OFF, ChestType::ITEM_CHEST)));
			else if (type == "PIKE_TRAP") m_entities.push_back(std::shared_ptr<PikeTrap>(new PikeTrap(it, tile, "Res/Textures/FloorButtons/pikeTrap.png", sf::Vector2f(64, 66))));
			else if (type == "PRESSURE_PLATE") m_entities.push_back(std::shared_ptr<PressurePlate>(new PressurePlate(it, tile, "Res/Textures/FloorButtons/pressurePlate.png", sf::Vector2f(64, 64))));
			else m_entities.push_back(std::shared_ptr<Object>(new Object(it, tile, directory + tile->GetImageSource(), it->GetSize())));
		}
	}
}

void ObjectLayout::Update(const sf::Vector2f& mousePosition, const sf::Vector2f& positionPlayer, const float& deltaTime)
{
	for (auto it : m_entities) {
		it->OnUpdate(mousePosition, deltaTime);
	}

	/*for (auto it = m_entities.begin(); it != m_entities.end();)
	{
		if (!(*it)->GetIsAlive()) {
			it = m_entities.erase(it);
		}
		else {
			(*it)->OnUpdate(mousePosition, deltaTime);
			++it;
		}
	}*/
}

void ObjectLayout::Draw(sf::RenderWindow& window, const sf::Vector2f& positionPlayer)
{
	for (auto it : m_entities) {
		if (fabs(it->getPosition().x - positionPlayer.x) < Settings::GetWindowSize().x &&
			fabs(it->getPosition().y - positionPlayer.y) < Settings::GetWindowSize().y)
		{
			it->Draw(window);
		}
	}
}

std::shared_ptr<Heroes> ObjectLayout::GetPtrOnHero(const std::string& typeHero)
{
	for (auto entity : m_entities) {
		if (typeHero == entity->Type() && !entity->Type().empty()) {
			if (std::shared_ptr<Heroes> hero = std::static_pointer_cast<Heroes>(entity)) {
				hero->IsMainHero = true;
				return hero;
			}
		}
	}

	return nullptr;
}
