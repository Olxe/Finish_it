#pragma once

#include <Box2D/Box2D.h>
#include <iostream>

#include "../../Entities/Physic/physicalentity.h"

class MyContactListenner: public b2ContactListener
{
public:
	MyContactListenner();
	~MyContactListenner();

	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;

};

