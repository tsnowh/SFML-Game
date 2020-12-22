#include "player.h"

// hard coded position for now
Player::Player(int x, int y): Enemy(100, x, y), shape{sf::CircleShape(20)} {
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin (x, y);
    shape.setPosition(x, y);
}

/*
void Player::getAttacked (Weapon *) {

}
*/

sf::CircleShape Player::draw() {
    shape.setPosition(getX(), getY());
    return shape;
}
