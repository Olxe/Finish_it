#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

#include <SFML/Window.hpp>
#include <map>
#include <iostream>

namespace InputAction
{
    enum action{
        MOVE_UP,
        MOVE_DOWN,
        MOVE_LEFT,
        MOVE_RIGHT,
		ATTACK_LEFT,
		ATTACK_MIDDLE,
		ATTACK_RIGHT,
		INTERACT
    };
}

class InputManager
{

struct Key
{
    bool isPressed;
    sf::Keyboard::Key key;
};

struct Button
{
	bool isPressed;
	sf::Mouse::Button button;
};

private:
    InputManager();
    ~InputManager();

public:
    static bool BindKey(const int& id, sf::Keyboard::Key key);
    static bool BindButton(const int& id, const sf::Mouse::Button& button);

    static void Update();
    static bool Action(const int& idAction);

private:
    static std::map<int, Key> m_keyboardBinds;
    static std::map<int, Button> m_mouseBinds;

};

#endif