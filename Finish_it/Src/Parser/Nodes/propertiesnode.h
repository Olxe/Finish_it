#ifndef __PROPERTIESNODE__
#define __PROPERTIESNODE__

#include <vector>

#include "propertynode.h"

class PropertiesNode
{
public:
    PropertiesNode();
    ~PropertiesNode();

    void Parse(const tinyxml2::XMLNode* node);

    PropertyNode GetProperty(const std::string& name) const;

private:
    std::vector< PropertyNode* > m_properties;

};

#endif