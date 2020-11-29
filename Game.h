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
    Monster* monster;
    int x;
    int y;
    MonsterData(Monster& monster, int x, int y): monster(&monster), x(x), y(y){};
};


class Game{

    Map gameMap;
    std::vector<MonsterData> monsters;
    HeroData hero={};
    public:

    Game(); // Empty Game
    Game(std::string mapfilename){ gameMap = Map(mapfilename);}
    void print(){gameMap.printMap();}
    void setMap(Map map){gameMap=map;}
    void putHero(Hero& hero, int x, int y){
        if(gameMap.get(x,y)==1){
        this->hero.hero=&hero;
        this->hero.x=x;
        this->hero.y=y;
        gameMap.setObject('h',x,y);
        }
    }
    void putMonster(Monster monster, int x, int y){

        if(gameMap.get(x,y)==1){
            for (auto& it:monsters){
                if (it.x==x && it.y==y){
                    gameMap.setObject('M',x,y);
                    this->monsters.push_back( MonsterData (monster, x, y));
                    return;
                }
            }
            this->monsters.push_back( MonsterData (monster, x, y));
            gameMap.setObject('m',x,y);
            }
    }


    void run(){
        int x=0, y=0;
        std::string input;

        while(true){
            if(input=="north") {x=0; y= 1;}
            else if(input=="south") {x=0; y= -1;}
            else if(input=="east"){x=1; y= 0;}
            else if(input=="west"){x=-1; y= 0;}
            else {x=0; y= 0;}
            if(gameMap.get(this->hero.x+x,this->hero.y+y)==1){
                gameMap.setObject(' ',this->hero.x,this->hero.y);
                gameMap.setObject('h',this->hero.x+x,this->hero.y+y);
                this->hero.x+=x;
                this->hero.y+=y;
                for(auto it=monsters.begin(); it!=monsters.end();){
                    if(it->x==this->hero.x && it->y==this->hero.y){
                        hero.hero->fightTilDeath(*it->monster);
                        if(hero.hero->isAlive()){
                            it=monsters.erase(it);
                            if(monsters.size()==0){
                                std::cout<< hero.hero->getName()<<" cleared the map.\n\n";
                                return;
                            }
                        }
                        else {
                            std::cout<< hero.hero->getName()<<" died.\n\n";
                            hero.hero=nullptr;
                            hero.x=-1;
                            hero.y=-1;
                            return;
                        }
                    }
                    else it++;
                }
            }
            gameMap.printMap();
            std::cin>>input;
        }

    };














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

};
#endif