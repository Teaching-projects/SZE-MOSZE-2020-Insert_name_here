#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include<iostream>

#include "Hero.h"
#include "Map.h"

struct HeroData
{
    Hero* hero;
    int x;
    int y;
    HeroData(): hero(nullptr), x(-1), y(-1){};
};

struct MonsterData
{
    Monster monster;
    int x;
    int y;
    MonsterData(Monster& monster, int x, int y): monster(monster), x(x), y(y){};
};


class Game{
    std::string logfile="log.txt";
    Map gameMap;
    std::vector<MonsterData> monsters;
    HeroData hero={};
    bool isMap=false;

    public:
    Game(){}; // Empty Game
    Game(std::string mapfilename){ gameMap = Map(mapfilename); isMap=true;}
    void print() {gameMap.printMap();}
    void setMap(Map map);
    void putHero(Hero& hero, int x, int y);
    void putMonster(Monster monster, int x, int y);
    void run();

    std::string controlWithKey();
    std::string controlWithWord();

    class OccupiedException : public std::runtime_error{ 
        public:
        OccupiedException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };

    class AlreadyHasHeroException : public std::runtime_error{
        public:
        AlreadyHasHeroException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };

    class AlreadyHasUnitsException : public std::runtime_error{
        public:
        AlreadyHasUnitsException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };

    class NotInitializedException : public std::runtime_error{
        public:
        NotInitializedException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };

    class GameAlreadyStartedException : public std::runtime_error{
        public:
        GameAlreadyStartedException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };


    void writeLog(std::string output, std::string fname);

};
#endif