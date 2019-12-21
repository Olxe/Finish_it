#include "shape.h"

Shape::Shape(sf::Vector2f position, sf::Vector2f size, float rotation)
    : m_position(position)
    , m_size(size)
    , m_rotation(rotation)
{
}

Shape::~Shape()
{
}