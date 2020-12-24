#include "enemy.h"
#include "weapon.h"

Enemy::Enemy(int h, sf::Vector2f pos, float speed, State state): health{h}, position{pos}, speed{speed}, state{state} {}

void Enemy::getAttacked(Weapon *w) {
    health -= w->getDamage();
}

int Enemy::getX() {
    return position.x;
}

void Enemy::setX(int i) {
    position.x = i;
}

int Enemy::getY() {
    return position.y;
}

void Enemy::setY(int i) {
    position.y = i;
}

sf::Vector2f Enemy::getPosition() {
    return position;
}

void Enemy::setPosition(sf::Vector2f i) {
    position = i;
}


