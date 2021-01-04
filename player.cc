#include "player.h"
#include "weapon.h"
#include <iostream>
#include "physics.h"
#include "model.h"

// hard coded position for now
Player::Player(Model *model, sf::Vector2f pos, float speed): Enemy(100, pos, speed, 500, 0.3), model{model}, radius{20} {
    //shape.setOrigin ({shape.getRadius(), shape.getRadius()});

    this->ptex.loadFromFile("player.png");

    this->sprite.setTexture(ptex);
    this->spriteRec = sf::IntRect(1, 1, 13, 16);
    this->sprite.setTextureRect(spriteRec);
    this->sprite.setScale(sf::Vector2f(3.0f, 3.0f));
    this->sprite.setOrigin (sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
    this->sprite.setPosition(pos);
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

sf::Sprite Player::draw() {
    sprite.setPosition(getPos());
    return sprite;
}

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

sf::Sprite Player::getSprite() {
    return sprite;
}
