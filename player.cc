#include "player.h"
#include "weapon.h"
#include <iostream>
#include "physics.h"
#include "model.h"

// hard coded position for now
Player::Player(Model *model, sf::Vector2f pos, float speed): Enemy(100, pos, speed, 500), shape{sf::CircleShape(20)}, model{model} {
    shape.setRadius(20);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Green);
}

void Player::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    //std::cout << "OUCH player-zombie collision detected" << getHealth() << std::endl; 
    reEvaluateState();
}

void Player::attack (Enemy *e) {}

void Player::reEvaluateState () {
    if (getHealth() <= 0) {
        setState(State::Dead);
    }
}

sf::CircleShape Player::draw() {
    shape.setPosition(getPos());
    return shape;
}

float Player::getRadius() {
    return shape.getRadius();
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
        std::cout << projectiles.size() << " size before delete" << std::endl;
        projectiles.erase(it);
        std::cout << projectiles.size() << " size after delete" << std::endl;
    }
}

Projectile * Player::getProjectile(int i) {
    //if (i >= projectiles.size()) throw;
    return projectiles.at(i).get();
}

int Player::getNumProjectiles() {
    return projectiles.size();
}


void Player::shoot() {
    addProjectile(std::move(std::make_unique<Projectile>(this, getPos(), normalize(getPos()), 250.0, 1.0, 20)));
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

