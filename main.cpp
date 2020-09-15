#include "character.h"
#include <iostream>



int main(int argc, char *argv[]) {
	Character ch01(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
	Character ch02(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));


	ch01.fight(ch01, ch02);

	return 0;
}