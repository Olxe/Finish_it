#ifndef __TILESETNODE__
#define __TILESETNODE__

#include "tilenode.h"
#include "propertiesnode.h"

class TilesetNode
{
public:
    TilesetNode();
    ~TilesetNode();

    void Parse(int firstgid, const std::string& directory, const std::string& source);

    const PropertiesNode* GetProperties() const;
    const ImageNode* GetImage() const { return m_image; }
    const TileNode* GetTilesByGid(int gid) const;
    const std::vector< TileNode* >& GetTiles() const { return m_tiles; }

    int GetFirstgid() const { return m_firstgid; }
    std::string GetDirectory() const { return m_directory; }
    std::string GetSource() const { return m_source; }
    std::string GetName() const { return m_name; }
    int GetTilewidth() const { return m_tilewidth; }
    int GetTileheight() const { return m_tileheight; }
    int GetTilecount() const { return m_tilecount; }

private:
    void parseTilesetImage();

private:
    int m_firstgid;
    std::string m_directory;
    std::string m_source;
    std::string m_name;
    int m_tilewidth;
    int m_tileheight;
    int m_tilecount;

    PropertiesNode* m_properties;
    ImageNode* m_image;
    std::vector< TileNode* > m_tiles;
};

#endif