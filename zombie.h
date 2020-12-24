#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include "weapon.h"

class Zombie: public Enemy {
  private:
    sf::CircleShape shape;
    Weapon weapon;
  public:
    Zombie(sf::Vector2f pos, float speed, int damage);
    void getAttacked (Weapon *) override;
    void attack (Enemy *) override;
    void reEvaluateState () override;
    float getRadius();

    sf::CircleShape draw();
};


#endif
