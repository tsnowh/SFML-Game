#include "weapon.h"
#include <iostream>
#include <cmath>
#include "physics.h"


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
        Enemy(1, pos, speed, 5, 0), Weapon(damage, owner), direction{direc}, range{range}, radius{5} {
    
    /*
    sprite.setRadius(5);
    sprite.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    sprite.setPosition(pos);
    sprite.setFillColor(sf::Color::White);
    */

    this->ptex.loadFromFile("bullet.png");

    this->sprite.setTexture(ptex);
    //this->spriteRec = sf::IntRect(0, 0, 13, 16);
    //this->sprite.setTextureRect(spriteRec);
    this->sprite.setScale(sf::Vector2f(1.5f, 1.5f));
    this->sprite.setOrigin (sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
    this->sprite.setPosition(pos);

    if (direc.x >= 0.0f) {
        this->sprite.rotate(getAngle(sf::Vector2f(0.0, -1.0), direc));
    } else {
        this->sprite.rotate( -1 * getAngle(sf::Vector2f(0.0, -1.0), direc));
    }
}

sf::Sprite Projectile::draw() {
    sprite.setPosition(getPos());
    return sprite;
}

float Projectile::getRadius() {
    return radius;
}

void Projectile::move(int width, int height) {
    if (this == nullptr) throw;
    sf::Vector2f velocity;
    sf::Vector2f newPos;
    velocity = direction * getSpeed();
    distance += getSpeed();
    if (distance >= range) getOwner()->notify(this);

    newPos = getPos() + velocity;

    if (newPos.y <= 0.0) {
        newPos.y = (float)height;
    } else if (newPos.y >= (float)height) {
        newPos.y = 0.0;
    }

    if (newPos.x <= 0.0) {
        newPos.x = (float)width;
    } else if (newPos.x >= (float)width) {
        newPos.x = 0.0;
    }
    
    setPos(newPos);
    draw();
}

void Projectile::getAttacked (Weapon *w, bool reval) {
    setHealth(getHealth() - w->getDamage());

    if (reval) reEvaluateState();
}

void Projectile::attack (Enemy *e, bool reval) {
    e->getAttacked(this, reval);
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

sf::Sprite Projectile::getSprite() {
    return sprite;
}
