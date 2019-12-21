#include "mapnode.h"

MapNode::MapNode()
    : m_width(0)
    , m_height(0)
    , m_tilewidth(0)
    , m_tileheight(0)
    , isInfinite(false)
    , m_directory()
    , m_properties(nullptr)
    , m_tilesets()
    , m_objectGroups()
    , m_layers()
{
}

MapNode::~MapNode()
{
    clearPtr(m_properties);
    clearVector(m_tilesets);
    clearVector(m_objectGroups);
    clearVector(m_layers);
	//clearVector(m_allTiles);
}

bool MapNode::Parse(const std::string& directory, const std::string& fileTMXname)
{
    m_directory = directory;
    tinyxml2::XMLDocument document;
	tinyxml2::XMLError result = document.LoadFile( (directory + fileTMXname).c_str() );
    if( result != tinyxml2::XML_SUCCESS ){
        std::cout << "Error loading : " + directory + fileTMXname << std::endl;
        return false;
    } 

    tinyxml2::XMLElement* eMap = document.FirstChildElement("map");

	clearVector(m_objectGroups);
	clearVector(m_layers);
	for (const tinyxml2::XMLElement* eChild = eMap->FirstChildElement(); eChild != nullptr; eChild = eChild->NextSiblingElement())
	{
		parseObjectGroup(eChild);
		parseLayer(eChild);
	}
	parseAttributes(eMap);
	parseTilesets(eMap);

    parseAllTiles();

	return true;
}

void MapNode::parseAttributes(const tinyxml2::XMLElement* eMap)
{
    m_width = eMap->IntAttribute("width");
    m_height = eMap->IntAttribute("height");
    m_tilewidth = eMap->IntAttribute("tilewidth");
    m_tileheight = eMap->IntAttribute("tileheight");
    isInfinite = eMap->BoolAttribute("infinite");
}

void MapNode::parseProperties(const tinyxml2::XMLElement* eMap)
{
    const tinyxml2::XMLElement* eProperties = eMap->FirstChildElement("properties");
    if(eProperties){
        clearPtr(m_properties);
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);     
    }
}

void MapNode::parseTilesets(const tinyxml2::XMLElement* eMap)
{
    clearVector(m_tilesets);
    for(const tinyxml2::XMLElement* eTileset = eMap->FirstChildElement("tileset"); eTileset != nullptr; eTileset = eTileset->NextSiblingElement("tileset"))
    {
        int firstgid = eTileset->IntAttribute("firstgid");
        const char* source = eTileset->Attribute("source");
        if(!source) return;

        TilesetNode* tileset = new TilesetNode();
        tileset->Parse(firstgid, m_directory, source);
        m_tilesets.push_back(tileset);
    }
}

void MapNode::parseObjectGroup(const tinyxml2::XMLElement* eObjGrp)
{
	if (strcmp(eObjGrp->Value(), "objectgroup") == 0) {
		ObjectGroupNode* objectGroup = new ObjectGroupNode(m_layers.size() + m_objectGroups.size());
		objectGroup->Parse(eObjGrp);
		m_objectGroups.push_back(objectGroup);
	}
}

void MapNode::parseLayer(const tinyxml2::XMLElement* eLayer)
{
	if (strcmp(eLayer->Value(), "layer") == 0) {
		LayerNode* layer = new LayerNode(m_layers.size() + m_objectGroups.size());
		layer->Parse(eLayer);
		m_layers.push_back(layer);
	}
}

void MapNode::parseAllTiles()
{
    m_allTiles.clear();
    for(auto tileset : m_tilesets){
        for(auto tile : tileset->GetTiles()){
            m_allTiles.push_back(tile);
        }
    }
}
