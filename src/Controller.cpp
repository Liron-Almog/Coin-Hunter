#include "Controller.h"
#include "GameSound.h"
#include "GameTexture.h"

//The function runs the game
//----------------run-----------------
void Controller::run(sf::RenderWindow & window) {

    unsigned currentStage = FIRST_STAGE;
    window.setFramerateLimit(MAXIMUM_FPS);

      m_map.readMap(true);
      setView(window,WALL_SIZE-5, WALL_SIZE - 5);//moves screen a little
                                                       //bit to right and down
	  handleEvents(window, currentStage);
    
}
//The function handles events and 
//responsible to manages the occurrences
//--------------handleEvents-----------
void Controller::handleEvents(sf::RenderWindow & window, unsigned& currentStage) {

    sf::Clock clock;
    float deltaTime = 0.0f;
    sf::Vector2f direction;
    sf::Event event;

    while (window.isOpen() && m_isPlay)//in game
    {
        deltaTime = clock.restart().asSeconds();
       
        //If a long time has passed
        if (deltaTime > MAXIMUM_DELTA_TIME)
            deltaTime = clock.restart().asSeconds();
       
        direction = getDirection();
        if (STAND != direction) 
            m_map.movePlayer(direction, deltaTime);
          
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
             m_map.shot();               
   
         updateView(window);
         updateGame(window, deltaTime, currentStage);    
    }
}
//The function draws the map, checks collisionand 
// checks occurrences in game
//-------------updateGame-------------
void Controller::updateGame(sf::RenderWindow&  window, const float &deltaTime,
                                                unsigned& currentStage) {

    m_map.drawMap(window, deltaTime);
    m_map.moveUnconrollerPlayer(deltaTime);
    m_map.checkCollistion(window, deltaTime);
    checkOccurrencesInGame(window, currentStage); //checks game status
    
}
//the function handles in pass to next level
//----------------- nextLevel-----------------
 void Controller::nextLevel(sf::RenderWindow& window,unsigned & currentStage) {

    currentStage = m_map.getCurrentLevel();
    m_map.readMap(true);

    if (!m_map.isGameOver()) {
        GameSound::instance().soundEffects(WIN_LEVEL_SOUND);
        drawTransitioScreen(window, NEXT_LEVEL);
    }
}
// The function manages the occurrences of game
//--------------  checkOccurrencesInGame--------------
void Controller::checkOccurrencesInGame(sf::RenderWindow& window, unsigned& currentStage) {

    if (currentStage < m_map.getCurrentLevel()) //next level
        nextLevel(window, currentStage);
       
    if (m_map.isTimeOver()) {//time is over
        drawTransitioScreen(window, TIME_IS_OVER);
        m_map.readMap(false);
    }
    if (m_map.isGameStart()) {//The first round of game
        m_map.setGameStart();
        setView(window, WALL_SIZE -5, WALL_SIZE -5);
    }
    if (m_map.isGameOver()) {//game over
        m_isPlay = false;
        drawTransitioScreen(window, GAME_OVER_BG);
    } 
}
//The function determines the view of screen 
//--------------setView-----------------
void Controller::setView(sf::RenderWindow& window, const int& x, const int& y) {

    auto view = sf::View(sf::FloatRect(x, y, SCREEN_W, SCREEN_H));
    window.setView(view);
   
}
//The function draws transition screen according the number that send to her
//--------------drawGameOver---------------
void Controller::drawTransitioScreen(sf::RenderWindow& window,const int& num) {

    window.clear();
    setView(window, WALL_SIZE - 5, WALL_SIZE - 5);//set view to start
    window.draw(m_transitioScreen[num]);
    window.display();
    std::this_thread::sleep_for(std::chrono::seconds(SHOW_TIME));
}
//The function determines the view screen according to position of player 
//----------------updateView------------------
void Controller::updateView(sf::RenderWindow& window ) {

    sf::Vector2f playerPosition = m_map.getPlayerPosition();

    auto newView = window.getView();


    //if we are at the start of mapand the position of player < center of screen
    if (playerPosition.x - window.getSize().x / 2 < 0) {
        newView.setCenter(window.getSize().x / 2  + WALL_SIZE - 5, newView.getCenter().y);
        m_map.setPositionOfInfo(window.getSize().x / 2 );
    }
    //if we are at the and of the map
    else if ((playerPosition.x + window.getSize().x / 2) > SCREENÉ_LENGHT) {
        newView.setCenter(SCREENÉ_LENGHT - newView.getSize().x / 2 + WALL_SIZE - 5, newView.getCenter().y);
        m_map.setPositionOfInfo(SCREENÉ_LENGHT - newView.getSize().x / 2 );
    }
    else {//if we passed the middle of the screen and we are not ended of map
        newView.setCenter(playerPosition.x + WALL_SIZE - 5, newView.getCenter().y);
        m_map.setPositionOfInfo(playerPosition.x);
    }
    window.setView(newView);
}
//The function returns the direction that chose by user 
//---------------getDirection----------------------
 sf::Vector2f Controller::getDirection() {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return LEFT;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return RIGHT;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return UP;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return DOWN;

        return STAND; 
    }
//---------------Constructor------------
Controller::Controller()
{
    m_transitioScreen[NEXT_LEVEL].setTexture(*GameTexture::instance().getTransitionScreen(NEXT_LEVEL));
    m_transitioScreen[GAME_OVER_BG].setTexture(*GameTexture::instance().getTransitionScreen(GAME_OVER_BG));
    m_transitioScreen[TIME_IS_OVER].setTexture(*GameTexture::instance().getTransitionScreen(TIME_IS_OVER));
    m_transitioScreen[GAME_OVER_BG].move(230, -10);
    m_transitioScreen[NEXT_LEVEL].move(230, -10);
    m_transitioScreen[TIME_IS_OVER].move(230, -10);
 
     m_map.startLevelTime();
  
}
