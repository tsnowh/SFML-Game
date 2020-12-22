#include "display.h"

Display::Display(unsigned int width, unsigned int height): window(sf::VideoMode(width, height), "SFML-GAME") {}

sf::RenderWindow& Display::getWindow() {
    return window;
}
