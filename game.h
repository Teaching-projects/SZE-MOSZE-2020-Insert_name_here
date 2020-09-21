#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:	
		std::vector<Character> CH;
		void printWhoWins() const;

	public:	
		void fight();
		void addCharacter(const std::string& fname);
};
#endif
