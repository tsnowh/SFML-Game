#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <SFML/Graphics.hpp>

#include "enemy.h"

class Weapon {
  private:
    int damage;
    Enemy * owner;
  public:
    Weapon(int damage, Enemy *);
    Weapon(int damage);
    virtual void attack (Enemy *);
    int getDamage();
    Enemy * getOwner();
};


class Projectile: public Weapon, public Enemy {
  private:
    sf::CircleShape shape;
    sf::Vector2f direction;
    float distance = 0;
    float range;
  public:
    Projectile(Enemy * owner, sf::Vector2f pos, sf::Vector2f direc, float range, float speed = 1.0, int damage = 0);
    sf::CircleShape draw();
    void move(int maxW, int maxH);
    void getAttacked (Weapon *) override;
    void attack (Enemy *) override;
    void notify (Projectile *) override;
};


#endif
