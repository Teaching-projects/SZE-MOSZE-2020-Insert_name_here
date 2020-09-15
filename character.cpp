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


void Character::print_attack(Character attacker, Character defender) {
	std::cout << attacker.getname() << " -> " << defender.getname() << '\n';
}


void Character::print_status(Character ch01, Character ch02) {
	std::cout << ch01.getname() << ": HP: " << ch01.gethealth() << ", DMG: " << ch01.getdamage() << '\n';
	std::cout << ch02.getname() << ": HP: " << ch02.gethealth() << ", DMG: " << ch02.getdamage() << '\n';
}


void Character::print_whowins(Character ch01, Character ch02) {
	if (ch02.gethealth() > 0) {
		std::cout << ch01.getname() << " died. " << ch02.getname() << " wins.\n";
	}
	else { std::cout << ch02.getname() << " died. " << ch01.getname() << " wins.\n"; }

}


void Character::fight(Character& ch01, Character& ch02) {
	print_status(ch01, ch02);
	while (ch02.gethealth() > 0 and ch01.gethealth() > 0)
	{
		if (ch02.gethealth() > 0) {
			ch02.healthloss(ch01.getdamage());
			print_attack(ch01, ch02);
			print_status(ch01, ch02);



		}
		if (ch01.gethealth() > 0 and ch02.gethealth() > 0) {
			ch01.healthloss(ch02.getdamage());
			print_attack(ch02, ch01);
			print_status(ch01, ch02);
		}
	}
	print_whowins(ch01, ch02);

}



