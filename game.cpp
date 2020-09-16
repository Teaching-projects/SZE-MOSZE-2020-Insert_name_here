#include <iostream>
#include "character.h"
#include "game.h"





void Game::print_attack(Character attacker, Character defender) {
	std::cout << attacker.getname() << " -> " << defender.getname() << '\n';
}


void Game::print_status(Character ch01, Character ch02) {
	std::cout << ch01.getname() << ": HP: " << ch01.gethealth() << ", DMG: " << ch01.getdamage() << '\n';
	std::cout << ch02.getname() << ": HP: " << ch02.gethealth() << ", DMG: " << ch02.getdamage() << '\n';
}


void Game::print_whowins(Character ch01, Character ch02) {
	if (ch02.gethealth() > 0) {
		std::cout << ch01.getname() << " died. " << ch02.getname() << " wins.\n";
	}
	else { std::cout << ch02.getname() << " died. " << ch01.getname() << " wins.\n"; }

}
void Game::fight(Character& ch01, Character& ch02) {
	Game::print_status(ch01, ch02);
	while (ch02.gethealth() > 0 and ch01.gethealth() > 0)
	{
		if (ch02.gethealth() > 0) {
			ch02.healthloss(ch01.getdamage());
			Game::print_attack(ch01, ch02);
			Game::print_status(ch01, ch02);



		}
		if (ch01.gethealth() > 0 and ch02.gethealth() > 0) {
			ch01.healthloss(ch02.getdamage());
			Game::print_attack(ch02, ch01);
			Game::print_status(ch01, ch02);
		}
	}
	Game::print_whowins(ch01, ch02);

}
