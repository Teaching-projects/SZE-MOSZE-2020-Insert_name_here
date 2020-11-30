#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include<iostream>

class Map{

enum type {Wall, Free};
std::vector<std::string> MapInVector;
public:




Map(){};
Map(std::string filename);
void printMap();

type get(int x, int y) const{
    if(MapInVector[MapInVector.size()-y-1][x]=='#')return Wall;
    else return Free;
}

void setObject(char c,int x,int y){MapInVector[MapInVector.size()-y-1][x]=c;}

class WrongIndexException : public std::runtime_error{
    public:
        WrongIndexException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };
};
#endif