#include "mycontactlistenner.h"

MyContactListenner::MyContactListenner()
{
}

MyContactListenner::~MyContactListenner()
{
}

void MyContactListenner::BeginContact(b2Contact* contact)
{
	/*std::shared_ptr<PhysicalEntity>* entityA = static_cast<std::shared_ptr<PhysicalEntity>*>(contact->GetFixtureA()->GetBody()->GetUserData());
	if (*entityA) {
		display((*entityA)->Name());
	}*/
	
	PhysicalEntity* bodyA_userData = static_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicalEntity* bodyB_userData = static_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (!bodyA_userData || !bodyB_userData) return;

	
	/*b2WorldManifold manifold;
	contact->GetWorldManifold(&manifold);
	for (b2Vec2 point : manifold.points) {
		displayVec(sf::Vector2f(point.x * 30.f, point.y * 30.f));
		displayVec(bodyA_userData->getPosition());
		//printf("Contact at : [" + point.x + ", " + point.y + "]");
	}*/

	if (contact->GetFixtureA()->IsSensor() == true)
	{
		bodyA_userData->CheckSensorCollision(bodyB_userData);
	}
	else
	{
		bodyA_userData->CheckCollision(bodyB_userData);
		
	}

	if (contact->GetFixtureB()->IsSensor() == true)
	{
		bodyB_userData->CheckSensorCollision(bodyA_userData);
		
	}
	else
	{
		bodyB_userData->CheckCollision(bodyA_userData);
	}
}

void MyContactListenner::EndContact(b2Contact* contact)
{
	PhysicalEntity* bodyA_userData = static_cast<PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicalEntity* bodyB_userData = static_cast<PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (!bodyA_userData || !bodyB_userData) return;

	if (contact->GetFixtureA()->IsSensor() == true)
	{
		bodyA_userData->CheckEndSensorContact(bodyB_userData);
	}
	else
	{
		bodyA_userData->CheckEndContact(bodyB_userData);
	}

	if (contact->GetFixtureB()->IsSensor() == true)
	{
		bodyB_userData->CheckEndSensorContact(bodyA_userData);
	}
	else
	{
		bodyB_userData->CheckEndContact(bodyA_userData);
	}
}

void MyContactListenner::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
}

void MyContactListenner::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
}
