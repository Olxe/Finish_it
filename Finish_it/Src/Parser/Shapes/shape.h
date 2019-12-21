#ifndef __SHAPE__
#define __SHAPE__

#include <SFML/System/Vector2.hpp>

class Shape
{
public:
    Shape(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(0.f, 0.f), float rotation = 0.f);
    virtual ~Shape();

    sf::Vector2f GetPosition() const { return m_position; }
    sf::Vector2f GetSize() const { return m_size; }
    float GetRotation() const { return m_rotation; }

private:
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    float m_rotation;

};

#endif