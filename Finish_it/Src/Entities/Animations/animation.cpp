#include "animation.h"

Animation::Animation(sf::Sprite* spriteSheet, std::vector<sf::Vector2i> framesPos, sf::Vector2i frameSize, float frameTime, std::string name, bool loop, bool cancelMovement, int priority)
	: isActive(false)
	, isCancelMovement(cancelMovement)
	, isLoop(loop)
	, m_spriteSheet(spriteSheet)
	, m_frameTime(frameTime)
	, m_name(name)
	, m_currentTime(0.f)
	, m_currentFrame(0)
	, m_priority(priority)
{
	for (auto framePos : framesPos) {
		m_frames.push_back(sf::IntRect(framePos.x * frameSize.x, framePos.y * frameSize.y, frameSize.x, frameSize.y));
	}
}

Animation::~Animation()
{
}

void Animation::Start()
{
	
	isActive = true;
	m_currentFrame = 0;
	m_currentTime = 0.f;

	updateFrames();
}

void Animation::Stop()
{
	isActive = false;
	m_currentFrame = 0;
	m_currentTime = 0.f;
}

void Animation::Pause()
{
	isActive = false;
}

void Animation::Resume()
{
	isActive = true;
}

bool Animation::Update(const float& deltaTime)
{
	if (isActive && !m_frames.empty()) {
		m_currentTime += deltaTime;
		while (m_currentTime >= m_frameTime) {
			m_currentTime -= m_frameTime;

			if (!updateFrames()) return false;
		}
	}

	return true;
}

bool Animation::updateFrames()
{
	bool isWorking = true;
	if (m_currentFrame >= m_frames.size()) {
		m_currentFrame = 0;
		isWorking = false;
		if (!isLoop) {
			isActive = false;
			return isWorking;
		}
	}

	m_spriteSheet->setTextureRect(m_frames[m_currentFrame]);

	m_currentFrame++;

	return isWorking;
}

