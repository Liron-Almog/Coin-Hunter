#include "Const.h"
#include "Menu.h"
#include "Map.h"
class Controller
{
public:

	Controller();
	~Controller() = default;
	void nextLevel(sf::RenderWindow&, unsigned& );
	string g(sf::RenderWindow& window);
	void updateGame(sf::RenderWindow& window, const float& , unsigned& );
	void run(sf::RenderWindow& window);
	void drawTransitioScreen(sf::RenderWindow& , const int&);
	void handleEvents(sf::RenderWindow&  , unsigned& currentStage);
	sf::Vector2f getDirection();
	void updateView(sf::RenderWindow& window);
	void checkOccurrencesInGame(sf::RenderWindow& window, unsigned& );
	void setView(sf::RenderWindow& window, const int& x, const int& y);

private:
	
	sf::Sprite m_transitioScreen[TRANSITION_SCREENS-2];
	Map m_map;
	bool m_isPlay = true;
};
