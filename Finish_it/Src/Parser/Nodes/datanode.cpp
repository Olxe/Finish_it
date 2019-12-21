#include "datanode.h"

DataNode::DataNode()
    : m_encoding()
    , m_tilesGid()
{
}

DataNode::~DataNode()
{
}

void DataNode::Parse(const tinyxml2::XMLNode* node)
{
    const tinyxml2::XMLElement* eData = node->ToElement();
    const char* encoding = eData->Attribute("encoding");
    if(encoding) m_encoding = encoding;

    if(m_encoding == "csv"){
        const char* data = eData->GetText();
        if(data) parseCVS(data);
    }
}

void DataNode::parseCVS(const char* data)
{
	char* token = _strdup(data);
	char* nextToken = nullptr;

	token = strtok_s(token, ",", &nextToken);

	while (token) {
		m_tilesGid.push_back(atoi(token));
		token = strtok_s(NULL, ",", &nextToken);
	}
	free(token);

    /*char* token = _strdup(data);
    for(token = strtok(token, ","); token != NULL; token = strtok(NULL, ",")){
        m_tilesGid.push_back(atoi(token));
    }*/
}