#ifndef __OBJECTGROUPNODE__
#define __OBJECTGROUPNODE__

#include "objectnode.h"

class ObjectGroupNode
{
public:
    ObjectGroupNode(int positionFile = -1);
    ~ObjectGroupNode();

    void Parse(const tinyxml2::XMLNode* node);

    const std::vector< ObjectNode* >& GetObjects() const;
    const ObjectNode* GetObjectById(int id) const;

    int GetId() const { return m_id; }
	int GetPositionFile() const { return m_positionFile; }
    std::string GetName() const { return m_name; }

private:
    int m_id;
	int m_positionFile;
    std::string m_name;
    PropertiesNode* m_properties;
    std::vector< ObjectNode* > m_objects;

};

#endif