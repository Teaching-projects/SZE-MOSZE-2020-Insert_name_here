#include "character.h"
#include "game.h"
#include <iostream>





void Game::printWhoWins() const {
	int winner;
	CH[1].getHealth() > 0 ? winner = 1 : winner=0;
		std::cout << CH[winner].getName() << " wins. Remaining HP: "<< CH[winner].getHealth()<<'\n';
}
void Game::fight() {
	int n = 0;
	int m = 1;

	while (CH[1].getHealth() > 0 and CH[0].getHealth() > 0){
			CH[m].reduceHealthByDamage(CH[n]);
			n = 1 - n;
			m = 1 - m;
	}

	Game::printWhoWins();
}


void Game::addCharacter(const std::string& fname) {

	CH.push_back(Character::parseUnit(fname));
}