#ifndef __TILELAYOUT__
#define __TILELAYOUT__

#include "layout.h"
#include "../../Entities/Tilemap/tilemap.h"
#include "../Nodes/mapnode.h"


class TileLayout: public Layout
{
public:
    TileLayout(sf::Vector2i mapSize, sf::Vector2i tileSize);
    ~TileLayout();

    bool LoadLayer(const LayerNode* layer, const std::vector< TilesetNode* >& tilesets);
    void Draw(sf::RenderWindow& window);

private:
    std::vector< Tilemap* > m_tilemaps;
	sf::Vector2i m_mapSize;
	sf::Vector2i m_tileSize;
};

#endif