#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <map>
#include <iostream>

class EventManager
{
private:
    EventManager();
    ~EventManager();

public:
    static void Update(sf::RenderWindow* window);
    static sf::Event* GetEvent(sf::Event::EventType eventType);
    static bool IsEventTriggered(sf::Event::EventType eventType);

private:
    static std::map< sf::Event::EventType, sf::Event > m_event;
    
};

#endif