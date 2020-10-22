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
 * \date 2020/10/22 03:00
 * 
 * Created on 2020/10/22 03:00
*/
#ifndef GAME_H
#define GAME_H
#include "character.h"
#include <vector>




class Game {
	private:	
		/// Character vector
		std::vector<Character> CH;

	public:	
		/// This Function prints out the winner of the fight.
		void printWhoWins(const Character &attacker, const Character &defender) const;
		/// This Function is responsible for starting the fight.
		void fight();
		/// This Function is responsible for adding Characters or units to the Character vector.
		void addCharacter(const std::string& fname/** [in] File name of Unit .json*/);
};
#endif
