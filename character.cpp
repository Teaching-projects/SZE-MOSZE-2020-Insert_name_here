#include "character.h"



Character::Character(std::string name, int health, int damage) :name(name), health(health), damage(damage) {}
const std::string& Character::getName() const { return  name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }



void Character::reduceHealthByDamage(const Character &attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
}






