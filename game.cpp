#include "character.h"
#include "player.h"
#include "game.h"
#include <iostream>



void Game::printWhoWins(Character attacker, Character defender) const {
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

template<class T1, class T2>
void Game::attack(T1& attacker, T2& defender) {
	int n = 0;
	while (attacker.getHealth() > 0 and defender.getHealth() > 0) {
		(n == 0)?
			defender.reduceHealthByDamage(attacker):
			attacker.reduceHealthByDamage(defender);
		
		n = 1 - n;
	}
};

template void Game::attack <Player>(Player&, Player&);
template void Game::attack <Character>(Character&, Character&);
template void Game::attack <Character, Player>(Character&, Player&);
template void Game::attack <Player, Character>(Player&, Character&);