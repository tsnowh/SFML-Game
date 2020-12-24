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


double Model::distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

sf::Vector2f Model::normalize(const sf::Vector2f& source) {
    float length = sqrt((source.x * source.x) + (source.y * source.y));
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
    for (auto &i : zombies) {
        direction = normalize(player->getPos() - i->getPos());
        velocity = direction * i->getSpeed();

        i->setPos(i->getPos() + velocity);
        i->draw();
    }
}

void Model::drawZombies() {
    //moveZombies();
    //std::cout << "drawing" << std::endl;
    for (auto &i: zombies) {
        getDisplay()->getWindow().draw(i->draw());
    }
}
