#include "weapon.h"
#include <iostream>


Weapon::Weapon(int damage, Enemy * owner): damage{damage}, owner{owner} {}

Weapon::Weapon(int damage): damage{damage} {}

void Weapon::attack(Enemy *enemy) {
    enemy->getAttacked(this);
}

int Weapon::getDamage() {
    return damage;
}

Enemy * Weapon::getOwner() {
    return owner;
}

Projectile::Projectile(Enemy * owner, sf::Vector2f pos, sf::Vector2f direc, float range, float speed, int damage) :
        Enemy(1, pos, speed, 5), Weapon(damage, owner), shape{sf::CircleShape(5)}, direction{direc}, range{range} {
    shape.setRadius(5);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::White);
}

sf::CircleShape Projectile::draw() {
    shape.setPosition(getPos());
    return shape;
}

float Projectile::getRadius() {
    return shape.getRadius();
}

void Projectile::move(int width, int height) {
    if (this == nullptr) throw;
    sf::Vector2f velocity;
    sf::Vector2f newPos;
    velocity = direction * getSpeed();
    distance += getSpeed();
    if (distance >= range) getOwner()->notify(this);

    newPos = getPos() + velocity;

    if (newPos.y <= 0) {
        newPos.y = height;
    }

    if (newPos.y >= height) {
        newPos.y = 0;
    }

    if (newPos.x <= 0) {
        newPos.x = width;
    }

    if (newPos.x >= width) {
        newPos.x = 0;
    }
    
    setPos(newPos);
    draw();
}

void Projectile::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    //std::cout << "OUCH projectile-zombie collision detected" << getHealth() << std::endl; 
    reEvaluateState();
}

void Projectile::getAttacked (Weapon *w, bool reval) {
    setHealth(getHealth() - w->getDamage());

    if (reval) reEvaluateState();
}

void Projectile::attack (Enemy *e) {
    e->getAttacked(this);
}

void Projectile::notify (Projectile *) {

}

void Projectile::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }

    if (getState() == State::Dead) {
        getOwner()->notify(this);
    }
}
