#include "JSON.h"
#include "Monster.h"
#include <fstream>
#include <cmath>



Monster::Monster(const std::string& name, int health, int damage, const float attackspeed, float defense) : name(name), health(health), damage(damage), attackspeed(attackspeed), defense(defense) {}
const std::string& Monster::getName() const { return  name; }
float Monster::getDamage() const { return damage; }
int Monster::getHealthPoints() const { return health; }
float Monster::getAttackCoolDown() const { return attackspeed; }

float Monster::reduceHealthByDamage(const Monster& attacker) {
	float gainedxp;
	if (health + defense - attacker.getDamage() >= 0) {
		gainedxp = attacker.getDamage() - defense;
		if (gainedxp<0) gainedxp=0;
		health -= attacker.getDamage() + defense;
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
	if (fname.substr(fname.size()-5,5)!=".json"){
		P = JSON::StringToJSON(fname);
	}
	else{
		P = JSON::parseFromFile(fname);
	} 
  	return Monster(
    P.get<std::string>("name"),
    P.get<int>("health_points"),
    P.get<int>("damage"),
    P.get<float>("attack_cooldown"),
	P.get<float>("defense")
  );
}


void Monster::fightTilDeath(Monster& defender) {
	int rounding=10, A_Timer = this->getAttackCoolDown()*rounding, B_Timer = defender.getAttackCoolDown()*rounding;
	this->performAttack(defender);if(defender.getHealthPoints()>0)defender.performAttack(*this);
	while (defender.getHealthPoints() > 0 && this->getHealthPoints() > 0) {

		if (A_Timer > B_Timer) defender.performAttack(*this);
		else this->performAttack(defender);
		(A_Timer > B_Timer) ?
			(A_Timer -= B_Timer, B_Timer = rounding*defender.getAttackCoolDown()):
			(B_Timer -= A_Timer, A_Timer = rounding*this->getAttackCoolDown());
	}
};