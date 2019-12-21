#include "tilesetnode.h"

TilesetNode::TilesetNode()
    : m_firstgid(0)
    , m_directory()
    , m_source()
    , m_name()
    , m_tilewidth(0)
    , m_tileheight(0)
    , m_tilecount(0)
    , m_properties(nullptr)
    , m_image(nullptr)
    , m_tiles()
{
}

TilesetNode::~TilesetNode()
{
    clearPtr(m_properties);
    clearPtr(m_image);
    clearVector(m_tiles);
}

void TilesetNode::Parse(int firstgid, const std::string& directory, const std::string& source)
{
    m_firstgid = firstgid;
    m_directory = directory;
    m_source = source;

    tinyxml2::XMLDocument document;
	tinyxml2::XMLError result = document.LoadFile( (m_directory + m_source).c_str() );
    if( result != tinyxml2::XML_SUCCESS ){
        std::cout << "Error loading : " + m_source << std::endl;
        return;
    } 

    const tinyxml2::XMLElement* eTileset = document.FirstChildElement("tileset");
    
    const char* name = eTileset->Attribute("name");
    if(name) m_name = name;
    m_tilewidth = eTileset->IntAttribute("tilewidth");
    m_tileheight = eTileset->IntAttribute("tileheight");
    m_tilecount = eTileset->IntAttribute("tilecount");

    const tinyxml2::XMLElement* eProperties = eTileset->FirstChildElement("properties");
    if(eProperties){
        clearPtr(m_properties);
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);
    }

    const tinyxml2::XMLElement* eImage = eTileset->FirstChildElement("image");
    if(eImage){
        clearPtr(m_image);
        m_image = new ImageNode();
        m_image->Parse(eImage);
        parseTilesetImage();

        for(const tinyxml2::XMLElement* eTile = eTileset->FirstChildElement("tile"); eTile != nullptr; eTile = eTile->NextSiblingElement("tile"))
        {
            int id = eTile->IntAttribute("id");
            for(auto it : m_tiles){
                if(it->GetId() == id){
                    it->Parse(eTile, m_firstgid);
                }
            }
        }
    }
    else{
        clearVector(m_tiles);
        for(const tinyxml2::XMLElement* eTile = eTileset->FirstChildElement("tile"); eTile != nullptr; eTile = eTile->NextSiblingElement("tile"))
        {
            TileNode* tile = new TileNode();
            tile->Parse(eTile, m_firstgid);
            m_tiles.push_back(tile);
        }
    }
}

const PropertiesNode* TilesetNode::GetProperties() const
{
    return m_properties;
}

const TileNode* TilesetNode::GetTilesByGid(int gid) const
{
    for(auto it : m_tiles){
        if(it->GetGid() == gid){
            return it;
        }
    }
    return nullptr;
}

void TilesetNode::parseTilesetImage()
{
    clearVector(m_tiles);
	int id = 0;
	int columns = static_cast<int>(m_image->GetWidth() / m_tilewidth);
	int rows = static_cast<int>(m_image->GetHeight() / m_tileheight);

	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){		
            TileNode* tile = new TileNode(id, m_firstgid, j, i, m_image->GetSource());
            m_tiles.push_back(tile);

            id++;
		}
	}
}