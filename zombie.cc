#include "zombie.h"

Zombie::Zombie(int x, int y): Enemy(20, x, y), shape{sf::CircleShape(10)} {
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin (x, y);
    shape.setPosition(x, y);
}

sf::CircleShape Zombie::draw() {
    shape.setPosition(getX(), getY());
    return shape;
}


