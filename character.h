#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <iostream>




	class Character {

	private:
		const std::string name;
		int health;
		const int damage;

	public:
		Character(std::string name, int health, int damage);		
		void healthloss(int damage);
		int getdamage();
		int gethealth();
		std::string getname();


	};
	#endif