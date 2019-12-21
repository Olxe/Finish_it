#include "debugphysic.h"

DebugPhysic::DebugPhysic()
{
}

DebugPhysic::~DebugPhysic()
{
}

void DebugPhysic::AddDebugShapeCircle(sf::Vector2f position, float radius, sf::Vector2f offset)
{
    m_offset = offset;
    sf::CircleShape shape;
    shape.setRadius(radius);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(position);
    shape.setFillColor(sf::Color(50, 50, 50 , 180));

    m_circles.push_back(shape);
}

void DebugPhysic::AddDebugShapeConvex(sf::Vector2f position, const std::vector< Point >& points)
{
    sf::ConvexShape shape;
    shape.setPointCount(points.size());

    for(size_t i = 0; i < points.size(); i++){
       shape.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
    }

    shape.setPosition(position);
    shape.setFillColor(sf::Color(50, 50, 50 , 180));

    m_convexes.push_back(shape);
}

void DebugPhysic::AddDebugShapeRectangle(sf::Vector2f position, sf::Vector2f size, sf::Vector2f offset, float rotation)
{
    m_offset = offset;
    sf::RectangleShape shape;
    shape.setSize(size);
    shape.setOrigin(size / 2.f);
    shape.setPosition(position + offset);
    shape.setRotation(rotation);
    shape.setFillColor(sf::Color(255, 255, 255, 255));

    m_rectangles.push_back(shape);
}

void DebugPhysic::UpdateDebugShape(const sf::Vector2f& , const float& )
{   
    /*for(auto& it : m_circles){
        it.setPosition(position + m_offset);
    }
    for(auto& it : m_rectangles){
        it.setPosition(position * 30.f);
        it.setRotation(rotation * 180.f / 3.14f);
    }
    for(auto& it : m_convexes){
        it.setPosition(position);
        it.setRotation(rotation);
    }*/
}

void DebugPhysic::DrawDebugShape(sf::RenderWindow& window)
{
    for(auto& it : m_circles){
        window.draw(it);
    }
    for(auto& it : m_rectangles){
        window.draw(it);
    }
    for(auto& it : m_convexes){
        window.draw(it);
    }
}