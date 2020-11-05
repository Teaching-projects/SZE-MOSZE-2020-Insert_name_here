#include "Hero.h"
#include <cmath>


Player::Player(const std::string& name, double health, double damage, const double attackspeed) :Character(name, health, damage, attackspeed) {};
int Player::getXP() { return xp; }

void Player::gainXP(double gainedxp) {
	xp += gainedxp;
	while (xp >= 100)
		this->lvlUp();
};


void Player::lvlUp() {
		maxhealth = round(maxhealth * 1.1);
		health = maxhealth;
		damage = damage * 1.1;
		xp -= 100;
};


void Player::performAttack(Character& defender) {
	this->gainXP(defender.reduceHealthByDamage(*this));
}



Player Player::parseUnit(const std::string& fname) {
	Character ch = Character::parseUnit(fname);
	return Player(ch.getName(), ch.getHealth(), ch.getDamage(), ch.getAttackspeed());
}
