#ifndef __DEBUGPHYSIC__
#define __DEBUGPHYSIC__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Parser/Shapes/point.h"
#include "../../Tools/utility.h"

class DebugPhysic
{
public:
    DebugPhysic();
    ~DebugPhysic();

    void AddDebugShapeCircle(sf::Vector2f position, float radius, sf::Vector2f offset);
    void AddDebugShapeRectangle(sf::Vector2f position, sf::Vector2f size, sf::Vector2f offset, float rotation);

    void AddDebugShapeConvex(sf::Vector2f position, const std::vector< Point >& m_points);

    void UpdateDebugShape(const sf::Vector2f& position, const float& rotation);
    void DrawDebugShape(sf::RenderWindow& window);

private:
    std::vector< sf::CircleShape > m_circles;
    std::vector< sf::RectangleShape > m_rectangles;
    std::vector< sf::ConvexShape > m_convexes;

    sf::Vector2f m_offset;

};

#endif