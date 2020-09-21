#include "character.h"
#include "game.h"
#include <iostream>




void Game::printAttack(const Character &attacker,const Character &defender) const {
	std::cout << attacker.getName() << " -> " << defender.getName() << '\n';
}


void Game::printStatus() const {
	std::cout << CH[0].getName() << ": HP: " << CH[0].getHealth() << ", DMG: " << CH[0].getDamage() << '\n';
	std::cout << CH[1].getName() << ": HP: " << CH[1].getHealth() << ", DMG: " << CH[1].getDamage() << '\n';
}


void Game::printWhoWins() const {
	if (CH[1].getHealth() > 0) {
		std::cout << CH[0].getName() << " died. " << CH[1].getName() << " wins.\n";
	}
	else { std::cout << CH[1].getName() << " died. " << CH[0].getName() << " wins.\n"; }

}
void Game::fight() {

	Game::printStatus();
	int n = 0;
	int m = 1;

	while (CH[1].getHealth() > 0 and CH[0].getHealth() > 0)
	{
			CH[m].reduceHealthByDamage(CH[n]);
			Game::printAttack(CH[n], CH[m]);
			Game::printStatus();
		
			n = 1 - n;
			m = 1 - m;
	}
	Game::printWhoWins();

}


void Game::addCharacter(const Character& ch) {
	CH.push_back(ch);
}