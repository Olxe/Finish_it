#include "settings.h"

sf::Vector2u Settings::m_windowSize;
unsigned int Settings::m_fps;

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::Init()
{
    InputManager::BindKey(InputAction::MOVE_UP, sf::Keyboard::Z);
    InputManager::BindKey(InputAction::MOVE_DOWN, sf::Keyboard::S);
    InputManager::BindKey(InputAction::MOVE_LEFT, sf::Keyboard::Q);
    InputManager::BindKey(InputAction::MOVE_RIGHT, sf::Keyboard::D);
	InputManager::BindKey(InputAction::INTERACT, sf::Keyboard::E);

	InputManager::BindButton(InputAction::ATTACK_LEFT, sf::Mouse::Left);
	InputManager::BindButton(InputAction::ATTACK_MIDDLE, sf::Mouse::Middle);
	InputManager::BindButton(InputAction::ATTACK_RIGHT, sf::Mouse::Right);


    m_windowSize = sf::Vector2u(1500, 800);
    m_fps = 80;
}

void Settings::SetFPS(unsigned int fps)
{
	m_fps = fps;
}

const sf::Vector2u& Settings::GetWindowSize()
{
    return m_windowSize;
}

const unsigned int& Settings::GetFPS()
{
    return m_fps;
}