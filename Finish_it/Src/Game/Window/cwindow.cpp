#include "cwindow.h"

CWindow* CWindow::m_instance = nullptr;

CWindow::CWindow():
    isWindowFocus(true)
{
}

CWindow::~CWindow()
{
}

CWindow* CWindow::GetInstance()
{
	if (!m_instance) m_instance = new CWindow();
	return m_instance;
}

void CWindow::Init()
{
    Settings::Init();
	this->create(sf::VideoMode(Settings::GetWindowSize().x, Settings::GetWindowSize().y), "MyFirstRealProject", sf::Style::Close);
	this->setFramerateLimit(Settings::GetFPS());
}

void CWindow::SetFPS(unsigned int fps)
{
	Settings::SetFPS(fps);

	std::cout << Settings::GetFPS() << std::endl;
	this->setFramerateLimit(Settings::GetFPS());
}

void CWindow::Update()
{
    EventManager::Update(this);
    InputManager::Update();

    if(EventManager::IsEventTriggered(sf::Event::GainedFocus)) isWindowFocus = true;
    if(EventManager::IsEventTriggered(sf::Event::LostFocus)) isWindowFocus = false;
}

float CWindow::GetDeltaTime()
{
    return m_clockDeltaTime.restart().asSeconds();
}