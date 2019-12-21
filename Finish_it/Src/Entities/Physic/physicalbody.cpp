#include "physicalbody.h"

PhysicalBody::PhysicalBody()
    : m_b2Body(nullptr)
{
}

PhysicalBody::~PhysicalBody()
{
	if (m_b2Body) {
		m_b2Body->SetUserData(nullptr);
		m_b2Body->GetWorld()->DestroyBody(m_b2Body);
		m_b2Body = nullptr;
	}
}

void PhysicalBody::InitBody(const TileNode* tile, sf::Vector2f bodyPosition, float bodyRotation, sf::Vector2f entityOrigin, void* ptrData)
{
	b2BodyType type = b2BodyType::b2_staticBody;
	bool isFixedRotation = true;

	if (tile)
	{
		if (const PropertiesNode * properties = tile->GetProperties()) {
			int bodyType = 0;
			bodyType = properties->GetProperty("physic").ToInt();
			isFixedRotation = properties->GetProperty("isFixedRotation").ToBool();
			if (bodyType == 0) type = b2BodyType::b2_staticBody;
			else if (bodyType == 1) type = b2BodyType::b2_kinematicBody;
			else if (bodyType == 2) type = b2BodyType::b2_dynamicBody;
		}
	}
	

	CreateBody(bodyPosition, bodyRotation, type, ptrData, isFixedRotation);

	if (tile) {
		if (const ObjectGroupNode * objgrp = tile->GetObjectGroup())
		{
			for (auto obj : objgrp->GetObjects())
			{
				InitFixture(obj, entityOrigin);
			}
		}
	}
}

bool PhysicalBody::InitFixture(const ObjectNode* obj, sf::Vector2f entityOrigin)
{
	float density = 1.f;
	bool isSensor = false;

	if (const PropertiesNode * properties = obj->GetProperties()) {
		density = properties->GetProperty("density").ToFloat(1.f);
		isSensor = properties->GetProperty("isSensor").ToBool();
	}

	if (const Shape * shape = obj->GetShape())
	{
		sf::Vector2f offset = (shape->GetPosition() + shape->GetSize() / 2.f) - entityOrigin;
		offset += getRotatedPosition(shape->GetSize() / 2.f, shape->GetRotation());
		AddFixtureRectangle(offset, shape->GetSize(), shape->GetRotation(), density, isSensor);
	}
	else if (const Ellipse * ellipse = obj->GetEllipse())
	{
		AddCircle((ellipse->GetPosition() + ellipse->GetSize() / 2.f) - entityOrigin, ellipse->GetSize().x / 2.f, density, isSensor);
	}
	else if (const Polygone * polygone = obj->GetPolygon())
	{
		AddPolygon(polygone->GetPosition() - entityOrigin, polygone->GetPoints(), density, isSensor);
	}
	else if (const Polyline * polyline = obj->GetPolyline())
	{
		for (size_t i = 0; i < polyline->GetPoints().size(); i++) {
			if (i > 0) {
				AddFixtureEdge(sf::Vector2f(polyline->GetPoints()[i].x, polyline->GetPoints()[i].y) - entityOrigin, sf::Vector2f(polyline->GetPoints()[i - 1].x, polyline->GetPoints()[i - 1].y) - entityOrigin, density, isSensor);
			}
		}
	}

	return true;
}

void PhysicalBody::CreateBody(sf::Vector2f position, float rotation, b2BodyType bodyType, void* userData, bool isFixedRotation)
{
	if (m_b2Body) {
		m_b2Body->SetUserData(nullptr);
		m_b2Body->GetWorld()->DestroyBody(m_b2Body);
		m_b2Body = nullptr;
	}

	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	bodyDef.angle = rotation / 180.f * b2_pi;
	bodyDef.type = bodyType;

	m_b2Body = Box2DWorld::GetInstance()->GetWorld()->CreateBody(&bodyDef);
	m_b2Body->SetFixedRotation(isFixedRotation);
	m_b2Body->SetUserData(userData);
}

