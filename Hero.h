/**
 * \class Player
 * 
 * \brief Player class
 * 
 * This class is repsonsible for the Player.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.0
 * 
 * \date 2020/11/02 19:44
 * 
 * Created on 2020/11/02 19:44
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Monster.h"


class Player : public Character {
private:
	double xp=0; ///< XP of the Player
	int maxhealth = health; ///< Maxhealth of the Player
	/**
	 * \brief Function responsible for settting xp for the player and calling lvlup function if necessary.
	 * \param damagePoints Dealt damage to the defender, used to calculate xp given to the player.
	*/
	void gainXP(double damagePoints);
	void lvlUp(); ///< Function to level up the player, giving it more maxhealth, attackspeed, damage and resseting it's XP
	/**
	 *  \brief This function calls the right function with the right parameters for adjusting Health and xp.
	 *  \param defender Defending unit
	*/
	void performAttack(Character& defender) override;
public:
	/**
	 *  Player constructor
	 * 
	 * Sets the Player's data according to the parameters.
	 * 
	 * \param name Name of the Player
	 * \param health Health of the Player
	 * \param damage Damage of the Player
	 * \param attackspeed Attack speed of the Player
	*/
	Player(const std::string& name, double health, double damage, const double attackspeed);
	/**
	 * \brief Get XP of the Player
	 * \param none
	 * \return Player's XP
	*/
	int getXP();
	/// This function parses the .json files for the Player.
	static Player parseUnit(const std::string& fname/** [in]  File name of Player .json or string data of the Player*/);
};
#endif