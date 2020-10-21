#include "character.h"
#include "player.h"
#include "game.h"
#include <iostream>



void Game::printWhoWins(const Character &attacker, const Character &defender) const {
	if (attacker.getHealth() > 0) std::cout << attacker.getName() << " wins. Remaining HP: " << attacker.getHealth() << '\n';
	else std::cout << defender.getName() << " wins. Remaining HP: " << defender.getHealth() << '\n';
}


void Game::fight() {
	attack(CH[0],CH[1]);
	Game::printWhoWins(CH[0], CH[1]);
}


void Game::addCharacter(const std::string& fname) {
	CH.push_back(Character::parseUnit(fname));
}


void Game::attack(Character& attacker, Character& defender) {
	while (attacker.getHealth() > 0 and defender.getHealth() > 0) {

		attacker.performAttack(defender);
		if(defender.getHealth()>0)
			defender.performAttack(attacker);
	}
};