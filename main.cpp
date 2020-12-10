#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Map.h"
#include "Game.h"




const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single mapfile should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." },
    { 5 , "The Game already has a Hero."},
    { 6 , "The Game does not have a Map"},
    { 7 , "Wrong coordinate."},
    { 8 , "There are units on the map already."},
    { 9 , "The Game is not initialized properly."}

};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    std::string hero_file;
    std::list<std::string> monster_files;
    



    try{
    Game game(argv[1]);
    Hero hero{Hero::parse("units/Dark_Wanderer.json")};
    Monster monster01{Monster::parse("units/Fallen.json")};
    Monster monster02{Monster::parse("units/Zombie.json")};
    Monster monster03{Monster::parse("units/Zombie.json")};
    Monster monster04{Monster::parse("units/Fallen.json")};
    
    
    game.putHero(hero, 12, 5);
    game.putMonster(monster01, 11, 5);
    game.putMonster(monster02, 6, 1);
    game.putMonster(monster03, 7, 1);
    game.putMonster(monster04, 8, 1);
    game.putMonster(monster01, 11, 4);
    game.putMonster(monster01, 10, 4);

    game.run();
    
    }
    catch (const JSON::ParseException& e) {bad_exit(4);}
    catch (const Game::AlreadyHasHeroException& e){bad_exit(5);}
    catch (const Map::WrongIndexException& e){bad_exit(6);}
    catch (const Game::OccupiedException& e){bad_exit(7);}
    catch (const Game::NotInitializedException& e){bad_exit(9);};
    return 0;
}
