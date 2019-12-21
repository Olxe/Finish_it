#include "tilenode.h"

TileNode::TileNode()
    : m_id(0)
    , m_gid(0)
    , m_coordTextureX(0)
    , m_coordTextureY(0)
    , m_imageSource()
    , m_properties(nullptr)
    , m_objectGroup(nullptr)
    , m_image(nullptr)
{
}

TileNode::TileNode(int id, int firstgid, int coordTextureX, int coordTextureY, const std::string& imageSource)
    : m_id(id)
    , m_gid(id + firstgid)
    , m_coordTextureX(coordTextureX)
    , m_coordTextureY(coordTextureY)
    , m_imageSource(imageSource)
    , m_properties(nullptr)
    , m_objectGroup(nullptr)
    , m_image(nullptr)
{
}

TileNode::~TileNode()
{
	clearPtr(m_properties);
	clearPtr(m_objectGroup);
	clearPtr(m_image);
}

void TileNode::Parse(const tinyxml2::XMLNode* node, int firstgid)
{
    const tinyxml2::XMLElement* eTile = node->ToElement();
    m_id = eTile->IntAttribute("id");
    m_gid = m_id + firstgid;
	const char* type = eTile->Attribute("type");
	if (type) m_type = type;

    const tinyxml2::XMLElement* eProperties = eTile->FirstChildElement("properties");
    if(eProperties){
        clearPtr(m_properties);
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);
    }

    const tinyxml2::XMLElement* eObjectGroup = eTile->FirstChildElement("objectgroup");
    if(eObjectGroup){
        clearPtr(m_objectGroup);
        m_objectGroup = new ObjectGroupNode();
        m_objectGroup->Parse(eObjectGroup);
    }

    const tinyxml2::XMLElement* eImage = eTile->FirstChildElement("image");
    if(eImage){
        clearPtr(m_image);
        m_image = new ImageNode();
        m_image->Parse(eImage);
    }
}

std::string TileNode::GetImageSource() const
{
    if(m_image) return m_image->GetSource();
    return m_imageSource;
}