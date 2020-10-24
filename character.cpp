#include "jsonparser.h"
#include "character.h"
#include <fstream>


Character::Character(const std::string& name, int health, int damage) :name(name), health(health), damage(damage) {}
const std::string& Character::getName() const { return  name; }
int Character::getDamage() const { return damage; }
int Character::getHealth() const { return health; }



void Character::reduceHealthByDamage(const Character &attacker) {
	health -= attacker.damage;
	if (health < 0) { health = 0; }
}


Character Character::parseUnit(const std::string& fname) {
	std::map<std::string, std::string> P;
	if (fname.find(".json", fname.size() - 5) == -1){
		P = Parser::StringToMap(fname);
	}
	else{
		P = Parser::jsonParser(fname);
	} 

	return Character(P["name"], stoi(P["hp"]), stoi(P["dmg"]));
}



