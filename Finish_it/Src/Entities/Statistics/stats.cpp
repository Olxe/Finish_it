#include "stats.h"

Stats::Stats()
    : isAlive(true)
    , m_maxLife(0.f)
    , m_life(0.f)
    , m_maxSpeed(0.f)
    , m_acceleration(0.f)
    , m_deceleration(0.f)
{
}

Stats::~Stats()
{
}

float Stats::GetDeceleration() const
{
    return m_deceleration;
}

bool Stats::InitStats(const PropertiesNode* properties)
{
	if (!properties) return false;

    m_maxLife = properties->GetProperty("maxLife").ToFloat();
    SetLife(properties->GetProperty("life").ToFloat());
    SetMaxSpeed(properties->GetProperty("maxSpeed").ToFloat());
    SetAcceleration(properties->GetProperty("acceleration").ToFloat());
    SetDeceleration(properties->GetProperty("deceleration").ToFloat());

	return true;
}

bool Stats::SetIsAlive(bool state)
{
	isAlive = state;
	m_life = 0.f;
	return isAlive;
}

float Stats::SetMaxSpeed(const float& maxSpeed)
{
    m_maxSpeed = maxSpeed;
    return m_maxSpeed;
}

float Stats::SetAcceleration(const float& acceleration)
{
    m_acceleration = acceleration;
    if(m_acceleration < 0.f) m_acceleration = 0.f;
    return m_acceleration;
}

float Stats::SetDeceleration(const float& deceleration)
{
    m_deceleration = deceleration;

    if(m_deceleration > 1.f) m_deceleration = 1.f;
    if(m_deceleration < 0.f) m_deceleration = 0.f;

    return m_deceleration;
}

float Stats::AddLife(const float& amount)
{
    if(amount <= 0.f) return m_life;

    m_life += amount;
    if(m_life > m_maxLife) m_life = m_maxLife;

    return m_life;
}

float Stats::RemoveLife(const float& amount)
{
    m_life -= amount;
    if(m_life <= 0.f){
        m_life = 0.f;
        isAlive = false;
    } 

    return m_life;
}

float Stats::SetMaxLife(const float& maxLife)
{
    m_maxLife = maxLife;
    if(m_maxSpeed < 0.f) m_maxSpeed = 0.f;
    return m_maxLife;
}

float Stats::SetLife(const float& amount)
{
    m_life = amount;

    if(m_life >= m_maxLife) m_life = m_maxLife;
    if(m_life <= 0){
        m_life = 0;
        isAlive = false;
    }

    return m_life;
}