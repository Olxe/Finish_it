#ifndef __SETTINGS__
#define __SETTINGS__

#include <SFML/System/Vector2.hpp>
#include "inputmanager.h"

class Settings
{
private:
    Settings();
    ~Settings();

public:
    static void Init();
    static const sf::Vector2u& GetWindowSize();
    static const unsigned int& GetFPS();
	static void SetFPS(unsigned int fps);

private:
    static sf::Vector2u m_windowSize;
    static unsigned int m_fps;
};

#endif