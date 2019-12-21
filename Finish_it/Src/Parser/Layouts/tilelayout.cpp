#include "tilelayout.h"

TileLayout::TileLayout(sf::Vector2i mapSize, sf::Vector2i tileSize)
	: m_mapSize(mapSize)
	, m_tileSize(tileSize)
{
}

TileLayout::~TileLayout()
{
    clearVector(m_tilemaps);
}

bool TileLayout::LoadLayer(const LayerNode* layer, const std::vector< TilesetNode* >& tilesets)
{
	clearVector(m_tilemaps);
    if(!layer){
        display("Error layer -> tilelayout");
        return false;
    }
    
    const DataNode* data = layer->GetData();
	if (!data) {
		display("Error data -> tilelayout");
		return false;
	}

    std::vector< const TileNode* > saveTile;

    for(auto gid : data->GetTilesGid()){
        for(auto tileset : tilesets){
            const TileNode* tile = tileset->GetTilesByGid(gid);
            if(tile){
                bool isTextureExist = false;
                std::string texturePath = tileset->GetDirectory() + tile->GetImageSource();

                for(auto tilemap : m_tilemaps){
                    if(tilemap->GetTexturePath() == texturePath) isTextureExist = true;
                }

                if(!isTextureExist){
                    m_tilemaps.push_back(new Tilemap(tileset->GetDirectory(), tile->GetImageSource(), m_mapSize, m_tileSize));
                }
                break;
            }
        }
    }

    for(auto tilemap : m_tilemaps){
        tilemap->Load(data, tilesets);
    }

	return true;
}

void TileLayout::Draw(sf::RenderWindow& window)
{
    for(auto tilemap : m_tilemaps){
		tilemap->OnDraw(window);
    }
}