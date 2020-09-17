#include "character.h"
#include "game.h"




void Game::printAttack(const Character* attacker, const Character* defender) const {
	std::cout << attacker->getName() << " -> " << defender->getName() << '\n';
}


void Game::printStatus() const {
	std::cout << ch01->getName() << ": HP: " << ch01->getHealth() << ", DMG: " << ch01->getDamage() << '\n';
	std::cout << ch02->getName() << ": HP: " << ch02->getHealth() << ", DMG: " << ch02->getDamage() << '\n';
}


void Game::printWhoWins() const {
	if (ch02->getHealth() > 0) {
		std::cout << ch01->getName() << " died. " << ch02->getName() << " wins.\n";
	}
	else { std::cout << ch02->getName() << " died. " << ch01->getName() << " wins.\n"; }

}
void Game::fight() const {
	Game::printStatus();
	while (ch02->getHealth() > 0 && ch01->getHealth() > 0)
	{
		if (ch02->getHealth() > 0) {
			ch02->healthLoss(ch01);			
			Game::printAttack(ch01,ch02);
			Game::printStatus();
		}

		if (ch01->getHealth() > 0 && ch02->getHealth() > 0) {
			ch01->healthLoss(ch02);
			Game::printAttack(ch01, ch02);
			Game::printStatus();
		}
	}
	Game::printWhoWins();

}
