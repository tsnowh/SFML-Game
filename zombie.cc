#include "zombie.h"
#include <iostream>

#include "model.h"

Zombie::Zombie(Model *model, sf::Sprite spr, sf::Vector2f pos, float speed, int damage, float attackDelay): Enemy(20, pos, speed, 10, attackDelay), weapon{Weapon(damage)}, model{model}, radius{18}, sprite{spr} {
    //shape.setFillColor(sf::Color::Red);
    //sprite.setTextureRect(sf::IntRect(0, 0, 180, 180));
    sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    sprite.setOrigin (sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
    this->setPos(pos);
    sprite.setPosition(pos);
}

sf::Sprite Zombie::draw() {
    sprite.setPosition(getPos());
    return sprite;
}

void Zombie::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }

    if (getState() == State::Dead) {
        model->removeZombie(this);
    }
}

void Zombie::getAttacked (Weapon *w, bool reval) {
    setHealth(getHealth() - w->getDamage());
    
    if (reval) reEvaluateState();
}

void Zombie::notify (Projectile *) {}

void Zombie::attack (Enemy *e, bool reval) {
    e->getAttacked(&weapon, reval);
    restartAttackClock();
}

float Zombie::getRadius() {
    return radius;
}
