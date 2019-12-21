#include "physicalentity.h"

PhysicalEntity::PhysicalEntity(int gid, std::string name, std::string type)
	: Entity(gid, name, type)
{
}

PhysicalEntity::~PhysicalEntity()
{
}