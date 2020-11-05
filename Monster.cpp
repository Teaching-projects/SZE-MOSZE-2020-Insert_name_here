#include "JSON.h"
#include "Monster.h"
#include <fstream>
#include <cmath>



Monster::Monster(const std::string& name, int health, double damage, const double attackspeed) : name(name), health(health), damage(damage), attackspeed(attackspeed) {}
const std::string& Monster::getName() const { return  name; }
double Monster::getDamage() const { return damage; }
int Monster::getHealthPoints() const { return health; }
double Monster::getAttackCoolDown() const { return attackspeed; }

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


Monster Monster::parse(const std::string& fname) {
	JSON P;
	if (fname.substr(fname.size()-5,5)==".json"){
		P = JSON::StringToMap(fname);
	}
	else{
		P = JSON::parseFromFile(fname);
	} 
  	return Monster(
    P.get<std::string>("name"),
    P.get<int>("health_points"),
    P.get<int>("damage"),
    P.get<double>("attack_cooldown")
  );
}


void Monster::fightTilDeath(Monster& defender) {
	if (this->getAttackCoolDown() == 0) { this->performAttack(defender); defender.performAttack(*this); };
	int A_Timer = 0, B_Timer = 0, rounding=1000000;
	while (defender.getHealthPoints() > 0 && this->getHealthPoints() > 0) {

		if (A_Timer > B_Timer) defender.performAttack(*this);
		else this->performAttack(defender);
		(A_Timer > B_Timer) ?
			(A_Timer -= rounding* B_Timer, B_Timer = rounding* defender.getAttackCoolDown()):
			(B_Timer -= rounding* A_Timer, A_Timer = rounding* this->getAttackCoolDown());
	}
};