#include "jsonparser.h"
#include "character.h"
#include <fstream>
#include <cmath>



Character::Character(const std::string& name, double health, double damage, const double attackspeed) : name(name), health(health), damage(damage), attackspeed(attackspeed) {}
const std::string& Character::getName() const { return  name; }
double Character::getDamage() const { return damage; }
double Character::getHealth() const { return health; }
double Character::getAttackspeed() const { return attackspeed; }

double Character::reduceHealthByDamage(const Character& attacker) {
	double gainedxp;
	if (health - attacker.getDamage() >= 0) {
		gainedxp = attacker.getDamage();
		health -= attacker.getDamage();
	}
	else {
		gainedxp = health;
		health = 0;
	}
	return gainedxp;
}


void Character::performAttack(Character& defender) {
	defender.reduceHealthByDamage(*this);
}


Character Character::parseUnit(const std::string& fname) {
	std::map<std::string, std::string> P;
	if (fname.find(".json", fname.size() - 5) == -1u){
		P = Parser::StringToMap(fname);
	}
	else{
		P = Parser::jsonParser(fname);
	} 

	return Character(P["name"], stod(P["hp"]), stod(P["dmg"]), stod(P["attackspeed"]));
}


void Character::attack(Character& defender) {
	if (this->getAttackspeed() == 0) { this->performAttack(defender); defender.performAttack(*this); };
	double A_Timer = 0, B_Timer = 0;
	while (defender.getHealth() > 0 and this->getHealth() > 0) {

		if (A_Timer > B_Timer) defender.performAttack(*this);
		else this->performAttack(defender);
		(A_Timer > B_Timer) ?
			(A_Timer -= B_Timer, B_Timer = defender.getAttackspeed(), A_Timer = round(A_Timer*1000000)/1000000):
			(B_Timer -= A_Timer, A_Timer = this->getAttackspeed(), B_Timer = round(B_Timer*1000000)/1000000);
	}
};