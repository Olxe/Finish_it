#include "animationmanager.h"

AnimationManager::AnimationManager()
	: m_currentAnimation(nullptr)
{
}

AnimationManager::~AnimationManager()
{
	clearVector(m_animations);
}

bool AnimationManager::AddAnimation(std::string name, sf::Vector2f frameSize, float frameTime, std::vector<sf::Vector2i> framePos, bool loop, bool cancelMovement, int priority)
{
	for (auto anim : m_animations) {
		if (anim->Name() == name) {
			return false;
		}
	}

	Animation* anim = new Animation(this, framePos, (sf::Vector2i)frameSize, frameTime, name, loop, cancelMovement, priority);
	//m_currentAnimation = anim;
	m_animations.push_back(anim);

	return true;
}

bool AnimationManager::LunchAnimation(const std::string& name)
{
	if (m_currentAnimation) {
		if (m_currentAnimation->Name() != name || !m_currentAnimation->Active()) {
			for (auto anim : m_animations) {
				if (anim->Name() == name) {
					if (anim->Priority() >= m_currentAnimation->Priority() || !m_currentAnimation->Active()) {
						m_currentAnimation = nullptr;
						m_currentAnimation = anim;
						m_currentAnimation->Start();
						return true;
					}
				}
			}
		}
	}
	else {
		for (auto anim : m_animations) {
			if (anim->Name() == name) {
				m_currentAnimation = anim;
				m_currentAnimation->Start();
				return true;
			}
		}
	}

	return false;
}

bool AnimationManager::UpdateAnimation(const float& deltaTime)
{
	if (m_currentAnimation) {
		if (!m_currentAnimation->Update(deltaTime)) {
			OnAnimationFinished(NameCurrentAnimation());
			return false;
		}

		return true;
	}

	return false;
}

std::string AnimationManager::NameCurrentAnimation() const
{
	if (m_currentAnimation) return m_currentAnimation->Name();
	else return "";
}

bool AnimationManager::VelocityCanceled() const
{
	if (m_currentAnimation) return m_currentAnimation->CancelMovement();

	return false;
}

bool AnimationManager::IsCurrentAnimationActive() const
{
	if (m_currentAnimation) return m_currentAnimation->Active();
	return false;
}
