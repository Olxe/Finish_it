#include "tilemap.h"

Tilemap::Tilemap(const std::string& directory, const std::string& imagePath, const sf::Vector2i& mapSize, const sf::Vector2i& tileSize)
    : m_directory(directory)
    , m_imagePath(imagePath)
    , m_mapSize(mapSize)
    , m_tileSize(static_cast<sf::Vector2f>(tileSize))
{
}

Tilemap::~Tilemap()
{
	clearVector(m_bodies);
}

void Tilemap::OnDraw(sf::RenderWindow& window)
{
	window.draw(*this);
	for (auto body : m_bodies) {
		window.draw(*body);
	}
}

void Tilemap::Load(const DataNode* data, const std::vector< TilesetNode* >& tilesets)
{
    for(auto gid : data->GetTilesGid()){
        bool tileFind = false;
        for(auto tileset : tilesets){
            const TileNode* tile = tileset->GetTilesByGid(gid);
            if(tile && tile->GetImageSource() == m_imagePath){
                tileFind = true;
                m_tiles.push_back(tile);
                break;
            }
        }
        if(!tileFind) m_tiles.push_back(nullptr);
    }

	LoadVertexArray(this->GetTexturePath(), m_mapSize);
	setup();
}

void Tilemap::setup()
{
	clearVector(m_bodies);
	for (int i = 0; i < m_mapSize.x; ++i)
	{
		for (int j = 0; j < m_mapSize.y; ++j)
		{
			if (i + j * m_mapSize.x >= (int)m_tiles.size()) return;

			const TileNode* tile = m_tiles[i + j * m_mapSize.x];
			if (tile != nullptr)
			{
				if (tile->GetObjectGroup() && false)
				{
					PhysicalTile* body = new PhysicalTile(tile, this->GetTexturePath(), (sf::Vector2i)m_tileSize, sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y));
					m_bodies.push_back(body);
				}
				else
				{
					//Pos in tileset
					int column = tile->GetCoordTextureX();
					int row = tile->GetCoordTextureY();

					//Margin of the m_texture trim (avoid bug display)
					float texMargin = 0.0f;

					//Ptr to quad (future tile)
					sf::Vertex* quad = GetVertexTo((i + j * m_mapSize.x) * 4);
					//Pos of the tile
					quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * m_tileSize.x, j * m_tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
					quad[3].position = sf::Vector2f(i * m_tileSize.x, (j + 1) * m_tileSize.y);

					//Tile coordinated in the tileset m_texture
					quad[0].texCoords = sf::Vector2f(column * m_tileSize.x + texMargin, row * m_tileSize.y + texMargin);
					quad[1].texCoords = sf::Vector2f((column + 1) * m_tileSize.x - texMargin, row * m_tileSize.y + texMargin);
					quad[2].texCoords = sf::Vector2f((column + 1) * m_tileSize.x - texMargin, (row + 1) * m_tileSize.y - texMargin);
					quad[3].texCoords = sf::Vector2f(column * m_tileSize.x + texMargin, (row + 1) * m_tileSize.y - texMargin);
				}
			}
		}
	}
}