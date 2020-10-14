#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:
		std::vector<Character> CH;

	public:	
		void printWhoWins(Character attacker, Character defender) const;
		void fight();
		void addCharacter(const std::string& fname);
		template<class T1, class T2> void
			attack(T1& attacker, T2& defender);
};
#endif
