#include "layernode.h"

LayerNode::LayerNode(int positionFile)
    : m_id(0)
	, m_positionFile(positionFile)
    , m_name()
    , m_width(0)
    , m_height(0)
    , m_properties(nullptr)
    , m_data(nullptr)
{
}

LayerNode::~LayerNode()
{
    clearPtr(m_properties);
    clearPtr(m_data);
}

void LayerNode::Parse(const tinyxml2::XMLNode* node)
{
    const tinyxml2::XMLElement* eLayer = node->ToElement();
    m_id = eLayer->IntAttribute("id");
    const char* name = eLayer->Attribute("name");
    if(name) m_name = name;
    m_width = eLayer->IntAttribute("width");
    m_height = eLayer->IntAttribute("height");
        
    const tinyxml2::XMLElement* eProperties = eLayer->FirstChildElement("properties");
    if(eProperties){
        clearPtr(m_properties);
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);
    }

    const tinyxml2::XMLElement* eData = eLayer->FirstChildElement("data");
    if(eData){
        clearPtr(m_data);
        m_data = new DataNode();
        m_data->Parse(eData);
    }
}