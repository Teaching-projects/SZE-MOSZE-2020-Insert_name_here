#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"


class Player : public Character {
private:
	double xp=0;
	int maxhealth = health;

public:
	Player(const std::string& name, double health, double damage);
	void gainXP();
	void lvlUp();
	int getXP() { return xp; }

	static Player parseUnit(const std::string& fname);
};
#endif