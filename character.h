/**
 * \class Character
 * 
 * \brief Character class
 * 
 * This class is repsonsible for the Characters and Units.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.0
 * 
 * \date 2020/10/14 18:00
 * 
 * Created on 2020/10/14 18:00
*/

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
		static Character parseUnit(const std::string& fname);
		void attack(Character& defender);
	};
	#endif