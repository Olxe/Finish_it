#ifndef __PHYSICALENTITY__
#define __PHYSICALENTITY__

#include "../Physic/physicalbody.h"
#include "../Entity/entity.h"

class PhysicalEntity: public Entity, public PhysicalBody
{
public:
    PhysicalEntity(int gid, std::string name, std::string type);
    virtual ~PhysicalEntity();

	//virtual void OnAnimationFinished_(std::string name) { display("test"); }

	virtual void OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime) = 0;
    virtual void CheckCollision(PhysicalEntity* pOther) = 0;
	virtual void CheckSensorCollision(PhysicalEntity* pOther) = 0;
	virtual void CheckEndContact(PhysicalEntity* pOther) = 0;
	virtual void CheckEndSensorContact(PhysicalEntity* pOther) = 0;


};

#endif