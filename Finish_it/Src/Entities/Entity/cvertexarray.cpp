#include "cvertexarray.h"

CVertexArray::CVertexArray()
    : isInit(false)
    , m_texture(nullptr)
{
}

CVertexArray::~CVertexArray()
{
}

void CVertexArray::LoadVertexArray(std::string texturePath, sf::Vector2i sizeMap)
{
	isInit = true;
	m_texture = AssetManager::GetInstance()->GetTexture(texturePath);
	//m_texture->setSmooth(true);
	m_vertexArray.setPrimitiveType(sf::Quads);
	//Allow to determine the number of vertex which define this tilemap/layer (4 vertex for one m_texture/tile)
	m_vertexArray.resize(sizeMap.x * sizeMap.y * 4);
}

void CVertexArray::draw(sf::RenderTarget& target, sf::RenderStates states) const
{    
    if(isInit){
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertexArray, states);
    }
}