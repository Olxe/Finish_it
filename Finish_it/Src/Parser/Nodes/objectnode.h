#ifndef __OBJECTNODE__
#define __OBJECTNODE__

#include "../Shapes/ellipse.h"
#include "../Shapes/polygone.h"
#include "../Shapes/polyline.h"

#include "propertiesnode.h"

class ObjectNode
{
public:
    ObjectNode();
    ~ObjectNode();

    void Parse(const tinyxml2::XMLNode* node);

    const PropertiesNode* GetProperties() const;
    int GetId() const { return m_id; };
    std::string GetName() const { return m_name; };
    std::string GetType() const { return m_type; };
    int GetGid() const { return m_gid; };
	sf::Vector2f GetPosition() const { return sf::Vector2f(m_x, m_y); }
	sf::Vector2f GetSize() const { return sf::Vector2f(m_width, m_height); }
    float GetRotation() const { return m_rotation; };
    bool GetIsVisible() const { return isVisible; };

    const Shape* GetShape() const { return m_shape; }
    const Polygone* GetPolygon() const { return m_polygone; }
	const Polyline* GetPolyline() const { return m_polyline; }
    const Point* GetPoint() const { return m_point; }
    const Ellipse* GetEllipse() const { return m_ellipse; }

private:
    int m_id;
    std::string m_name;
    std::string m_type;
    int m_gid;
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_rotation;
    bool isVisible;

    Point* m_point;
    Polygone* m_polygone;
	Polyline* m_polyline;
    Ellipse* m_ellipse;
    Shape* m_shape;//rectangle

    PropertiesNode* m_properties;
};

#endif