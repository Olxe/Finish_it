#include "propertiesnode.h"

PropertiesNode::PropertiesNode()
{
}

PropertiesNode::~PropertiesNode()
{
    clearVector(m_properties);
}

void PropertiesNode::Parse(const tinyxml2::XMLNode* node)
{
	clearVector(m_properties);
    for(const tinyxml2::XMLElement* eProperty = node->FirstChildElement("property"); eProperty != nullptr; eProperty = eProperty->NextSiblingElement("property"))
    {
        PropertyNode* property = new PropertyNode();
        property->Parse(eProperty);

        m_properties.push_back(property);
    }
}

PropertyNode PropertiesNode::GetProperty(const std::string& name) const
{
    for(auto property : m_properties){
        if(property->GetName() == name){
            return *property;
        }
    }

    return PropertyNode(); 
}