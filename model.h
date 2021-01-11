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
    int width;
    int height;
    int waveNum = 0;
  public:
    Model(int width = 500, int height = 500, float playerSpeed = 0.5);
    Display * getDisplay();
    Player * getPlayer();

    int getWidth();
    int getHeight();

    int getWaveNum();
    void setWaveNum(int);

    //Zombie methods
    void addZombie(std::unique_ptr<Zombie>);
    void removeZombie(Zombie *);
    int getNumZombie();
    void moveZombies();
    void drawZombies();
    void drawProjectiles();
};

#endif
