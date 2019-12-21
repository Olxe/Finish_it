#ifndef __TILENODE__
#define __TILENODE__

#include "propertiesnode.h"
#include "objectgroupnode.h"
#include "imagenode.h"
#include "../../Tools/utility.h"
class TileNode
{
public:
    TileNode(int id, int firstgid, int coordTextureX, int coordTextureY, const std::string& imageSource);
    TileNode();
    ~TileNode();

    void Parse(const tinyxml2::XMLNode* node, int firstgid);

    int GetId() const { return m_id; }
    int GetGid() const { return m_gid; }
    int GetCoordTextureX() const { return m_coordTextureX; }
    int GetCoordTextureY() const { return m_coordTextureY; }
    std::string GetImageSource() const;
	std::string GetType() const { return m_type; };

    const PropertiesNode* GetProperties() const { return m_properties; }
    const ObjectGroupNode* GetObjectGroup() const { return m_objectGroup; }
    const ImageNode* GetImage() const {  return m_image; }

private:
    int m_id;
    int m_gid;
    int m_coordTextureX;
    int m_coordTextureY;
    std::string m_imageSource;
	std::string m_type;

    PropertiesNode* m_properties;
    ObjectGroupNode* m_objectGroup;
    ImageNode* m_image;

};

#endif