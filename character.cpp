#include "character.h"
#include <fstream>



Character::Character(const std::string& name, int health, int damage, const double attackspeed) :name(name), health(health), damage(damage), attackspeed(attackspeed) {}
const std::string& Character::getName() const { return  name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }
double Character::getAttackspeed() const { return attackspeed; }


void Character::reduceHealthByDamage(const Character &attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
}


Character Character::parseUnit(const std::string& fname) {
	std::ifstream file;
	file.open(fname);
	if (file.fail()) throw "The " + fname + " file does not exist or is not readable.";
	std::string line, type, name, hp, dmg, attackspeed;
	bool inside = 0;

	while (getline(file, line)) {


		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '"') { inside = 1 - inside; i++; }
			if (inside or isdigit(line[i]) or line[i]=='.') {

				if (type == "name") name += line[i];
				else if (type == "hp") hp += line[i];
				else if (type == "dmg") dmg += line[i];
				else if (type == "attackspeed") attackspeed += line[i];
				else type += line[i];
			}
		}
		type = "";
	}
	

	file.close();
	return Character(name, stoi(hp), stoi(dmg),stod(attackspeed));
}


void Character::attack(Character& defender) {
	if (this->getAttackspeed() == 0) { defender.reduceHealthByDamage(*this); this->reduceHealthByDamage(defender); };
	double A_Timer = 0, B_Timer = 0;
	while (defender.getHealth() > 0 and this->getHealth() > 0) {

		if (A_Timer > B_Timer) { this->reduceHealthByDamage(defender); }
		else defender.reduceHealthByDamage(*this);
		(A_Timer <= B_Timer) ?
			(B_Timer -= A_Timer, A_Timer = this->getAttackspeed()) :
			(A_Timer -= B_Timer, B_Timer = defender.getAttackspeed());
	}
};


