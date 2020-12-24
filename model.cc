#include "model.h"
#include <iostream>
#include <math.h>

Model::Model(): display{std::make_unique<Display>()}, 
    player{std::make_unique<Player>(sf::Vector2f(500, 500), 1.0 / 30.0)} {}

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
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}


void Model::moveZombies() {
    sf::Vector2f direction; 
    for (auto &i : zombies) {
        direction = normalize(player->getPosition() - i->getPosition());

        i->setPosition(i->getPosition() + (i->getSpeed() * direction));
    }
}

void Model::drawZombies() {
    //moveZombies();
    //std::cout << "drawing" << std::endl;
    for (auto &i: zombies) {
        getDisplay()->getWindow().draw(i->draw());
    }
}
