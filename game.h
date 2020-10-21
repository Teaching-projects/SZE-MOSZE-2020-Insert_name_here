/**
 * \class Game
 * 
 * \brief Game class
 * 
 * This class is repsonsible for running fight and the printing the Winner.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.0
 * 
 * \date 2020/10/14 18:00
 * 
 * Created on 2020/10/14 18:00
*/
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
};
#endif
