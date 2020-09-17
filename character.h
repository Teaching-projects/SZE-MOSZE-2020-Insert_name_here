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
		void healthLoss(int damage);
		int getDamage() const;
		int getHealth() const;
		std::string getName() const;


	};
	#endif