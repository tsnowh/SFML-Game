#include "zombie.h"

Zombie::Zombie(sf::Vector2f pos, float speed, int damage): Enemy(20, pos, speed, 10), shape{sf::CircleShape(10)}, weapon{Weapon(damage)} {
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
}

sf::CircleShape Zombie::draw() {
    shape.setPosition(getPos());
    return shape;
}

void Zombie::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }
}

void Zombie::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    reEvaluateState();
}


void Zombie::attack (Enemy *e) {
    e->getAttacked(&weapon);
}

float Zombie::getRadius() {
    return shape.getRadius();
}
