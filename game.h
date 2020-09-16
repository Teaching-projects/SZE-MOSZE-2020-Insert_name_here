#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include "character.h"


class Game {
	private:		
		void print_attack(Character attacker, Character defender);
		void print_status(Character ch01, Character ch02);
		void print_whowins(Character ch01, Character ch02);

	public:		
		void fight(Character& ch01, Character& ch02);
};
#endif
