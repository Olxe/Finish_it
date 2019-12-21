#ifndef __WORLD__
#define __WORLD__

#include "levelmanager.h"

#include "../../Entities/Physic/mycontactlistenner.h"
#include "../Window/command.h"

class World
{
public:
    World();
    ~World();

    void Init();
	void Update(const float& deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    LevelManager m_levelManager;
	MyContactListenner m_contactListenner;
	double m_currentTime;
	float m_timeStep;

	
};

#endif