#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


	class Character {

	private:
		const std::string name;
		int health;
		const int damage;
		const double attackspeed;
		friend class Game;
		void reduceHealthByDamage(const Character& attacker);

	public:
		Character(const std::string& name, int health, int damage, const double attackspeed);
		int getDamage() const;
		int getHealth() const;
		double getAttackspeed() const;
		const std::string& getName() const;
		void attack(Character& defender);
		static Character parseUnit(const std::string& fname);
	};
	#endif