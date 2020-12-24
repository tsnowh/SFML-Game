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


void Model::moveZombies() {
    int move_x = 0;
    int move_y = 0;
    double scale; 
    for (auto &i : zombies) {
        move_x = 0;
        move_y = 0;
        //move_x = player->getX() - i->getX();
        //move_y = player->getY() - i->getY();
        //scale = 1 / distance(i->getX(), i->getY(), player->getX(), player->getY());
        
        if (player->getX() > i->getX()) {
            i->setX(i->getX() + 1);
        } else if (player->getX() < i->getX()) {
            i->setX(i->getX() - 1);
        }

        if (player->getY() > i->getY()) {
            i->setY(i->getY() + 1);
        } else if (player->getY() < i->getY()) {
            i->setY(i->getY() - 1);
        }
        i->draw();
        //std::cout << distance(i->getX(), i->getY(), player->getX(), player->getY()) << std::endl;
    }
}

void Model::drawZombies() {
    moveZombies();
    //std::cout << "drawing" << std::endl;
    for (auto &i: zombies) {
        getDisplay()->getWindow().draw(i->draw());
    }
}
