#include "zombie.h"
#include <iostream>

#include "model.h"

/*
Zombie::~Zombie() {
    delete model;
}
*/

Zombie::Zombie(Model *model, sf::Vector2f pos, float speed, int damage, float attackDelay): Enemy(20, pos, speed, 10, attackDelay), weapon{Weapon(damage)}, model{model}, radius{18} {
    //shape.setFillColor(sf::Color::Red);
    //sprite.setTextureRect(sf::IntRect(0, 0, 180, 180));
    setTex("zombie.png");

    // down frames
    frames_down.emplace_back(sf::IntRect(1, 1, 13, 15));
    frames_down.emplace_back(sf::IntRect(16, 1, 13, 15));
    frames_down.emplace_back(sf::IntRect(32, 1, 13, 15));

    // left frames
    frames_left.emplace_back(sf::IntRect(1, 17, 13, 15));
    frames_left.emplace_back(sf::IntRect(16, 17, 13, 15));
    frames_left.emplace_back(sf::IntRect(32, 17, 13, 15));

    // right frames
    frames_right.emplace_back(sf::IntRect(1, 33, 13, 15));
    frames_right.emplace_back(sf::IntRect(16, 33, 13, 15));
    frames_right.emplace_back(sf::IntRect(32, 33, 13, 15));

    // up frames
    frames_up.emplace_back(sf::IntRect(1, 49, 13, 15));
    frames_up.emplace_back(sf::IntRect(16, 49, 13, 15));
    frames_up.emplace_back(sf::IntRect(32, 49, 13, 15));

    this->maxFrame = 2;

    setSRec(sf::IntRect(1, 1, 13, 15));

    //getSprite()->setTexture(getTexture());
    getSprite()->setScale(sf::Vector2f(3.0f, 3.0f));
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

void Zombie::nextFrame() {
    //std::cout << getDirec().x << " " << getDirec().y << std::endl;
    if (getDirec().y > 0.0f) { //down
        if (framePosUp) {
            framePos++;
            if (framePos == maxFrame) {
                framePosUp = false;
            }
        } else {
            framePos--;
            if (framePos == 0) {
                framePosUp = true;
            }
        }
        setSRec(frames_down.at(framePos));
    } else if (getDirec().y < 0.0f) { //up
        if (framePosUp) {
            framePos++;
            if (framePos == maxFrame) {
                framePosUp = false;
            }
        } else {
            framePos--;
            if (framePos == 0) {
                framePosUp = true;
            }
        }
        setSRec(frames_up.at(framePos));
    } else if (getDirec().x > 0.0f) { //right
        if (framePosUp) {
            framePos++;
            if (framePos == maxFrame) {
                framePosUp = false;
            }
        } else {
            framePos--;
            if (framePos == 0) {
                framePosUp = true;
            }
        }
        setSRec(frames_right.at(framePos));
    } else if (getDirec().x < 0.0f) { //left
        if (framePosUp) {
            framePos++;
            if (framePos == maxFrame) {
                framePosUp = false;
            }
        } else {
            framePos--;
            if (framePos == 0) {
                framePosUp = true;
            }
        }
        setSRec(frames_left.at(framePos));
    }
}
