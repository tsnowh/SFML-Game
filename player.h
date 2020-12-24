#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Weapon;

class Player: public Enemy {
  private:
    sf::CircleShape shape;
  public:
    Player(sf::Vector2f pos, float speed);
    void getAttacked (Weapon *) override;
    void attack (Enemy *) override;
    void reEvaluateState () override;

    float getRadius();

    sf::CircleShape draw();
};


#endif
