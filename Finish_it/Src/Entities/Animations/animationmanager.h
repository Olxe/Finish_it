#pragma once

#include "../Entity/csprite.h"
#include "animation.h"

class AnimationManager : public CSprite
{
public:
	AnimationManager();
	~AnimationManager();

protected:
	virtual void OnAnimationFinished(std::string name) { ; }

	bool AddAnimation(std::string name, sf::Vector2f frameSize, float frameTime, std::vector<sf::Vector2i> framePos, bool loop = true, bool cancelMovement = false, int priority = 0);
	bool LunchAnimation(const std::string& name);
	
	Animation* CurrentAnimation() { return m_currentAnimation; }

	bool UpdateAnimation(const float& deltaTime);
	std::string NameCurrentAnimation() const;
	bool VelocityCanceled() const;
	bool IsCurrentAnimationActive() const;

private:
	std::vector< Animation* > m_animations;
	Animation* m_currentAnimation;

};

