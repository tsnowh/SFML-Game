#include "display.h"
#include "model.h"

#include <iostream>

/*
Display::~Display() {
    delete model;
};
*/


Display::Display(Model *model, unsigned int width, unsigned int height): healthHeight{height / 100}, healthWidth{width / 2}, window(sf::VideoMode(width, height), "SFML-GAME"), healthBar{sf::RectangleShape(sf::Vector2f(width / 2, height / 100))}, model{model} {
    //this->healthWidth = width / 2;
    //this->healthHeight = height / 100;
    this->healthBar.setPosition(sf::Vector2f(width - healthWidth - bufferWidth, bufferHeight));
    this->healthBar.setFillColor(sf::Color::Red);
    this->font.loadFromFile("1971.ttf");
    this->killCount.setFont(font);
    this->killCount.setCharacterSize(16);
    this->killCount.setFillColor(sf::Color::Red);
    this->killCount.setPosition(sf::Vector2f(10, 8));
    this->died.setFont(font);
    this->died.setCharacterSize(50);
    this->died.setFillColor(sf::Color::Red);
    this->died.setPosition(sf::Vector2f(100, 200));
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
    //std::cout << model->getPlayer()->getKillCount() << std::endl;
    killCount.setString("Kill count: " + std::to_string(model->getPlayer()->getKillCount()));
    window.draw(killCount);
}

void Display::displayDied() {
    died.setString("YOU DIED");
    window.draw(died);
}
