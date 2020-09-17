#ifndef GAME_H
#define GAME_H
#include "character.h"


class Game {
	private:		
		void printAttack(Character attacker, Character defender) const;
		void printStatus(Character ch01, Character ch02) const;
		void printWhoWins(Character ch01, Character ch02) const;

	public:		
		void fight(Character& ch01, Character& ch02) const;
};
#endif
