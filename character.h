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
 * \date 2020/10/22 03:00
 * 
 * Created on 2020/10/22 03:00
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


	class Character {

	protected:
		const std::string name; ///< Name of the Character.
		double health; ///< Health of the Character.
		double damage; ///< Damage of the Character.
		const double attackspeed; ///< Attack speed of the Character.
		virtual void performAttack(Character& defender);

	public:
		/**
		 *  Character constructor
		 * 
		 * Sets the character's data according to the parameters.
		 * 
		 * \param name Name of the Character
		 * \param health Health of the Character
		 * \param damage Damage of the Character
		 * \param attackspeed Attack speed of the Character
		*/
		Character(const std::string& name, double health, double damage, const double attackspeed);
		/// This function reduces the Health of a Character based on the Attacker's damage.
		double reduceHealthByDamage(const Character& attacker /** [in] Attacker unit. */);	
		/**
		 * \brief Get Damage of the Character
		 * \param none
		 * \return Character's damage
		*/
		double getDamage() const;
		/**
		 * \brief Get Health of the Character
		 * \param none
		 * \return Character's Health
		*/
		double getHealth() const;
		/**
		 * \brief Get Attack Speed of the Character
		 * \param none
		 * \return Character's AttackSpeed
		*/
		double getAttackspeed() const;
		/**
		 * \brief Get Name of the Character
		 * \param none
		 * \return Character's Name
		*/
		const std::string& getName() const;
		/// This function performs the attacks between two Characters until one of them dies.
		void attack(Character& defender/** [in] Defender unit, target of the attack. */);	
		/// This function parses the .json files for the Units.
		static Character parseUnit(const std::string& fname);
	};
	#endif