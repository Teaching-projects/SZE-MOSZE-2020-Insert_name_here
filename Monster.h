/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * This class is repsonsible for the Monsters and Units.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.1
 * 
 * \date 2020/11/02 19:44
 * 
 * Created on 2020/11/02 19:44
*/

#ifndef Monster_HPP
#define Monster_HPP
#include <string>


	class Monster {

	protected:
		const std::string name; ///< Name of the Monster.
		int health; ///< Health of the Monster.
		double damage; ///< Damage of the Monster.
		double attackspeed; ///< Attack speed of the Monster.
		/**
		 *  \brief This function calls the right function with the right parameters for adjusting Health.
		 *  \param defender Defending unit
		*/
		virtual void performAttack(Monster& defender);

	public:
		bool isAlive() {return health;}
		/**
		 *  Monster constructor
		 * 
		 * Sets the Monster's data according to the parameters.
		 * 
		 * \param name Name of the Monster
		 * \param health Health of the Monster
		 * \param damage Damage of the Monster
		 * \param attackspeed Attack speed of the Monster
		*/
		Monster(const std::string& name, int health, double damage, const double attackspeed);
		/// This function reduces the Health of a Monster based on the Attacker's damage.
		double reduceHealthByDamage(const Monster& attacker /** [in] Attacker unit. */);	
		/**
		 * \brief Get Damage of the Monster
		 * \param none
		 * \return Monster's damage
		*/
		double getDamage() const;
		/**
		 * \brief Get Health of the Monster
		 * \param none
		 * \return Monster's Health
		*/
		int getHealthPoints() const;
		/**
		 * \brief Get Attack Speed of the Monster
		 * \param none
		 * \return Monster's AttackSpeed
		*/
		double getAttackCoolDown() const;
		/**
		 * \brief Get Name of the Monster
		 * \param none
		 * \return Monster's Name
		*/
		const std::string& getName() const;
		/// This function performs the attacks between two Monsters until one of them dies.
		void fightTilDeath(Monster& defender/** [in] Defender unit, target of the attack. */);	
		/// This function parses the .json files for the Units.
		static Monster parse(const std::string& fname/** [in]  File name of Unit .json or string data of the Unit*/);
	};
	#endif