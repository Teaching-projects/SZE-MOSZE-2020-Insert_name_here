#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>



Map::Map(std::string filename){
    std::ifstream file;
	file.open(filename);
    std::string data;
	while(getline(file, data)) {
		MapInVector.push_back(data);
	}
    file.close();
}



void Map::printMap() {
	int columnnumber=0;
	for (int i = 0;i < (int)MapInVector.size();i++) {
		if ((int)MapInVector[i].size() > columnnumber) columnnumber = (int)MapInVector[i].size();
	}


	std::cout << "╔";  for (int i = 0;i < columnnumber;i++) std::cout << "══"; std::cout << "╗\n";
	for (int i = 0;i < (int)MapInVector.size();i++) {
		std::cout << "║";
		for (int k = 0;k < (int)MapInVector[i].size();k++) {
			if(MapInVector[i][k]=='#') std::cout << "██";
            else if(MapInVector[i][k]=='h') std::cout<<"┣┫";
            else if(MapInVector[i][k]=='m') std::cout<<"░M";
            else if(MapInVector[i][k]=='M') std::cout<<"MM";
			else std::cout << "░░";
		}
		for (int k = MapInVector[i].size();k < columnnumber;k++) std::cout << "██";
		std::cout << "║\n";
	}
	std::cout << "╚";  for (int i = 0;i < columnnumber;i++) std::cout << "══"; std::cout << "╝\n";
}