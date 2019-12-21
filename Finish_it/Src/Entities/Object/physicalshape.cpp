#include "physicalshape.h"

PhysicalShape::PhysicalShape(const ObjectNode* obj, b2BodyType bodyType, bool isFixedRotation)
{
	if (obj) {
		m_name = obj->GetName();
		m_pos = obj->GetPosition();
		m_size = obj->GetSize();

		this->CreateBody(obj->GetPosition(), obj->GetRotation(), bodyType, nullptr, isFixedRotation);
		this->InitFixture(obj);
	}

	for (b2Fixture* f = m_b2Body->GetFixtureList(); f; f = f->GetNext())
	{
		if (f->IsSensor()) {
			b2Filter filter;
			filter.categoryBits = HitboxType::SENSOR;
			filter.maskBits = HitboxType::PLAYER_SENSOR;
			f->SetFilterData(filter);
		}
		else {
			b2Filter filter;
			filter.categoryBits = HitboxType::PHYSICAL;
			filter.maskBits = HitboxType::PHYSICAL | HitboxType::PLAYER_PHYSICAL;
			f->SetFilterData(filter);
		}
	}
}

PhysicalShape::~PhysicalShape()
{
}