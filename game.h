#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:	
		std::vector<Character> CH;
		void printAttack(Character attacker, Character defender) const;
		void printStatus(Character ch01, Character ch02) const;
		void printWhoWins(Character ch01, Character ch02) const;

	public:		
		void fight();
		void addCharacter(Character& ch);
};
#endif
