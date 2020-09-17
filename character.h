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
		Character(const std::string& name, int health, int damage);
		void healthLoss(const Character* Attacker) ;
		int getDamage() const;
		int getHealth() const;
		std::string getName() const;


	};
	#endif