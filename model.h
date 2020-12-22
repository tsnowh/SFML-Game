#ifndef __MODEL_H__
#define __MODEL_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "display.h"
#include "player.h"
#include "zombie.h"

class Model {
  private:
    std::unique_ptr<Display> display;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Zombie>> zombies;

    //helper methods
    //double distance(int, int, int, int);
  public:
    Model();
    Display * getDisplay();
    Player * getPlayer();

    //Zombie methods
    void addZombie(Zombie *);
    void removeZombie(Zombie *);
    void moveZombies();
    void drawZombies();

};

#endif
