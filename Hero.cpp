#include "Hero.h"
#include "JSON.h"
#include <cmath>
#include <iostream>


Hero::Hero(const std::string& name, int health, int damage, float attackspeed, float defense, float defense_bonus_per_level, const int experience_per_level, const int health_point_bonus_per_level,
			const int damage_bonus_per_level, const float cooldown_multiplier_per_level, int light_radius,int light_radius_bonus_per_level):
					Monster(name, health, damage, attackspeed, defense),
					defense_bonus_per_level(defense_bonus_per_level),
					experience_per_level(experience_per_level), 			
					health_point_bonus_per_level(health_point_bonus_per_level),
					damage_bonus_per_level(damage_bonus_per_level), 		
					cooldown_multiplier_per_level(cooldown_multiplier_per_level),
					light_radius(light_radius),
					light_radius_bonus_per_level(light_radius_bonus_per_level){}


int Hero::getXP() { return xp; }
void Hero::gainXP(float gainedxp) {
	xp += gainedxp;
	while (xp >= experience_per_level)
		this->lvlUp();
};


void Hero::lvlUp() {
		maxhealth += health_point_bonus_per_level;
		health = maxhealth;
		damage += damage_bonus_per_level;
		xp -= experience_per_level;
		attackspeed *= cooldown_multiplier_per_level;
		defense+=defense_bonus_per_level;
		light_radius+=light_radius_bonus_per_level;
		level++;
};


void Hero::performAttack(Monster& defender) {
	this->gainXP(defender.reduceHealthByDamage(*this));
}



Hero Hero::parse(const std::string& fname) {
	JSON file = JSON::parseFromFile(fname);
  return Hero(
    file.get<std::string>("name"),
    file.get<int>("base_health_points"),
    file.get<int>("base_damage"),
    file.get<float>("base_attack_cooldown"),
	file.get<float>("defense"),
	file.get<float>("defense_bonus_per_level"),
    file.get<int>("experience_per_level"),
    file.get<int>("health_point_bonus_per_level"),
    file.get<int>("damage_bonus_per_level"),
    file.get<float>("cooldown_multiplier_per_level"),
	file.get<int>("light_radius"),
	file.get<int>("light_radius_bonus_per_level")
  );
}