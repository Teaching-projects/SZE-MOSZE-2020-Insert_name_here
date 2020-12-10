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

void Map::printMap(const int x,const int y,const int radius, std::string fname){
	int columnnumber=0;
	for (int i = 0;i < (int)MapInVector.size();i++) {
		if ((int)MapInVector[i].size() > columnnumber) columnnumber = (int)MapInVector[i].size();
	}
	std::string output;
	int n=radius*2+1;
	if(x-radius<=0) n+=x-radius;
	if(x+radius>=columnnumber) n+=columnnumber-x-radius-1;
	std::ofstream logfile;
	logfile.open(fname, std::ios_base::app);
	output= "╔";
	for (int i = 0;i < n;i++) {output += "══";}output += "╗\n";
	std::cout << output;
	logfile << output;
	for (int i = 0;i < (int)MapInVector.size();i++) {
		if((int)MapInVector.size()-y-radius-1<=i && (int)MapInVector.size()-y+radius-1>=i){
		output="║";
		std::cout << output;
		logfile<<output;
		for (int k = 0;k < (int)MapInVector[i].size();k++) {
			if(x-radius<=k && x+radius>=k){
			if(MapInVector[i][k]=='#') {std::cout << "██";logfile << "██";}
            else if(MapInVector[i][k]=='h'){ std::cout<<"┣┫";logfile<<"┣┫";}
            else if(MapInVector[i][k]=='m'){ std::cout<<"░M";logfile<<"░M";}
            else if(MapInVector[i][k]=='M'){ std::cout<<"MM";logfile<<"MM";}
			else {std::cout << "░░"; logfile<<"░░";}
			}
		}
		for (int k = MapInVector[i].size();k < columnnumber;k++) if(x-radius<=k && x+radius>=k){std::cout << "██";logfile<<"██";};
		std::cout << "║\n";
		logfile << "║\n";
		}
	}
	output= "╚";
	for (int i = 0;i < n;i++) {output += "══";}output += "╝\n";
	std::cout << output;
	logfile << output;

	logfile.close();
}

