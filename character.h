#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>



	class Character {

	private:
		const std::string name;
		int health;
		const int damage;

	public:
		Character(const std::string& name, int health, const int& damage);		
		void reduceHealthByDamage(Character& attacker);
		int getDamage() const;
		int getHealth() const;
		std::string getName() const;


	};
	#endif