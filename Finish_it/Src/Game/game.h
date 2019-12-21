#ifndef __GAME__
#define __GAME__

#include "World/world.h"
#include "Window/cwindow.h"

class Game
{
public:
	Game();
	~Game();

	void StartGame();

private:
	void init();

private:
	World* m_world;
};

#endif