#include "player.h"
#include "weapon.h"
#include <iostream>

// hard coded position for now
Player::Player(sf::Vector2f pos, float speed): Enemy(100, pos, speed, 500), shape{sf::CircleShape(20)} {
    shape.setRadius(20);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Green);
}

void Player::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    std::cout << "OUCH " << getHealth() << std::endl; 
    reEvaluateState();
}

void Player::attack (Enemy *e) {
        
}

void Player::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }
}

sf::CircleShape Player::draw() {
    shape.setPosition(getPos());
    return shape;
}

float Player::getRadius() {
    return shape.getRadius();
}
