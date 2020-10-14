#include "player.h"
#include <cmath>


Player::Player(const std::string& name, double health, double damage) :Character(name, health, damage) {};

void Player::gainXP() {
	xp += this->getDamage();
	while (xp >= 100) {
		this->lvlUp();
	}
};

void Player::lvlUp() {
	maxhealth = round(maxhealth * 1.1);
	health = maxhealth;
	damage = damage * 1.1;
	xp -= 100;
};

void Character::reduceHealthByDamage(Player& attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
	attacker.gainXP();
}



Player Player::parseUnit(const std::string& fname) {
	Character ch = Character::parseUnit(fname);
	return Player(ch.getName(), ch.getHealth(), ch.getDamage());
}