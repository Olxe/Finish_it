#ifndef __TILEMAP__
#define __TILEMAP__

#include "../Entity/cvertexarray.h"
#include "../Object/physicaltile.h"
#include "../../Parser/Nodes/tilesetnode.h"
#include "../../Parser/Nodes/datanode.h"

class Tilemap: public CVertexArray
{
public:
    Tilemap(const std::string& directory, const std::string& imagePath, const sf::Vector2i& sizeTilemap, const sf::Vector2i& sizeTile);
    ~Tilemap();

	void OnDraw(sf::RenderWindow& window);

    void Load(const DataNode* data, const std::vector< TilesetNode* >& tilesets);
    std::string GetTexturePath() const { return m_directory + m_imagePath; }

private:
	void setup();

private:
    std::string m_directory;
    std::string m_imagePath;
    sf::Vector2i m_mapSize;
    sf::Vector2f m_tileSize;
    std::vector< const TileNode* > m_tiles;
	std::vector< PhysicalTile* > m_bodies;
    
};

#endif