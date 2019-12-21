#include "imagenode.h"

ImageNode::ImageNode()
    : m_width(0)
    , m_height(0)
    , m_source()
{
}

ImageNode::~ImageNode()
{
}

void ImageNode::Parse(const tinyxml2::XMLNode* node)
{
    const tinyxml2::XMLElement* eImage = node->ToElement();
    if(!eImage){
        display("Error parsing image");
        return;
    } 

    m_width = eImage->IntAttribute("width");
    m_height = eImage->IntAttribute("height");
    const char* source = eImage->Attribute("source");
    if(source) m_source = source;
}