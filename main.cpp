#include "character.h"
#include "game.h"
#include <iostream>



int main(int argc, char *argv[]) {
	


	if (argc == 3) try{
		
		Game G;

		G.addCharacter(argv[1]);
		G.addCharacter(argv[2]);
		G.fight();
	}
	catch (std::string fileError) {
		std::cout << fileError;
	}
	else {
		std::cout << "Incorrect number of arguments.";
	}

	return 0;
}

	


