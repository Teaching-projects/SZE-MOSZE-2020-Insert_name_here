#include "character.h"
#include "game.h"
#include <iostream>




void Game::printAttack(Character attacker, Character defender) const {
	std::cout << attacker.getName() << " -> " << defender.getName() << '\n';
}


void Game::printStatus(Character ch01, Character ch02) const {
	std::cout << ch01.getName() << ": HP: " << ch01.getHealth() << ", DMG: " << ch01.getDamage() << '\n';
	std::cout << ch02.getName() << ": HP: " << ch02.getHealth() << ", DMG: " << ch02.getDamage() << '\n';
}


void Game::printWhoWins(Character ch01, Character ch02) const {
	if (ch02.getHealth() > 0) {
		std::cout << ch01.getName() << " died. " << ch02.getName() << " wins.\n";
	}
	else { std::cout << ch02.getName() << " died. " << ch01.getName() << " wins.\n"; }

}
void Game::fight() {

	Game::printStatus(CH[0], CH[1]);
	int n = 0;
	int m = 1;

	while (CH[1].getHealth() > 0 and CH[0].getHealth() > 0)
	{
			CH[m].reduceHealthByDamage(CH[n]);
			Game::printAttack(CH[n], CH[m]);
			Game::printStatus(CH[0], CH[1]);
		
			n = 1 - n;
			m = 1 - m;
	}
	Game::printWhoWins(CH[0], CH[1]);

}


void Game::addCharacter(Character& ch) {
	CH.push_back(ch);
}