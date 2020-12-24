#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Weapon;
class Projectile;

class Player: public Enemy {
  private:
    sf::CircleShape shape;
    std::vector<std::unique_ptr<Projectile>> projectiles;
  public:
    Player(sf::Vector2f pos, float speed);
    void getAttacked (Weapon *) override;
    void attack (Enemy *) override;
    void reEvaluateState () override;
    float getRadius();

    void addProjectile(Projectile *);
    void deleteProjectile(Projectile *);
    Projectile * getProjectile(int i);
    int getNumProjectiles();
    void shoot();
    void moveProjectiles();

    sf::CircleShape draw();
};


#endif
