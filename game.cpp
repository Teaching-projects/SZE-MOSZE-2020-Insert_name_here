#include "character.h"
#include "player.h"
#include "game.h"
#include <iostream>



void Game::printWhoWins(const Character &attacker, const Character &defender) const {
	if (attacker.getHealth() > 0) std::cout << attacker.getName() << " wins. Remaining HP: " << attacker.getHealth() << '\n';
	else std::cout << defender.getName() << " wins. Remaining HP: " << defender.getHealth() << '\n';
}


void Game::fight() {
	CH[0].attack(CH[1]);
	Game::printWhoWins(CH[0], CH[1]);
}


void Game::addCharacter(const std::string& fname) {
	CH.push_back(Character::parseUnit(fname));
}


