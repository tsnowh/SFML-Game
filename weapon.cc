#include "weapon.h"


Weapon::Weapon(int damage): damage{damage} {}

void Weapon::attack(Enemy *enemy) {
    enemy->getAttacked(this);
}

int Weapon::getDamage() {
    return damage;
}

Projectile::Projectile(sf::Vector2f pos, sf::Vector2f direc, float range, float speed, int damage) :
        Enemy(0, pos, speed, 5), Weapon(damage), shape{sf::CircleShape(5)}, direction{direc}, range{range} {
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

bool Projectile::move() {
    sf::Vector2f velocity;
    velocity = direction * getSpeed();
    distance += getSpeed();
    if (distance >= range) return true;
    setPos(getPos() + velocity);
    draw();
    return false;
}

void Projectile::getAttacked (Weapon *) {}

void Projectile::attack (Enemy *) {}
