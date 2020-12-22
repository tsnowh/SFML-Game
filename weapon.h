#ifndef __WEAPON_H__
#define __WEAPON_H__

class Enemy;

class Weapon {
  private:
    int damage;
  public:
    Weapon(int damage);
    virtual void attack (Enemy *);
    int getDamage();
};


#endif
