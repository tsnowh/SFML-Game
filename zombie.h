#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Zombie: public Enemy {
  private:
    sf::CircleShape shape;
  public:
    Zombie(sf::Vector2f pos, float speed);
    //void getAttacked (Weapon *) override;

    sf::CircleShape draw();
};


#endif
