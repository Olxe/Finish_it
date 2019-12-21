#include "ellipse.h"

Ellipse::Ellipse(float x, float y, float width, float height)
    : Shape(sf::Vector2f(x, y), sf::Vector2f(width, height), 0.f)
{
}

Ellipse::~Ellipse()
{
}