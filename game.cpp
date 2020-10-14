#include "character.h"
#include "game.h"
#include <iostream>





void Game::printWhoWins() const {
	int winner;
	CH[1].getHealth() > 0 ? winner = 1 : winner=0;
		std::cout << CH[winner].getName() << " wins. Remaining HP: "<< CH[winner].getHealth()<<'\n';
}


void Game::fight() {
	CH[0].attack(CH[1]);
	Game::printWhoWins();
}


void Game::addCharacter(const std::string& fname) {

	CH.push_back(Character::parseUnit(fname));
}