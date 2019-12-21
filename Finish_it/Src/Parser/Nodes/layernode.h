#ifndef __LAYERNODE__
#define __LAYERNODE__

#include "datanode.h"
#include "propertiesnode.h"

class LayerNode
{
public:
    LayerNode(int positionFile);
    ~LayerNode();

    void Parse(const tinyxml2::XMLNode* node);

    int GetId() const { return m_id; }
	int GetPositionFile() const { return m_positionFile;  }
    std::string GetName() const { return m_name; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    const DataNode* GetData() const { return m_data; } 

private:
    int m_id;
	int m_positionFile;
    std::string m_name;
    int m_width;
    int m_height;

    PropertiesNode* m_properties;
    DataNode* m_data;
};

#endif