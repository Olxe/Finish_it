#ifndef __PHYSICALENGINE__
#define __PHYSICALENGINE__

#include "../../Parser/Nodes/tilenode.h"
#include "../../Game/World/box2dworld.h"
#include "debugphysic.h"

enum HitboxType
{
	ANY				= 0x0000,
	PLAYER_SENSOR	= 0x0001,
	PLAYER_PHYSICAL	= 0x0002,
	PHYSICAL		= 0x0004,
	SENSOR			= 0x0008
};

class PhysicalBody//: public DebugPhysic
{
public:
    PhysicalBody();
    ~PhysicalBody();

	void InitBody(const TileNode* tile, sf::Vector2f bodyPosition, float bodyRotation, sf::Vector2f entityOrigin, void* ptrData);
	void CreateBody(sf::Vector2f position, float rotation, b2BodyType bodyType, void* userData, bool isFixedRotation);
	bool InitFixture(const ObjectNode* obj, sf::Vector2f entityOrigin);
	void InitFixture(const ObjectNode* obj);
	

private:
	bool AddFixtureRectangle(sf::Vector2f offset, sf::Vector2f size, float rotation, float density = 1.f, bool isSensor = false);
	bool AddFixtureEdge(sf::Vector2f p1, sf::Vector2f p2, float density = 1.f, bool isSensor = false);//no offset ?
	bool AddPolygon(sf::Vector2f offset, const std::vector< Point >& points, float density = 1.f, bool isSensor = false);
	bool AddCircle(sf::Vector2f offset, float radius, float density = 1.f, bool isSensor = false);

private:
    sf::Vector2f getRotatedPosition(const sf::Vector2f& origin, const float& rotation);

protected:
    const float SCALE = 30.0f;
    b2Body* m_b2Body;
};

#endif