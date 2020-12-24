#include "model.h"
#include <iostream>
#include <math.h>

Model::Model(): display{std::make_unique<Display>()}, 
    player{std::make_unique<Player>(sf::Vector2f(250, 250), 1.0)} {}

Display * Model::getDisplay() {
    return display.get();
}

Player * Model::getPlayer() {
    return player.get();
}

void Model::addZombie(Zombie *z) {
    zombies.emplace_back(std::unique_ptr<Zombie>(z));
    std::cout << "added zombie " << zombies.size() << std::endl;
}

void Model::removeZombie(Zombie *z) {
    auto it = std::find_if(zombies.begin(), zombies.end(), 
        [z](const std::unique_ptr<Zombie> & n) { return n.get() == z; });

    if (it != zombies.end()) {
        int i = zombies.end() - it;
        zombies.erase(it);
    }
}


float Model::distance(const sf::Vector2f& source) {
    return sqrt((source.x * source.x) + (source.y * source.y));
}

sf::Vector2f Model::normalize(const sf::Vector2f& source) {
    float length = distance(source);
    if (length != 0) {
        //std::cout << length << std::endl;
        return sf::Vector2f(source.x / length, source.y / length);
    } else {
        return source;
    }
}


void Model::moveZombies() {
    float move_x = 0;
    float move_y = 0;
    sf::Vector2f direction;
    sf::Vector2f velocity;
    sf::Vector2f vec;  
    for (auto &i : zombies) {
        vec = player->getPos() - i->getPos();
        direction = normalize(vec);
        velocity = direction * i->getSpeed();

        i->setPos(i->getPos() + velocity);
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
