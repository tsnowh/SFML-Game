#include "display.h"
#include "model.h"

Display::Display(Model *model, unsigned int width, unsigned int height): window(sf::VideoMode(width, height), "SFML-GAME"), healthBar{sf::RectangleShape(sf::Vector2f(healthWidth, healthHeight))}, model{model} {
    this->healthWidth = width / 2;
    this->healthHeight = height / 100;
    this->healthBar.setPosition(sf::Vector2f(width - healthWidth - bufferWidth, bufferHeight));
    this->healthBar.setFillColor(sf::Color::Red);
    //if (!font.loadFromFile("arial.ttf")) {
        // error...
    //}
    this->killCount.setCharacterSize(24);
    this->killCount.setFillColor(sf::Color::Red);
}

sf::RenderWindow& Display::getWindow() {
    return window;
}

void Display::renderHealthBar() {
    if ((float)model->getPlayer()->getHealth() / (float)model->getPlayer()->getInitialHealth() == 0) {
        healthBar.setSize(sf::Vector2f(0, healthHeight));
    } else {
        healthBar.setSize(sf::Vector2f(healthWidth * ((float)model->getPlayer()->getHealth() / (float)model->getPlayer()->getInitialHealth()), healthHeight));
    }
    window.draw(healthBar);
}

void Display::displayKillCount() {
    //std::string str = "Kill count: " + model->getPlayer()->getKillCount();
    killCount.setString("Kill count: " + model->getPlayer()->getKillCount());
    window.draw(killCount);
}
