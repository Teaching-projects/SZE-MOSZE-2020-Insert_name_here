#include "character.h"



Character::Character(const std::string& name, int health, const int& damage) :name(name), health(health), damage(damage) {}
std::string Character::getName() const { return name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }



void Character::reduceHealthByDamage(Character &attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
}






