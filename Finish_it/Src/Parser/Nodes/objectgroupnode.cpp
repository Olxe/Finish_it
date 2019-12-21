#include "objectgroupnode.h"

ObjectGroupNode::ObjectGroupNode(int positionFile)
    : m_id(0)
	, m_positionFile(positionFile)
    , m_name()
    , m_properties(nullptr)
    , m_objects()
{
}

ObjectGroupNode::~ObjectGroupNode()
{
    clearPtr(m_properties);
    clearVector(m_objects);
}

void ObjectGroupNode::Parse(const tinyxml2::XMLNode* node)
{   
    const tinyxml2::XMLElement* eObjectGroup = node->ToElement();
    m_id = eObjectGroup->IntAttribute("id");
    const char* name = eObjectGroup->Attribute("name");
    if(name) m_name = name;

    const tinyxml2::XMLElement* eProperties = node->FirstChildElement("properties");
    if(eProperties){
        clearPtr(m_properties);
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);
    }

    clearVector(m_objects);
    for(const tinyxml2::XMLElement* eObj = node->FirstChildElement("object"); eObj != nullptr; eObj = eObj->NextSiblingElement("object"))
    {
        ObjectNode* obj = new ObjectNode();
        obj->Parse(eObj);
        m_objects.push_back(obj);
    }
}

const ObjectNode* ObjectGroupNode::GetObjectById(int id) const
{
    for(auto it : m_objects){
        if(it->GetId() == id){
            return it;
        }
    }
    return nullptr;
}

const std::vector< ObjectNode* >& ObjectGroupNode::GetObjects() const
{
    return m_objects;
}