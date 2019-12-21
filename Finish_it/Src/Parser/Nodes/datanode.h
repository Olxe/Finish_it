#ifndef __DATANODE__
#define __DATANODE__

#include "../tinyxml2.h"
#include <string>

#include "../../Tools/utility.h"

class DataNode
{
public:
    DataNode();
    ~DataNode();

    void Parse(const tinyxml2::XMLNode* node);

    std::string GetEncoding() const { return m_encoding; }
    const std::vector< int >& GetTilesGid() const { return m_tilesGid; }

private:
    void parseCVS(const char* data);

private:
    std::string m_encoding;
    std::vector< int > m_tilesGid;

};

#endif