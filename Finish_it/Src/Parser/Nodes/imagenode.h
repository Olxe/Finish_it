#ifndef __IMAGENODE__
#define __IMAGENODE__

#include "../tinyxml2.h"
#include <string>

#include "../../Tools/utility.h"

class ImageNode
{
public:
    ImageNode();
    ~ImageNode();

    void Parse(const tinyxml2::XMLNode* node);

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    std::string GetSource() const { return m_source; }

private:
    int m_width;
    int m_height;
    std::string m_source;

};

#endif