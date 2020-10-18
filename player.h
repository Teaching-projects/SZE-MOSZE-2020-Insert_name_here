#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"


class Player : public Character {
private:
	double xp=0;
	int maxhealth = health;
	void gainXP(double damagePoints);
	void lvlUp();
public:
	Player(const std::string& name, double health, double damage);
	int getXP();
	void performAttack(Character& defender) override;
	static Player parseUnit(const std::string& fname);
};
#endif