#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


	class Character {

	protected:
		const std::string name;
		double health;
		double damage;

	public:
		Character(const std::string& name, double health, double damage);
		double reduceHealthByDamage(const Character& attacker);
		virtual void performAttack(Character& defender);	
		double getDamage() const;
		double getHealth() const;
		const std::string& getName() const;
		static Character parseUnit(const std::string& fname);
	};
	#endif