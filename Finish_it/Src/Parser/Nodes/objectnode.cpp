#include "objectnode.h"

ObjectNode::ObjectNode()
    : m_id(0)
    , m_name()
    , m_type()
    , m_gid(0)
    , m_x(0.f)
    , m_y(0.f)
    , m_width(0.f)
    , m_height(0.f)
    , m_rotation(0.f)
    , isVisible(true)
    , m_point(nullptr)
    , m_polygone(nullptr)
	, m_polyline(nullptr)
    , m_ellipse(nullptr)
    , m_shape(nullptr)
    , m_properties(nullptr)
{
}

ObjectNode::~ObjectNode()
{
	clearPtr(m_properties);
	clearPtr(m_point);
	clearPtr(m_shape);
	clearPtr(m_polygone);
	clearPtr(m_polyline);
	clearPtr(m_ellipse);
}

void ObjectNode::Parse(const tinyxml2::XMLNode* node)
{
	clearPtr(m_properties);
	clearPtr(m_point);
	clearPtr(m_shape);
	clearPtr(m_polygone);
	clearPtr(m_polyline);
	clearPtr(m_ellipse);

    const tinyxml2::XMLElement* eObject = node->ToElement();

    m_id = eObject->IntAttribute("id");
    m_gid = eObject->IntAttribute("gid");
    m_x = eObject->FloatAttribute("x");
    m_y = eObject->FloatAttribute("y");
    m_width = eObject->FloatAttribute("width");
    m_height = eObject->FloatAttribute("height");
    m_rotation = eObject->FloatAttribute("rotation");
    isVisible = eObject->BoolAttribute("visible");
    
    const char* name = eObject->Attribute("name");
    const char* type = eObject->Attribute("type");
    if(name) m_name = name;
    if(type) m_type = type;

    const tinyxml2::XMLElement* eProperties = eObject->FirstChildElement("properties");
    if(eProperties){
        m_properties = new PropertiesNode();
        m_properties->Parse(eProperties);     
    }

    const tinyxml2::XMLElement* eEllipse = eObject->FirstChildElement("ellipse");
    if(eEllipse){
        m_ellipse = new Ellipse(m_x, m_y, m_width, m_height);
        return;
    }

    const tinyxml2::XMLElement* ePoint = eObject->FirstChildElement("point");
    if(ePoint){
        m_point = new Point(m_x, m_y);
        return;
    }

    const tinyxml2::XMLElement* ePolygon = eObject->FirstChildElement("polygon");
    if(ePolygon){
        m_polygone = new Polygone(sf::Vector2f(m_x, m_y));
        m_polygone->Parse(ePolygon);
        return;
    }

    const tinyxml2::XMLElement* ePolyline = eObject->FirstChildElement("polyline");
    if(ePolyline){
		m_polyline = new Polyline(sf::Vector2f(m_x, m_y));
		m_polyline->Parse(ePolyline);
        return;
    }

    if(m_gid == 0){
        m_shape = new Shape(sf::Vector2f(m_x, m_y) , sf::Vector2f(m_width, m_height), m_rotation);
        return;
    }
}

const PropertiesNode* ObjectNode::GetProperties() const
{
    return m_properties;
}