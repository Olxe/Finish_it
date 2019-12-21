#include "cview.h"

CView::CView(sf::Vector2i limitPos, sf::Vector2i limitSize, sf::Vector2f viewSize)
	: m_pos(limitPos)
	, m_size(limitSize)
{
	this->setSize(viewSize);
}

CView::CView()
{
}

CView::~CView()
{
}

void CView::GoTo(const sf::Vector2f& pos)
{
    if(false)
    {
        sf::Vector2f distance =  pos - this->getCenter();
        float magnitude = sqrt(distance.x * distance.x + distance.y * distance.y);

		if (magnitude > 1.f) {
			sf::Vector2f velocity = distance / magnitude;
			this->move(velocity * (magnitude / 15.f));
		}

		if (this->getCenter().x - this->getSize().x / 2.f < m_pos.x) this->setCenter(m_pos.x + this->getSize().x / 2.f, this->getCenter().y);
		else if (this->getCenter().x + this->getSize().x / 2.f > m_pos.x + m_size.x) this->setCenter(m_pos.x + m_size.x - this->getSize().x / 2.f, this->getCenter().y);
		if (this->getCenter().y - this->getSize().y / 2.f < m_pos.y) this->setCenter(this->getCenter().x, m_pos.y + this->getSize().y / 2.f);
		else if (this->getCenter().y + this->getSize().y / 2.f > m_pos.y + m_size.y) this->setCenter(this->getCenter().x, m_pos.y + m_size.y - this->getSize().y / 2.f);
    }
    else
    {
		//this->setCenter(pos);
		this->setCenter(std::floor(pos.x), std::floor(pos.y));

		if (this->getCenter().x - this->getSize().x / 2.f < m_pos.x) this->setCenter(m_pos.x + this->getSize().x / 2.f, this->getCenter().y);
		else if (this->getCenter().x + this->getSize().x / 2.f > m_pos.x + m_size.x) this->setCenter(m_pos.x + m_size.x - this->getSize().x / 2.f, this->getCenter().y);
		if (this->getCenter().y - this->getSize().y / 2.f < m_pos.y) this->setCenter(this->getCenter().x, m_pos.y + this->getSize().y / 2.f);
		else if (this->getCenter().y + this->getSize().y / 2.f > m_pos.y + m_size.y) this->setCenter(this->getCenter().x, m_pos.y + m_size.y - this->getSize().y / 2.f);
    }
}

void CView::SetLimit(sf::Vector2i pos, sf::Vector2i size)
{
	m_pos = pos;
	m_size = size;
}
