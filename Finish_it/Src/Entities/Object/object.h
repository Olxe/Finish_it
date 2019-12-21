#ifndef __OBJECT__
#define __OBJECT__

#include "../Playable/heroes.h"
#include "../../Game/Window/inputmanager.h"

enum StateObject
{
	ON,
	OFF
};

class Object: public PhysicalEntity
{
public:
    Object(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize = sf::Vector2f(0, 0), sf::Vector2i posFrame = sf::Vector2i(0, 0));
    virtual ~Object();
	

	virtual void OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime);
	virtual void AddDependentObject(std::shared_ptr<Object> obj);
	virtual void AddDependentObject(Object* obj);
	virtual void OnAction() { ; }
	virtual void OnInteract() { ; }
	
	virtual void CheckCollision(PhysicalEntity* pOther) override { ; }
	virtual void CheckEndContact(PhysicalEntity* pOther) override { ; }
	virtual void CheckSensorCollision(PhysicalEntity* pOther) override;
	virtual void CheckEndSensorContact(PhysicalEntity* pOther) override;

protected:
	StateObject currentState;
	std::vector< std::shared_ptr<Object> > m_dependentObjects;

	std::vector< Object* > m_actionnableObjects;
	Heroes* hero;
	
private:
	bool isInteractPush;

};

#endif