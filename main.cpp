#include "character.h"
#include "player.h"
#include "game.h"
#include <iostream>



int main(int argc, char *argv[]) {
	if (argc != 3) {std::cout << "Incorrect number of arguments."; return 1;}

	try{	

		std::string fname1 = argv[1];
		std::string fname2 = argv[2];

	Game G;
	if (fname1 == "player.json") {
		Player p1(Player::parseUnit(fname1));
		Character c1(Character::parseUnit(fname2));
		G.attack(p1, c1);
		G.printWhoWins(p1, c1);
	}
	else if (fname2 == "player.json") {
		Character c1(Character::parseUnit(fname1));
		Player p1(Player::parseUnit(fname2));
		G.attack(c1, p1);
		G.printWhoWins(p1, c1);
	}
	else {
		G.addCharacter(argv[1]);
		G.addCharacter(argv[2]);
		G.fight();
	}

	}
	catch (std::string &fileError) {
		std::cout << fileError;
		return 1;
	}
	return 0;
}

	





