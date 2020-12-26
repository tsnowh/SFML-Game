#include "model.h"
#include <iostream>
#include "physics.h"

Model::Model(int width, int height, float playerSpeed): display{std::make_unique<Display>(width, height)}, 
    player{std::make_unique<Player>(this, sf::Vector2f(width / 2, height / 2), playerSpeed)}, width{width}, height{height} {}

Display * Model::getDisplay() {
    return display.get();
}

Player * Model::getPlayer() {
    return player.get();
}

int Model::getWidth() {
    return width;
}

int Model::getHeight() {
    return height;
}

void Model::addZombie(Zombie *z) {
    zombies.emplace_back(std::unique_ptr<Zombie>(z));
    //std::cout << "added zombie " << zombies.size() << std::endl;
}

void Model::removeZombie(Zombie *z) {
    auto it = std::find_if(zombies.begin(), zombies.end(), 
        [z](const std::unique_ptr<Zombie> & n) { return n.get() == z; });

    if (it != zombies.end()) {
        int i = zombies.end() - it;
        zombies.erase(it);
    }
}

void Model::moveZombies() {
    float move_x = 0;
    float move_y = 0;
    sf::Vector2f direction;
    sf::Vector2f velocity;
    sf::Vector2f vec;  
    sf::Vector2f newPos;
    for (auto &i : zombies) {
        vec = player->getPos() - i->getPos();
        direction = normalize(vec);
        velocity = direction * i->getSpeed();
        newPos = i->getPos() + velocity;

        if (newPos.y <= 0) {
            newPos.y = height;
        }

        if (newPos.y >= height) {
            newPos.y = 0;
        }

        if (newPos.x <= 0) {
            newPos.x = width;
        }

        if (newPos.x >= width) {
            newPos.x = 0;
        }

        i->setPos(newPos);
        i->draw();
        if (distance(vec) <= (float)i->getRadius() + player->getRadius()) {
            i->attack(player.get());
        }
    }
}

void Model::drawZombies() {
    //moveZombies();
    //std::cout << "drawing" << std::endl;
    for (auto &i: zombies) {
        getDisplay()->getWindow().draw(i->draw());
    }
}

void Model::drawProjectiles() {
    //try{
        for (int i = 0; i < player->getNumProjectiles(); ++i) {
            getDisplay()->getWindow().draw(player->getProjectile(i)->draw());
        }
    //} catch ( ... ) {

    //}
}
