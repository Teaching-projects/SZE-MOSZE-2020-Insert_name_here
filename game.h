#ifndef GAME_H
#define GAME_H
#include "character.h"


class Game {
	private:		
		void printAttack(const Character* attacker, const Character* defender) const;
		void printStatus() const;
		void printWhoWins() const;
		 Character* ch01;
		 Character* ch02;
		

	public:		
		void fight() const;
		Game( Character* ch01,  Character* ch02)
		{
			this->ch01 = ch01;
			this->ch02 = ch02;
		};


};
#endif
