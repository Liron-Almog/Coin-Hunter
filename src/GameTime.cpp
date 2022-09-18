#include "GameTime.h"
#include "GameFont.h"
#include <chrono>
#include <thread>
#include "GameTexture.h"
#include "GameSound.h"
#include "Const.h"
#include "GameFont.h"

//--------------Constructor------------------
GameTime::GameTime() {
    //set  txt
    m_infoTime.setFont(GameFont::instance().getFont(FONTINFO_FONT));
    m_infoTime.setColor(sf::Color::White);
    m_infoTime.setCharacterSize(35);
    m_infoTime.setString("Time:");
    m_infoTime.setPosition(POS_TIME_BAR);

    m_textTime.setFont(GameFont::instance().getFont(DIGITAL_FONT));
    m_textTime.setCharacterSize(40);
    m_textTime.setColor(sf::Color::White);
    m_textTime.setPosition(TEXT_POS_TIME);
}

//The function Initializes the clock
//----------------startTime------------------
void GameTime::startTime(const int & level) {
    
    m_totalTime = MAXIMUM_TIME + (level) * (DECREASE_TIME) ;//set time according to stage 
    m_gameTime.restart();

}
//----------------getTime----------------
int GameTime::getTime() const {
    
    return m_totalTime - (int)m_gameTime.getElapsedTime().asSeconds();

}
//----------------drawTime----------------
void GameTime::drawTime(sf::RenderWindow& window) {
    
    updateTime();
    window.draw(m_textTime);
    window.draw(m_infoTime);
   
}

//----------------updateTime----------------
void GameTime::updateTime() {

    m_textTime.setString(std::to_string(getTime()));
}

//----------------setTimePosition----------------
void GameTime::setTimePosition(float x) {

    m_infoTime.setPosition(POS_TIME_BAR.x + x, POS_TIME_BAR.y);
    m_textTime.setPosition(TEXT_POS_TIME.x + x, TEXT_POS_TIME.y);
}
//----------------resetPosition----------------
void GameTime::resetPosition() {

    m_textTime.setPosition(TEXT_POS_TIME);
    m_infoTime.setPosition(POS_TIME_BAR);
}