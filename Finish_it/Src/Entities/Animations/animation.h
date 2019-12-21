#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation
{
public:
	Animation(sf::Sprite* spriteSheet, std::vector<sf::Vector2i> framesPos, sf::Vector2i frameSize, float frameTime, std::string name, bool loop, bool cancelMovement, int priority);
	~Animation();

	void Start();
	void Stop();
	void Pause();
	void Resume();
	bool Update(const float& deltaTime);
	const std::string& Name() const { return m_name; }
	const int& Priority() const { return m_priority; }
	bool Active() const { return isActive; }
	bool CancelMovement() const { return isCancelMovement;  }

private:
	bool updateFrames();

private:
	bool isActive;
	bool isLoop;
	bool isCancelMovement;

	sf::Sprite* m_spriteSheet;
	std::vector<sf::IntRect> m_frames;
	float m_frameTime;
	std::string m_name;
	float m_currentTime;
	size_t m_currentFrame;
	int m_priority;

};