#ifndef __STATS__
#define __STATS__

#include <iostream>
#include "../../Parser/Nodes/propertiesnode.h"

class Stats
{
public:
    Stats();
    virtual ~Stats();

	bool GetIsAlive() const { return isAlive; }
	float GetMaxLife() const { return m_maxLife; }
	float GetLife() const { return m_life; }

protected:
    //getter
    float GetMaxSpeed() const { return m_maxSpeed; }
    float GetAcceleration() const { return m_acceleration; }
    float GetDeceleration() const;

protected:
    //setter
	bool SetIsAlive(bool state);
    float SetMaxSpeed(const float& maxSpeed);
    float SetAcceleration(const float& acceleration);
    float SetDeceleration(const float& deceleration);
    float AddLife(const float& amount);
    float RemoveLife(const float& amount);
    float SetMaxLife(const float& maxLife);
    float SetLife(const float& amount);

protected:
    bool InitStats(const PropertiesNode* properties);

private:
    bool isAlive;
    float m_maxLife;
    float m_life;
    float m_maxSpeed;
    float m_acceleration;
    float m_deceleration;

};

#endif