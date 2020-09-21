#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>



	class Character {

	private:
		const std::string name;
		int health;
		const int damage;
		friend class Game;

	public:
		Character(std::string name, int health, int damage);		
		void reduceHealthByDamage(const Character& attacker);
		int getDamage() const;
		int getHealth() const;
		const std::string& getName() const;

		static Character parseUnit(const std::string& fname);
	};
	#endif