#include "weapon.h"
#include "enemy.h"

Weapon::Weapon(int damage): damage{damage} {}

void Weapon::attack(Enemy *enemy) {
    enemy->getAttacked(this);
}

int Weapon::getDamage() {
    return damage;
}