void PhysicalBody::InitFixture(const ObjectNode* obj)
{
	//object layout because position is not usefull, doent need an offet local from an entity
	float density = 1.f;
	bool isSensor = false;

	if (const PropertiesNode * properties = obj->GetProperties()) {
		density = properties->GetProperty("density").ToFloat(1.f);
		isSensor = properties->GetProperty("isSensor").ToBool();
	}

	if (const Shape * shape = obj->GetShape())
	{
		sf::Vector2f offset = shape->GetSize() / 2.f;
		offset += getRotatedPosition(shape->GetSize() / 2.f, shape->GetRotation());
		AddFixtureRectangle(offset, shape->GetSize(), shape->GetRotation(), density, isSensor);
	}
	else if (const Ellipse * ellipse = obj->GetEllipse())
	{
		AddCircle(ellipse->GetSize() / 2.f, ellipse->GetSize().x / 2.f, density, isSensor);
	}
	else if (const Polygone * polygone = obj->GetPolygon())
	{
		AddPolygon(sf::Vector2f(0.f, 0.f), polygone->GetPoints(), density, isSensor);
	}
	else if (const Polyline * polyline = obj->GetPolyline())
	{
		for (size_t i = 0; i < polyline->GetPoints().size(); i++) {
			if (i > 0) {
				AddFixtureEdge(sf::Vector2f(polyline->GetPoints()[i].x, polyline->GetPoints()[i].y), sf::Vector2f(polyline->GetPoints()[i - 1].x, polyline->GetPoints()[i - 1].y), density, isSensor);
			}
		}
	}
}

bool PhysicalBody::AddFixtureRectangle(sf::Vector2f offset, sf::Vector2f size, float rotation, float density, bool isSensor)
{
	if (!m_b2Body) return false;
	
	//definition form
	b2PolygonShape shape;
	shape.SetAsBox(size.x / 2.0f / SCALE, size.y / 2.0f / SCALE, b2Vec2( offset.x / SCALE, offset.y / SCALE), rotation / 180.f * b2_pi);
	//definition fixture of this form
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	//fixtureDef.filter.groupIndex = -1;
	
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);

	return true;
}

bool PhysicalBody::AddFixtureEdge(sf::Vector2f p1, sf::Vector2f p2, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2EdgeShape shape;
	shape.Set(b2Vec2(p1.x / SCALE, p1.y / SCALE), b2Vec2(p2.x / SCALE, p2.y / SCALE));

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);
	return true;
}

bool PhysicalBody::AddCircle(sf::Vector2f offset, float radius, float density, bool isSensor)
{
	if (!m_b2Body) return false;
    //definition form
	b2CircleShape shape;
	shape.m_radius = radius / SCALE;
    shape.m_p.Set(offset.x / SCALE, offset.y / SCALE);

	//definition fixture of this form
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);
	return true;
}

bool PhysicalBody::AddPolygon(sf::Vector2f offset, const std::vector< Point >& points, float density, bool isSensor)
{
	if (!m_b2Body) return false;

	b2Vec2* vertices = new b2Vec2[points.size()];//delete ?
    for(size_t i = 0; i < points.size(); i++){
        vertices[i].Set((points[i].x + offset.x) / SCALE, (points[i].y + offset.y) / SCALE);
    }

    b2PolygonShape shape;
    shape.Set(vertices, points.size());

    //definition fixture of this form
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.isSensor = isSensor;

	m_b2Body->CreateFixture(&fixtureDef);
	return true;
}

sf::Vector2f PhysicalBody::getRotatedPosition(const sf::Vector2f& origin, const float& rotation)
{
    float centerX = origin.x;
    float centerY = origin.y;
    double cosRotation = cos(rotation / 180.f * 3.14f);
    double sinRotation = sin(rotation / 180.f * 3.14f);
    sf::Vector2f rotatedCenter;
    rotatedCenter.x = static_cast<float>(centerX * cosRotation - centerY * sinRotation) - origin.x;
    rotatedCenter.y = static_cast<float>(centerX * sinRotation + centerY * cosRotation) - origin.y;

    return rotatedCenter;
}