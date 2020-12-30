#include "enemy.h"
#include "weapon.h"

Enemy::Enemy(int h, sf::Vector2f pos, float speed, int attackRange, float attackDelay, State state): health{h}, initalHealth{h}, position{pos}, speed{speed}, state{state}, attackRange{attackRange}, attackDelay{attackDelay} {}

void Enemy::getAttacked(Weapon *w, bool reval) {
    health -= w->getDamage();
    if (reval) reEvaluateState();
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

int Enemy::getAttackRange() {
    return attackRange;
}

void Enemy::setAttackRange(int i) {
    attackRange = i;
}

int Enemy::getInitialHealth() {
    return initalHealth;
}

int Enemy::getHealth() {
    return health;
}

void Enemy::setHealth(int i) {
    health = i;
}

State Enemy::getState() {
    return state;
}

void Enemy::setState(State s) {
    state = s;
}

float Enemy::getAttackDelay() {
    return attackDelay;
}

void Enemy::getAttackDelay(float i) {
    attackDelay = i;
}

void Enemy::restartAttackClock() {
    zombieAttack_clock.restart();
}

float Enemy::getAttackTime() {
    return zombieAttack_clock.getElapsedTime().asSeconds();
}

sf::Vector2f Enemy::getPos() {
    return position;
}

void Enemy::setPos(sf::Vector2f i) {
    position = i;
}

float Enemy::getSpeed() {
    return speed;
}

void Enemy::setSpeed(float i) {
    speed = i;
}

void Enemy::reEvaluateState () {
    if (health <= 0) {
        state = State::Dead;
    }
}


