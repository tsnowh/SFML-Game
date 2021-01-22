#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>

enum State {Alive, Dead};

class Weapon;
class Projectile;

class Enemy {
  private:
    State state;
    int health;
    int initalHealth;
    sf::Vector2f position;
    sf::Vector2f direc;
    float speed;
    int attackRange;
    float attackDelay;
    sf::Clock attack_clock;
    sf::Clock animation_clock;

    sf::Texture ptex;
    sf::IntRect spriteRec;
    sf::Sprite sprite;
  public:
    Enemy(int h, sf::Vector2f pos, float speed, int attackRange, float attackDelay, State = State::Alive);
    virtual void getAttacked (Weapon *, bool = true) = 0;
    virtual void attack (Enemy *, bool = true) = 0;
    virtual void notify (Projectile *) = 0;
    virtual float getRadius() = 0;
    virtual void reEvaluateState ();

    sf::Sprite * getSprite();
    void setTex (std::string);
    sf::Texture getTexture ();
    void setSRec(sf::IntRect);
    sf::IntRect getSRec();

    virtual sf::Sprite draw();

    // getters / setters
    int getX();
    void setX(int);
    int getY();
    void setY(int);

    int getAttackRange();
    void setAttackRange(int);

    int getInitialHealth();
    int getHealth();
    void setHealth(int);
    State getState();
    void setState(State);

    float getAttackDelay();
    void getAttackDelay(float);

    void restartAttackClock();
    float getAttackTime();

    void restartAnimateClock();
    float getAnimateTime();

    sf::Vector2f getPos();
    void setPos(sf::Vector2f);

    sf::Vector2f getDirec();
    void setDirec(sf::Vector2f);

    float getSpeed();
    void setSpeed(float);
};


#endif
