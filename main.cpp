#include "character.h"
#include "player.h"
#include "game.h"
#include <iostream>



int main(int argc, char *argv[]) {
	if (argc != 3) {std::cout << "Incorrect number of arguments."; return 1;}

	try{	
	Game G;
		Player p1(Player::parseUnit(argv[1]));
		Character c1(Character::parseUnit(argv[2]));
		p1.attack(c1);
		G.printWhoWins(p1, c1);
	}
	catch (std::string const &fileError) {
		std::cout << fileError;
		return 1;
	}
	return 0;
}

	





