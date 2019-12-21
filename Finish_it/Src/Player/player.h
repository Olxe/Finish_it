#ifndef __PLAYERMECHANICS__
#define __PLAYERMECHANICS__

#include <cmath>

#include "../Entities/Playable/heroes.h"
#include "../Game/Window/inputmanager.h"

class Player
{
public:
	Player(std::shared_ptr<Heroes> player);
    ~Player();

    void Update(const sf::Vector2f& mousePosition, const float& deltaTime);
	const sf::Vector2f& GetPosition() const;

private:
	void move(const float& deltaTime);
	void shoot(const sf::Vector2f& mousePosition);

private:
	std::shared_ptr<Heroes> m_player;
	bool isLeftAttackPush;
	bool isRightAttackPush;
};

#endif