#include "player.h"
#include "weapon.h"
#include <iostream>
#include "physics.h"
#include "model.h"

/*
Player::~Player() {
    delete model;
}
*/

// hard coded position for now
Player::Player(Model *model, sf::Vector2f pos, float speed): Enemy(100, pos, speed, 500, 0.3), model{model}, radius{20} {
    //shape.setOrigin ({shape.getRadius(), shape.getRadius()});

    setTex("player.png");

    //getSprite()->setTexture(getTexture());

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
    getSprite()->setTextureRect(getSRec());
    getSprite()->setScale(sf::Vector2f(3.0f, 3.0f));
    getSprite()->setOrigin (sf::Vector2f(getSprite()->getLocalBounds().width / 2, getSprite()->getLocalBounds().height / 2));
    getSprite()->setPosition(pos);
}

void Player::getAttacked (Weapon *w, bool reval) {
    setHealth(getHealth() - w->getDamage());
   
    if (reval) reEvaluateState();
}

void Player::attack (Enemy *e, bool reval) {}

void Player::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }
}

/*
sf::Sprite Player::draw() {
    sprite.setPosition(getPos());
    return sprite;
}
*/

float Player::getRadius() {
    return radius;
}

void Player::addProjectile(std::unique_ptr<Projectile> p) {
    //std::unique_ptr<Projectile> z;
    //z = std::make_unique<Projectile>(getPos(), normalize(getPos()), 100.0, 1.0, 20);
    if (p) projectiles.push_back(std::move(p));
}

void Player::deleteProjectile(Projectile *w) {
    auto it = std::find_if(projectiles.begin(), projectiles.end(), 
        [w](const std::unique_ptr<Projectile> & n) { return n.get() == w; });

    if (it != projectiles.end()) {
        //int i = projectiles.end() - it;
        //std::cout << projectiles.size() << " size before delete" << std::endl;
        projectiles.erase(it);
        //std::cout << projectiles.size() << " size after delete" << std::endl;
    }
}

Projectile * Player::getProjectile(int i) {
    if (i > projectiles.size()) throw std::exception{};
    return projectiles.at(i).get();
}

int Player::getNumProjectiles() {
    return projectiles.size();
}


void Player::shoot(sf::Vector2f mpos) {
    //std::cout << mpos.x << " " << mpos.y << std::endl; 
    addProjectile(std::move(std::make_unique<Projectile>(this, getPos(), normalize(mpos - getPos()), 450.0, 2.0, 20)));
    restartAttackClock();
}

void Player::moveProjectiles() {
    if (projectiles.size() == 0) return;
    for (auto &i : projectiles) {
        if (i) i->move(model->getWidth(), model->getHeight());
    }
}

void Player::notify (Projectile * w) {
    deleteProjectile(w);
}

int Player::getKillCount() {
    return killCount;
}

void Player::increaseKillCount() {
    killCount++;
}

void Player::resetKillCount() {
    killCount = 0;
}

/*
sf::Sprite * Player::getSprite() {
    return sprite;
}
*/

void Player::nextFrame() {
    if (getDirec() == sf::Vector2f(0, 1)) { //down
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
    } else if (getDirec() == sf::Vector2f(0, -1)) { //up
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
    } else if (getDirec() == sf::Vector2f(1, 0)) { //right
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
    } else if (getDirec() == sf::Vector2f(-1, 0)) { //left
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
