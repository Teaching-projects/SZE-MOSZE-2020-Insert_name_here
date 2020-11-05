#include "JSON.h"
#include "Monster.h"
#include <fstream>
#include <cmath>



Monster::Monster(const std::string& name, double health, double damage, const double attackspeed) : name(name), health(health), damage(damage), attackspeed(attackspeed) {}
const std::string& Monster::getName() const { return  name; }
double Monster::getDamage() const { return damage; }
double Monster::getHealth() const { return health; }
double Monster::getAttackspeed() const { return attackspeed; }

double Monster::reduceHealthByDamage(const Monster& attacker) {
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


void Monster::performAttack(Monster& defender) {
	defender.reduceHealthByDamage(*this);
}


Monster Monster::parseUnit(const std::string& fname) {
	std::map<std::string, std::string> P;
	if (fname.find(".json", fname.size() - 5) == -1u){
		P = Parser::StringToMap(fname);
	}
	else{
		P = Parser::jsonParser(fname);
	} 

	return Monster(P["name"], stod(P["hp"]), stod(P["dmg"]), stod(P["attackspeed"]));
}


void Monster::attack(Monster& defender) {
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