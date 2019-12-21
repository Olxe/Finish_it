#include "game.h"

Game::Game()
	: m_world(nullptr)
{
}

Game::~Game()
{  
	clearPtr(m_world);
    AssetManager::KillInstance();
    Box2DWorld::KillInstance();
}

void Game::init()
{
	CWindow::GetInstance()->Init();
    m_world = new World();
}

void Game::StartGame()
{
	init();

	CWindow* window = CWindow::GetInstance();

	while (window->isOpen())
    {
		window->Update();

        if(window->GetIsWindowFocus()) m_world->Update(window->GetDeltaTime());

        m_world->Draw(*window);
    }
}