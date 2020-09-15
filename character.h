#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <iostream>




	class Character {

	private:
		const std::string name;
		int health;
		const int damage;

		void healthloss(int damage);
		std::string getname();
		int getdamage();
		int gethealth();

		void print_attack(Character attacker, Character defender);
		void print_status(Character ch01, Character ch02);
		void print_whowins(Character ch01, Character ch02);





	public:
		Character(std::string name, int health, int damage);
		//Character input_character();
		void fight(Character& ch01, Character& ch02);


	};
	#endif