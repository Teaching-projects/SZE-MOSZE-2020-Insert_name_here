#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


	class Character {

	protected:
		const std::string name;
		double health;
		double damage;
		const double attackspeed;
		virtual void performAttack(Character& defender);

	public:
		Character(const std::string& name, double health, double damage, const double attackspeed);
		double reduceHealthByDamage(const Character& attacker);	
		double getDamage() const;
		double getHealth() const;
		double getAttackspeed() const;
		const std::string& getName() const;
		void attack(Character& defender);	
		static Character parseUnit(const std::string& fname);
	};
	#endif