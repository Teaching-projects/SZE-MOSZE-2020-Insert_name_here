#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:	
		std::vector<Character> CH;
		void printAttack(const Character &attacker,const Character &defender) const;
		void printStatus() const;
		void printWhoWins() const;

	public:		
		void fight();
		void addCharacter(const Character& ch);
};
#endif
