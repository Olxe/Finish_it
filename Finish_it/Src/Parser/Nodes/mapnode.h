#ifndef __MAPNODE__
#define __MAPNODE__

#include "tilesetnode.h"
#include "objectgroupnode.h"
#include "layernode.h"

class MapNode
{
public:
    MapNode();
    ~MapNode();

    bool Parse(const std::string& directory, const std::string& fileTMXname);

    const std::vector< TilesetNode* >& GetTilesets() const { return m_tilesets; }
    const std::vector< ObjectGroupNode* >& GetObjectGroups() const { return m_objectGroups; }
    const std::vector< LayerNode* >& GetLayers() const { return m_layers; }
    const std::vector< TileNode* >& GetAllTiles() const { return m_allTiles; }

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    int GetTilewidth() const { return m_tilewidth; }
    int GetTileheight() const { return m_tileheight; }
    bool GetIsInfinite() const { return isInfinite; }
    std::string GetDirectory() const { return m_directory; }

private:
    void parseAttributes(const tinyxml2::XMLElement* eMap);
    void parseProperties(const tinyxml2::XMLElement* eMap);
    void parseTilesets(const tinyxml2::XMLElement* eMap);
    void parseObjectGroup(const tinyxml2::XMLElement* eObjGrp);
    void parseLayer(const tinyxml2::XMLElement* eLayer);

    void parseAllTiles();

private:
    int m_width;
    int m_height;
    int m_tilewidth;
    int m_tileheight;
    bool isInfinite;
    std::string m_directory;

    PropertiesNode* m_properties;
    std::vector< TilesetNode* > m_tilesets;
    std::vector< ObjectGroupNode* > m_objectGroups;
    std::vector< LayerNode* > m_layers;
    std::vector< TileNode* > m_allTiles;
};

#endif