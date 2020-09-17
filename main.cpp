#include "character.h"
#include "game.h"




int main(int argc, char *argv[]) {
	Character ch01(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Character ch02(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
	Game G;
	G.fight(ch01, ch02);	
	return 0;
}

	


