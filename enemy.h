#ifndef __ENEMY_H__
#define __ENEMY_H__

enum State {Alive, Dead};

class Weapon;

class Enemy {
  private:
    State state;
    int health;
    int x; 
    int y;
  public:
    Enemy(int h, int x, int y, State = State::Alive);
    virtual void getAttacked (Weapon *);

    // getters / setters
    int getX();
    void setX(int);
    int getY();
    void setY(int);
};


#endif
