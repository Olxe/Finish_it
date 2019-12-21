#ifndef __POINT__
#define __POINT__

#include <SFML/System/Vector2.hpp>

class Point
{
public:
    Point(float _x, float _y);
    Point();
    ~Point();

	sf::Vector2f GetPosition() const { return sf::Vector2f(x, y); }

    float x;
    float y;

};

#endif