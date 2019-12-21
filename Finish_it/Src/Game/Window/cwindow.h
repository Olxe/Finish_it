#ifndef __WINDOW__
#define __WINDOW__

#include <SFML/Graphics/RenderWindow.hpp>

#include "settings.h"
#include "eventmanager.h"

class CWindow: public sf::RenderWindow
{
private:
    CWindow();
    ~CWindow();
public:
	static CWindow* GetInstance();

    void Init();
    void Update();

    bool GetIsWindowFocus() { return isWindowFocus; };
    float GetDeltaTime();

	void SetFPS(unsigned int fps);

private:
	static CWindow* m_instance;
    bool isWindowFocus;
    sf::Clock m_clockDeltaTime;
};

#endif