#include "eventmanager.h"

std::map< sf::Event::EventType, sf::Event > EventManager::m_event;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::Update(sf::RenderWindow* window)
{
    m_event.clear();

    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        default:
            m_event[event.type] = event;
            break;
        }
    }
}

sf::Event* EventManager::GetEvent(sf::Event::EventType eventType)
{
    auto it = m_event.find(eventType);
    if(it != m_event.end()){
        return &it->second;
    }

    return nullptr;
}

bool EventManager::IsEventTriggered(sf::Event::EventType eventType)
{
    auto it = m_event.find(eventType);
    if(it != m_event.end()){
        return true;
    }

    return false;
}