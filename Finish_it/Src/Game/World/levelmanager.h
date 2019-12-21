#ifndef __LEVELMANAGER__
#define __LEVELMANAGER__

#include <SFML/System.hpp>

#include "../../Player/player.h"
#include "../cview.h"
#include "../Window/cwindow.h"
#include "../../Parser/Load/loadmap.h"

class LevelManager
{
public:
    LevelManager();
    ~LevelManager();


    bool LoadLevel(size_t idLevel);
	void NextLevel();
	void PreviousLevel();

    void Update(const float& deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    bool loadPlayer();
	void loadCamera(sf::Vector2f position);

private:
	LoadMap* m_loadMap;
	Player* m_playerMechanics;
    CView m_view;
    std::vector< Layout* > m_layouts;

	std::vector< std::string > m_levels;
	size_t m_currentLevel;
};

#endif