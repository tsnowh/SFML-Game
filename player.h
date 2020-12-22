#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Player: public Enemy {
  private:
    sf::CircleShape shape;
  public:
    Player(int x, int y);
    //void getAttacked (Weapon *) override;

    sf::CircleShape draw();
};


#endif
