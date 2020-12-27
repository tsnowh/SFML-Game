#include "zombie.h"
#include <iostream>

#include "model.h"

Zombie::Zombie(Model *model, sf::Vector2f pos, float speed, int damage): Enemy(20, pos, speed, 10), shape{sf::CircleShape(10)}, weapon{Weapon(damage)}, model{model} {
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

    if (getState() == State::Dead) {
        model->removeZombie(this);
    }
}

void Zombie::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    //std::cout << "OUCH zombie-projectile collision detected" << getHealth() << std::endl; 
    reEvaluateState();
}

void Zombie::notify (Projectile *) {}

void Zombie::attack (Enemy *e) {
    e->getAttacked(&weapon);
}

float Zombie::getRadius() {
    return shape.getRadius();
}
