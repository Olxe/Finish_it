#include "propertynode.h"

PropertyNode::PropertyNode()
    : m_name()
    , m_value()
    , m_type(PropertyType::TYPE_STRING)
{
}

PropertyNode::~PropertyNode()
{
}

void PropertyNode::Parse(const tinyxml2::XMLNode* node)
{    
    const tinyxml2::XMLElement* eProperty = node->ToElement();

    const char* name = eProperty->Attribute("name");
    const char* value = eProperty->Attribute("value");
    const char* type = eProperty->Attribute("type");

    if(name) m_name = name;
    if(value) m_value = value;

    if(type){
        if(strcmp(type, "bool") == 0) m_type = PropertyType::TYPE_BOOL;
        if(strcmp(type, "color") == 0) m_type = PropertyType::TYPE_COLOR;
        if(strcmp(type, "float") == 0) m_type = PropertyType::TYPE_FLOAT;
        if(strcmp(type, "file") == 0) m_type = PropertyType::TYPE_FILE;
        if(strcmp(type, "int") == 0) m_type = PropertyType::TYPE_INT;
    }
}

bool PropertyNode::ToBool(bool defaultValue) const
{
    if(m_type == PropertyType::TYPE_BOOL) return m_value.compare("false");

    return defaultValue;
}

float PropertyNode::ToFloat(float defaultValue) const
{
    if(m_type == PropertyType::TYPE_FLOAT) return std::stof(m_value);

    return defaultValue;
}

int PropertyNode::ToInt(int defaultValue) const
{
    if(m_type == PropertyType::TYPE_INT) return std::stoi(m_value);

    return defaultValue;
}

std::string PropertyNode::ToString() const
{
    return m_value;
}