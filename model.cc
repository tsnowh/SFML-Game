#include "model.h"

Model::Model(): display{std::make_unique<Display>()}, 
    player{std::make_unique<Player>(250, 250)} {}

Display * Model::getDisplay() {
    return display.get();
}

Player * Model::getPlayer(){
    return player.get();
}

