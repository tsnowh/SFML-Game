#include "display.h"
#include "model.h"

Display::Display(Model *model, unsigned int width, unsigned int height): window(sf::VideoMode(width, height), "SFML-GAME"), healthBar{sf::RectangleShape(sf::Vector2f(healthWidth, healthHeight))}, model{model} {
    healthWidth = width / 2;
    healthHeight = height / 100;
    healthBar.setPosition(sf::Vector2f(width - healthWidth - bufferWidth, bufferHeight));
}

sf::RenderWindow& Display::getWindow() {
    return window;
}

void Display::renderHealthBar() {
    healthBar.setSize(sf::Vector2f(healthWidth + (model->getPlayer()->getHealth() / healthWidth), healthHeight));
    window.draw(healthBar);
}
