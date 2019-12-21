#include "player.h"

Player::Player(std::shared_ptr<Heroes> player)
	: m_player(player)
	, isLeftAttackPush(false)
	, isRightAttackPush(false)
{
}

Player::~Player()
{
}

void Player::Update(const sf::Vector2f& mousePosition, const float& deltaTime)
{
	if (m_player->GetIsAlive()) 
	{
		
		shoot(mousePosition);
		move(deltaTime);
		
	}
}

const sf::Vector2f& Player::GetPosition() const
{
	return m_player->getPosition();
}

void Player::move(const float& deltaTime)
{
	sf::Vector2i velocity = sf::Vector2i(0, 0);

	if (InputManager::Action(InputAction::MOVE_UP)) velocity.y += -1;
	if (InputManager::Action(InputAction::MOVE_LEFT)) velocity.x += -1;
	if (InputManager::Action(InputAction::MOVE_DOWN)) velocity.y += 1;
	if (InputManager::Action(InputAction::MOVE_RIGHT)) velocity.x += 1;

	m_player->OnMove(velocity, deltaTime);
}

void Player::shoot(const sf::Vector2f& mousePosition)
{
	if (InputManager::Action(InputAction::ATTACK_LEFT) == true) {
		if (!isLeftAttackPush) {
			m_player->OnLeftClickPressed(mousePosition);
			isLeftAttackPush = true;
		}
		m_player->OnLeftClick(mousePosition);
	}
	else if(isLeftAttackPush) {
		m_player->OnLeftClickReleased(mousePosition);
		isLeftAttackPush = false;
	}

	if (InputManager::Action(InputAction::ATTACK_RIGHT) == true) {
		if (!isRightAttackPush) {
			m_player->OnRightClickPressed(mousePosition);
			isRightAttackPush = true;
		}
		m_player->OnRightClick(mousePosition);
	}
	else if(isRightAttackPush){
		m_player->OnRightClickReleased(mousePosition);
		isRightAttackPush = false;
	}
}