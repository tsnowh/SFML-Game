#include "enemy.h"
#include "weapon.h"

Enemy::Enemy(int health, int x, int y, State state): health{health}, x{x}, y{y}, state{state} {}

void Enemy::getAttacked(Weapon *w) {
    health -= w->getDamage();
}

int Enemy::getX() {
    return x;
}

void Enemy::setX(int i) {
    x = i;
}

int Enemy::getY() {
    return y;
}

void Enemy::setY(int i) {
    y = i;
}


