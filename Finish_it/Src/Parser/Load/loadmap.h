#ifndef __LOADMAP__
#define __LOADMAP__

#include "../Nodes/mapnode.h"
#include "../Layouts/tilelayout.h"
#include "../Layouts/objectlayout.h"

class LoadMap
{
public:
    LoadMap();
    ~LoadMap();

    std::vector< Layout* > Load(const std::string& directory, const std::string& filename);

private:
	void loadConnectionObject(std::vector< Layout* >& layouts);

private:
    MapNode* m_map;

};

#endif