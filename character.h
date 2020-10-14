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
 * 	Created on 2020/10/14 18:00
*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


	class Character {

	private:
		const std::string name; /// Name of the character.
		int health; /// Health of the character.
		const int damage; /// Damage of the character.
		const double attackspeed; /// Attack speed of the character.
		friend class Game;
		/// This function reduces the Health of a character based on the Attacker's damage.
		void reduceHealthByDamage(const Character& attacker /** [in] Attacker unit. */);

	public:
	/**
	 *  Character constructor
	 * 
	 * Sets the character's data according to the parameters.
	 * 
	 * \param name Name of the character
	 * \param health Health of the character
	 * \param damage Damage of the character
	 * \param attackspeed Attack speed of the character
	*/
		Character(const std::string& name, int health, int damage, const double attackspeed);
		/**
		 * \brief Get Damage of the Character
		 * \param none
		 * \return Character's damage
		*/
		int getDamage() const;
		/**
		 * \brief Get Health of the Character
		 * \param none
		 * \return Character's Health
		*/
		int getHealth() const;
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
		/// This function starts the attack
		void attack(Character& defender /** [in] Defender unit, target of the attack. */);
		/// This function parses the .json files for the Units.
		static Character parseUnit(const std::string& fname);
	};
	#endif