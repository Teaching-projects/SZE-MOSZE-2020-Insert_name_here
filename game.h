#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:
		std::vector<Character> CH;

	public:	
		void printWhoWins(const Character &attacker, const Character &defender) const;
		void fight();
		void addCharacter(const std::string& fname);
		void attack(Character& attacker, Character& defender);
};
#endif
