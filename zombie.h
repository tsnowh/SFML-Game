#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Zombie: public Enemy {
  private:
    sf::CircleShape shape;
  public:
    Zombie(int x, int y);
    //void getAttacked (Weapon *) override;

    sf::CircleShape draw();
};


#endif
