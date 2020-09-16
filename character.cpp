#include <iostream>
#include "character.h"


Character::Character(std::string name, int health, int damage) :name(name), health(health), damage(damage) {}
std::string Character::getname() { return name; }
int Character::getdamage() { return damage; }
int Character::gethealth() { return health; }



void Character::healthloss(int damage) {
	health -= damage;
	if (health < 0) { health = 0; }

}






