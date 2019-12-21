#include "loadmap.h"

LoadMap::LoadMap()
    : m_map(nullptr)
{
}

LoadMap::~LoadMap()
{
    clearPtr(m_map);
}

std::vector< Layout* > LoadMap::Load(const std::string& directory, const std::string& filename)
{
    std::vector< Layout* > layouts;
    m_map = new MapNode();
    m_map->Parse(directory, filename); 

	size_t numberLayer = m_map->GetLayers().size() + m_map->GetObjectGroups().size();

	for (size_t i = 0; i < numberLayer; i++) {
		for (auto layer : m_map->GetLayers()) {
			if (layer->GetPositionFile() == i) {
				TileLayout* tileLayout = new TileLayout(sf::Vector2i(m_map->GetWidth(), m_map->GetHeight()), sf::Vector2i(m_map->GetTilewidth(), m_map->GetTileheight()));
				tileLayout->LoadLayer(layer, m_map->GetTilesets());
				layouts.push_back(tileLayout);
			}
		}

		for (auto objGrp : m_map->GetObjectGroups()) {
			if (objGrp->GetPositionFile() == i) {
				ObjectLayout* objLayout = new ObjectLayout();
				objLayout->Load(objGrp, m_map->GetAllTiles(), m_map->GetDirectory());
				layouts.push_back(objLayout);
			}
		}
	}
	loadConnectionObject(layouts);
    clearPtr(m_map);

    return layouts;
}

void LoadMap::loadConnectionObject(std::vector<Layout*>& layouts)
{
	std::vector< std::shared_ptr<PhysicalEntity> > allEntities;

	for (auto layout : layouts) {
		if (ObjectLayout * obj = dynamic_cast<ObjectLayout*>(layout)) {
			for (auto it : obj->Entities()) {
				allEntities.push_back(it);
			}
		}
	}

	for (auto entity : allEntities)
	{
		if (!entity->Name().empty() && (entity->Type() == "LEVER" || entity->Type() == "PRESSURE_PLATE"))
		{
			for (auto entityToConnect : allEntities)
			{
				if (entity->Name() == entityToConnect->Name() && entity != entityToConnect) {
					std::shared_ptr<Object> actionner = std::static_pointer_cast<Object>(entity);
					std::shared_ptr<Object> actionnable = std::static_pointer_cast<Object>(entityToConnect);

					if (actionner && actionnable) {
						actionner->AddDependentObject(actionnable);
					}
				}
			}
		}
	}

	allEntities.clear();
}
