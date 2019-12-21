#include "inputmanager.h"

std::map<int, InputManager::Key> InputManager::m_keyboardBinds;
std::map<int, InputManager::Button> InputManager::m_mouseBinds;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}
#include <iostream>
bool InputManager::BindKey(const int& id, sf::Keyboard::Key key)
{
	Key k = { false, key };
    m_keyboardBinds[id] = k;
	
    return true;
}

bool InputManager::BindButton(const int& id, const sf::Mouse::Button& button)
{
	Button b = { false, button };
    m_mouseBinds[id] = b;
    return true;
}

void InputManager::Update()
{
    for (auto& key : m_keyboardBinds){
        key.second.isPressed = sf::Keyboard::isKeyPressed(key.second.key);
    }

	for (auto& button : m_mouseBinds) {
		button.second.isPressed = sf::Mouse::isButtonPressed(button.second.button);
	}
}

bool InputManager::Action(const int& idAction)
{
    auto key = m_keyboardBinds.find(idAction);
	if (key != m_keyboardBinds.end() && key->second.isPressed) {
		return true;
	}

	auto button = m_mouseBinds.find(idAction);
	if (button != m_mouseBinds.end() && button->second.isPressed) {
		return true;
	}

    return false;
}