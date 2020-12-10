/**
 * \class Hero
 * 
 * \brief Hero class
 * 
 * This class is repsonsible for the Hero.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.0
 * 
 * \date 2020/11/02 19:44
 * 
 * Created on 2020/11/02 19:44
*/
#ifndef Hero_H
#define Hero_H
#include "Monster.h"


class Hero : public Monster {
private:
	float defense_bonus_per_level=0;
	float xp=0; ///< XP of the Hero
	int level=1;
	int maxhealth = health; ///< Maxhealth of the Hero
	int experience_per_level=0;
    int health_point_bonus_per_level=0;
    float damage_bonus_per_level=0;
    float cooldown_multiplier_per_level=0;
	int light_radius;
	int light_radius_bonus_per_level=1;
	/**
	 * \brief Function responsible for settting xp for the Hero and calling lvlup function if necessary.
	 * \param damagePoints Dealt damage to the defender, used to calculate xp given to the Hero.
	*/
	void gainXP(float damagePoints);
	void lvlUp(); ///< Function to level up the Hero, giving it more maxhealth, attackspeed, damage and resseting it's XP
	/**
	 *  \brief This function calls the right function with the right parameters for adjusting Health and xp.
	 *  \param defender Defending unit
	*/
	void performAttack(Monster& defender) override;
public:
	/**
	 *  Hero constructor
	 * 
	 * Sets the Hero's data according to the parameters.
	 * 
	 * \param name Name of the Hero
	 * \param health Health of the Hero
	 * \param damage Damage of the Hero
	 * \param attackspeed Attack speed of the Hero
	*/
	Hero(const std::string& name, int health, int damage, float attackspeed, float defense, float defense_bonus_per_level, const int experience_per_level, const int health_point_bonus_per_level,
			const int damage_bonus_per_level, const float cooldown_multiplier_per_level, int light_radiusint, int light_radius_bonus_per_level);
	/**
	 * \brief Get XP of the Hero
	 * \param none
	 * \return Hero's XP
	*/
	int getXP();
	int getLight_radius(){return light_radius;}
	int getMaxHealthPoints(){return maxhealth;}
	int getLevel(){return level;}
	/// This function parses the .json files for the Hero.
	static Hero parse(const std::string& fname/** [in]  File name of Hero .json or string data of the Hero*/);
};
#endif