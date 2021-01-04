#include "zombie.h"
#include <iostream>

#include "model.h"

Zombie::Zombie(Model *model, sf::Vector2f pos, float speed, int damage, float attackDelay): Enemy(20, pos, speed, 10, attackDelay), weapon{Weapon(damage)}, model{model}, radius{18} {
    //shape.setFillColor(sf::Color::Red);
    //sprite.setTextureRect(sf::IntRect(0, 0, 180, 180));
    setTex("corona_cell.png");

    //getSprite()->setTexture(getTexture());
    getSprite()->setScale(sf::Vector2f(0.2f, 0.2f));
    getSprite()->setOrigin(sf::Vector2f(getSprite()->getLocalBounds().width / 2, getSprite()->getLocalBounds().height / 2));
    this->setPos(pos);
    getSprite()->setPosition(pos);
}

/*
sf::Sprite Zombie::draw() {
    sprite.setPosition(getPos());
    return sprite;
}
*/

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

/*
sf::Sprite Zombie::getSprite() {
    return sprite;
}
*/
