#include "player.h"
#include "weapon.h"
#include <iostream>
#include "physics.h"

// hard coded position for now
Player::Player(sf::Vector2f pos, float speed): Enemy(100, pos, speed, 500), shape{sf::CircleShape(20)} {
    shape.setRadius(20);
    shape.setOrigin ({shape.getRadius(), shape.getRadius()});
    this->setPos(pos);
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Green);
}

void Player::getAttacked (Weapon *w) {
    setHealth(getHealth() - w->getDamage());
    std::cout << "OUCH " << getHealth() << std::endl; 
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

void Player::addProjectile(Projectile *w) {
    projectiles.emplace_back(std::unique_ptr<Projectile>(w));
}

void Player::deleteProjectile(Projectile *w) {
    auto it = std::find_if(projectiles.begin(), projectiles.end(), 
        [w](const std::unique_ptr<Projectile> & n) { return n.get() == w; });

    if (it != projectiles.end()) {
        //int i = projectiles.end() - it;
        projectiles.erase(it);
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
    std::unique_ptr<Projectile> z;
    z = std::make_unique<Projectile>(getPos(), normalize(getPos()), 100.0, 3.0, 20);
    addProjectile(z.get());
}

void Player::moveProjectiles() {
    for (auto &i : projectiles) {
        bool del = i->move();
        if(!del) {

        } else {
            //int pos = projectiles.end() - i;
            deleteProjectile(i.get());
        }
    }
}


