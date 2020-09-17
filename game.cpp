#include "character.h"
#include "game.h"





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
void Game::fight(Character& ch01, Character& ch02) const {
	Game::printStatus(ch01, ch02);
	while (ch02.getHealth() > 0 and ch01.getHealth() > 0)
	{
		if (ch02.getHealth() > 0) {
			ch02.healthLoss(ch01);
			Game::printAttack(ch01, ch02);
			Game::printStatus(ch01, ch02);
		}

		if (ch01.getHealth() > 0 and ch02.getHealth() > 0) {
			ch01.healthLoss(ch02);
			Game::printAttack(ch02, ch01);
			Game::printStatus(ch01, ch02);
		}
	}
	Game::printWhoWins(ch01, ch02);

}
