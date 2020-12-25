#include "weapon.h"


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
        Enemy(0, pos, speed, 5), Weapon(damage, owner), shape{sf::CircleShape(5)}, direction{direc}, range{range} {
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

void Projectile::move() {
    if (this == nullptr) throw;
    sf::Vector2f velocity;
    velocity = direction * getSpeed();
    distance += getSpeed();
    if (distance >= range) getOwner()->notify(this);
    setPos(getPos() + velocity);
    draw();
}

void Projectile::getAttacked (Weapon *) {}

void Projectile::attack (Enemy *) {}

void Projectile::notify (Projectile *) {}
