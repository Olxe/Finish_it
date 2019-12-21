#include "object.h"

Object::Object(const ObjectNode* obj, const TileNode* tile, const std::string& texturePath, sf::Vector2f frameSize, sf::Vector2i posFrame)
	: PhysicalEntity(obj->GetGid(), obj->GetName(), tile->GetType())
	, currentState(StateObject::OFF)
	, hero(nullptr)
	, isInteractPush(false)
{
	InitStats(tile->GetProperties()); 
	InitEntity(texturePath, sf::Vector2f(frameSize), posFrame, obj->GetPosition(), obj->GetRotation());
	InitBody(tile, this->getPosition(), this->getRotation(), this->getOrigin(), this);
	SetIsAlive(true);

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

Object::~Object()
{
}

void Object::OnUpdate(const sf::Vector2f& mousePosition, const float& deltaTime)
{
	if (hero && hero->GetIsAlive()) {
		if (InputManager::Action(InputAction::INTERACT)) {
			if (!isInteractPush) {
				isInteractPush = true;
				OnInteract();
			}
		}
		else isInteractPush = false;
	}

	UpdateAnimation(deltaTime);
}

void Object::AddDependentObject(std::shared_ptr<Object> obj)
{
	m_dependentObjects.push_back(obj);
}

void Object::AddDependentObject(Object* obj)
{
	m_actionnableObjects.push_back(obj);
}

void Object::CheckSensorCollision(PhysicalEntity* pOther)
{
	if (Heroes * h = static_cast<Heroes*>(pOther)) {
		if (h->IsMainHero) {
			hero = h;
		}
	}
}

void Object::CheckEndSensorContact(PhysicalEntity* pOther)
{
	if (Heroes * h = static_cast<Heroes*>(pOther)) {
		if (h->IsMainHero) {
			hero = nullptr;
		}
	}
}