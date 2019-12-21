#ifndef __PROPERTYNODE__
#define __PROPERTYNODE__

#include "../tinyxml2.h"
#include <string>

#include "../../Tools/utility.h"

enum PropertyType
{
    TYPE_BOOL,
    TYPE_COLOR,
    TYPE_FLOAT,
    TYPE_FILE,
    TYPE_INT,
    TYPE_STRING
};

class PropertyNode
{
public:
    PropertyNode();
    ~PropertyNode();

    void Parse(const tinyxml2::XMLNode* node);

    std::string GetName() { return m_name; }

    bool ToBool(bool defaultValue = false) const;
    //std::string ToColor(std::string defaultValue);//later with color function
    float ToFloat(float defaultValue = 0.f) const;
    int ToInt(int defaultValue = 0) const;
    std::string ToString() const;

private:
    std::string m_name;
    std::string m_value;
    PropertyType m_type;

};

#endif