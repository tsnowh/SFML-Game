#include "player.h"

// hard coded position for now
Player::Player(sf::Vector2f pos, float speed): Enemy(100, pos, speed), shape{sf::CircleShape(20)} {
    shape.setRadius(20);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Green);
}

/*
void Player::getAttacked (Weapon *) {

}
*/

sf::CircleShape Player::draw() {
    shape.setPosition(getPos());
    return shape;
}
