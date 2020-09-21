#include "character.h"
#include <fstream>


Character::Character(std::string name, int health, int damage) :name(name), health(health), damage(damage) {}
const std::string& Character::getName() const { return  name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }



void Character::reduceHealthByDamage(const Character &attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
}


Character Character::parseUnit(const std::string& fname) {
	std::ifstream file;
	file.open(fname);
	if (file.fail()) throw "The " + fname + " file does not exist or is not readable.";
	std::string line, type, name, hp, dmg;

	while (getline(file, line)) {

		for (int i = 0; i < line.size(); i++) {
			if (isalnum(line[i])) {

				if (type == "name") name += line[i];
				else if (type == "hp") hp += line[i];
				else if (type == "dmg") dmg += line[i];
				else type += line[i];
			}
		}
		type = "";
	}


	file.close();
	return Character(name, stoi(hp), stoi(dmg));
}



