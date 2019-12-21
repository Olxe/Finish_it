#include "levelmanager.h"

LevelManager::LevelManager()
    : m_loadMap(nullptr)
    , m_playerMechanics(nullptr)
{
	m_view.setSize(static_cast<sf::Vector2f>(Settings::GetWindowSize()));
	m_levels = { "stage_1", "stage_2", "stage_3", "stage_4" };
}

LevelManager::~LevelManager()
{
	clearPtr(m_loadMap);
    clearPtr(m_playerMechanics);
    clearVector(m_layouts);
}

bool LevelManager::LoadLevel(size_t idLevel)
{
    clearVector(m_layouts);
    clearPtr(m_loadMap);

    m_loadMap = new LoadMap();

	std::string nameLevel = "STAGE_NO_AVAILABLE";
	if (idLevel - 1 < m_levels.size()) {
		nameLevel = m_levels[idLevel - 1];
		m_currentLevel = idLevel;
	}
    m_layouts = m_loadMap->Load("Res/Maps/", nameLevel + ".tmx");
    
    loadPlayer();
	if (m_playerMechanics) {
		loadCamera(m_playerMechanics->GetPosition());
	}
	
    return true;
}

void LevelManager::NextLevel()
{
	LoadLevel(m_currentLevel + 1);
}

void LevelManager::PreviousLevel()
{
	LoadLevel(m_currentLevel - 1);
}

bool LevelManager::loadPlayer()
{
    clearPtr(m_playerMechanics);
    for(auto layout : m_layouts){
        ObjectLayout* obj = dynamic_cast< ObjectLayout* >(layout);
        if(obj != nullptr){
            std::shared_ptr<Heroes> ptrPlayer = obj->GetPtrOnHero("HERO2");
            if(ptrPlayer != nullptr){
				m_playerMechanics = new Player(ptrPlayer);
                return true;
            }
        }
    }

    return true;
}

void LevelManager::loadCamera(sf::Vector2f position)
{
	for (auto layout : m_layouts) {
		if (ObjectLayout * obj = dynamic_cast<ObjectLayout*>(layout)) {
			for (auto shape : obj->Shapes()) {
				if (shape->Name() == "CAMERA") {
					m_view.SetLimit(sf::Vector2i(shape->Pos()), sf::Vector2i(shape->Size()));
					m_view.GoTo(position);
				}
			}
		}
	}
}

void LevelManager::Update(const float& deltaTime)
{
	//display(1.f / deltaTime);
	CWindow::GetInstance()->setView(m_view);
	sf::Vector2i pixelMousePos = sf::Mouse::getPosition(*CWindow::GetInstance());
	sf::Vector2f worldMousePos = CWindow::GetInstance()->mapPixelToCoords(pixelMousePos);

    sf::Event* event = EventManager::GetEvent(sf::Event::MouseWheelMoved);
    if(event != nullptr){
        if(event->mouseWheel.delta == 1) m_view.zoom(0.9f);     
        else if(event->mouseWheel.delta == -1 ) m_view.zoom(1.1f);
    }
	
	
	if (m_playerMechanics) m_playerMechanics->Update(worldMousePos, deltaTime);
	for (auto layout : m_layouts) {
		if (ObjectLayout * obj = dynamic_cast<ObjectLayout*>(layout)) {
			obj->Update(worldMousePos, m_view.getCenter(), deltaTime);
		}
	}
	
}

void LevelManager::Draw(sf::RenderWindow& window)
{
	CWindow::GetInstance()->setView(m_view);
	if (m_playerMechanics) m_view.GoTo(m_playerMechanics->GetPosition());

    for(auto layout : m_layouts){
		if (ObjectLayout * obj = dynamic_cast<ObjectLayout*>(layout)) {
			obj->Draw(window, m_view.getCenter());
		}
		else if (TileLayout * tile = dynamic_cast<TileLayout*>(layout)) {
			tile->Draw(window);
		}
    }
}
