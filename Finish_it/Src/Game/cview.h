#ifndef __CVIEW__
#define __CVIEW__

#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>

class CView: public sf::View
{
public:
    CView(sf::Vector2i limitPos, sf::Vector2i limitSize, sf::Vector2f viewSize);
	CView();
    ~CView();

    void GoTo(const sf::Vector2f& pos);
	void SetLimit(sf::Vector2i pos, sf::Vector2i size);

private:
	sf::Vector2i m_pos;
	sf::Vector2i m_size;

};

#endif