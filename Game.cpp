#include "Game.h"
#include <fstream>


void Game::setMap(Map map){
        if(this->hero.hero!=nullptr || this->monsters.size()!=0) throw AlreadyHasUnitsException("There are units on the map already.");
        gameMap=map;
        isMap=true;
}



 void Game::putHero(Hero& hero, int x, int y){
        if(!isMap) throw Map::WrongIndexException("No Map");
        if(this->hero.hero!=nullptr && this->hero.hero->isAlive()) throw  AlreadyHasHeroException("The game already has a Hero.");
        if(gameMap.get(x,y)==1){
        this->hero.hero=&hero;
        this->hero.x=x;
        this->hero.y=y;
        gameMap.setObject('h',x,y);
        }
        else throw OccupiedException("Wrong coordinate.");
    }

    void Game::putMonster(Monster monster, int x, int y){
        if(!isMap) throw Map::WrongIndexException("No Map");
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
        else throw OccupiedException("Wrong coordinate.");
    };



void Game::run(){
        unsigned short int control=1;
        if(control==0) system("clear");
        if(!isMap || this->hero.hero==nullptr) throw NotInitializedException("The Game is not initialized properly.");
        int remaining=monsters.size();
        int x=0, y=0;
        std::string input, output;


        while(true){
            if(input=="north") {x=0; y= 1;}
            else if(input=="south") {x=0; y= -1;}
            else if(input=="east"){x=1; y= 0;}
            else if(input=="west"){x=-1; y= 0;}
            else if(input=="keyboard"){control=0;}
            else if(input=="exit") return;
            else {x=0; y= 0;}
            if(gameMap.get(this->hero.x+x,this->hero.y+y)==1){
                gameMap.setObject(' ',this->hero.x,this->hero.y);
                gameMap.setObject('h',this->hero.x+x,this->hero.y+y);
                this->hero.x+=x;
                this->hero.y+=y;


                for(int i = 0; i < (int)monsters.size();){

                    if(monsters[i].x==this->hero.x && monsters[i].y==this->hero.y && monsters[i].monster.isAlive()){
                        hero.hero->fightTilDeath(monsters[i].monster);
                        if(hero.hero->isAlive()){
                            i++;
                            --remaining;
                            if(remaining==0){
                                output=hero.hero->getName()+" cleared the map.\n\n";
                                std::cout<< output;
                                writeLog(output,logfile);
                                return;
                            }
                        }
                        else {
                            output=hero.hero->getName()+" died.\n\n";
                            std::cout<< output;
                            writeLog(output,logfile);
                            hero.hero=nullptr;
                            hero.x=-1;
                            hero.y=-1;
                            return;
                        }

                       
                    }

                    else i++;
                }
            }
            gameMap.printMap(hero.x,hero.y,hero.hero->getLight_radius(), logfile);
            if(control==0) input=controlWithKey();
            else input=controlWithWord();
        }
        

    };


    std::string Game::controlWithKey(){
        char c;
        system("stty raw");

        c = getchar(); 
        system("stty cooked");
        system("clear");

        switch(c){
            case 'D':
            case 'a': return "west";
            case 'B':
            case 's': return "south";
            case 'C':
            case 'd': return "east";
            case 'A':
            case 'w': return "north";
            default: return "";
        }

    }



    std::string Game::controlWithWord(){
        std::string input;
        std::cin>>input;
        writeLog(input+'\n',logfile);
        return input;
    }



    
    void Game::writeLog(std::string output, std::string fname){
        std::ofstream logfile;
	    logfile.open(fname, std::ios_base::app);
        logfile<<output;
        logfile.close();
    }