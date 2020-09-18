#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:	
		std::vector<Character> CH;
		void printAttack(Character &attacker, Character &defender) const;
		void printStatus() const;
		void printWhoWins() const;

	public:		
		void fight();
		void addCharacter(Character& ch);
};
#endif
