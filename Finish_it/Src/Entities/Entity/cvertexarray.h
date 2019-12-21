#ifndef __CVERTEXARRAY__
#define __CVERTEXARRAY__

#include <SFML/Graphics.hpp>

#include "assetmanager.h"

class CVertexArray: public sf::Drawable, public sf::Transformable
{
public:
    CVertexArray();
    virtual ~CVertexArray();

protected:
	void LoadVertexArray(std::string texturePath, sf::Vector2i sizeMap);
	sf::Vertex* GetVertexTo(int id) { return &m_vertexArray[id]; }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    bool isInit;        
    sf::Texture* m_texture;
    sf::VertexArray m_vertexArray;

};

#endif