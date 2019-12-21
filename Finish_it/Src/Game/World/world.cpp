#include "world.h"

World::World()
	: m_currentTime(0.0)
	, m_timeStep(1.f / 60.f)
{
    Init();
}

World::~World()
{
}

void World::Init()
{
	Box2DWorld::GetInstance()->GetWorld()->SetContactListener(&m_contactListenner);
    m_levelManager.LoadLevel(2);
}

void World::Update(const float& deltaTime)
{
	std::string& command = Command::Instance()->LastCommand();
	if (command == "NEXT_LEVEL") {
		display(command);
		m_levelManager.NextLevel();
	}
	if (command == "PREVIOUS_LEVEL") {
		display(command);
		m_levelManager.PreviousLevel();
	}
	command.clear();

    sf::Event* event = EventManager::GetEvent(sf::Event::KeyReleased);
    if(event != nullptr){
        if(event->key.code == sf::Keyboard::Numpad1){
            m_levelManager.LoadLevel(1);
        }
        else if(event->key.code == sf::Keyboard::Numpad2){
            m_levelManager.LoadLevel(2);
        }
        else if(event->key.code == sf::Keyboard::Numpad3){
            m_levelManager.LoadLevel(3);
        }
        else if(event->key.code == sf::Keyboard::Numpad4){
            m_levelManager.LoadLevel(4);
        }
		else if (event->key.code == sf::Keyboard::Numpad5) {
			m_levelManager.LoadLevel(5);
		}
		else if (event->key.code == sf::Keyboard::O) {
			CWindow::GetInstance()->SetFPS(Settings::GetFPS() / 2);
		}
		else if (event->key.code == sf::Keyboard::P) {
			CWindow::GetInstance()->SetFPS(Settings::GetFPS() * 2);
		}
    }


	/*m_currentTime += deltaTime;
	while (m_currentTime >= m_timeStep)
	{
		

		m_currentTime -= m_timeStep;
	}*/

	Box2DWorld::GetInstance()->GetWorld()->Step(m_timeStep, 8, 3);

	m_levelManager.Update(deltaTime);
}

void World::Draw(sf::RenderWindow& window)
{
    window.clear();

    m_levelManager.Draw(window);

    window.display();
}