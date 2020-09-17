#include "character.h"


Character::Character(std::string name, int health, int damage) :name(name), health(health), damage(damage) {}
std::string Character::getName() const { return name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }



void Character::healthLoss(int damage) {
	health -= damage;
	if (health < 0) { health = 0; }

}






