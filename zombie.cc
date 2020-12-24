#include "zombie.h"

Zombie::Zombie(sf::Vector2f pos, float speed): Enemy(20, pos, speed), shape{sf::CircleShape(10)} {
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
}

sf::CircleShape Zombie::draw() {
    shape.setPosition(getPos());
    return shape;
}


