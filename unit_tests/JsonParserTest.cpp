#include "../jsonparser.h"
#include "../jsonparser.cpp"
#include "../character.h"
#include "../character.cpp"
#include "../game.h"
#include "../game.cpp"
#include "../player.cpp"
#include "../player.h"
#include <string>
#include <map>
#include <gtest/gtest.h>



TEST(ParserTest, StringRead) {
     std::map<std::string,std::string> M1,M2;
    M1=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":110,\"attackspeed\": 1.25");
    M2=Parser::StringToMap("{  \"hp\"110,\"dmg\" 35 \"name\":\"Rotfiend\",\"attackspeed\": 1.25}");
    
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1["hp"],"110")<<"M1[\"hp\"] is incorrect (read from string)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, whitespaces){
     std::map<std::string,std::string> M1,M2;
    M1=Parser::StringToMap("{   \"name\"    :   \"Rotfiend\"            ,\"dmg\"        : 35        },      \"hp\"  :110     ,\"attackspeed\"  : 1.25");
    M2=Parser::StringToMap("{       \"hp\"110,      \"dmg\" 35      \"name\":\"Rotfiend\"       ,\"attackspeed\":               1.25}");
    
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1["hp"],"110")<<"M1[\"hp\"] is incorrect (read from string)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, StringToMap){
    std::map<std::string,std::string> M1{{"hp","110"},{"name","Rotfiend"},{"dmg","35"},{"attackspeed","1.25"}};
    std::map<std::string,std::string> M2;
    M2=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":110,\"attackspeed\": 1.25");
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1["hp"],"110")<<"M1[\"hp\"] is incorrect (read from string)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, unit_data_order){
     std::map<std::string,std::string> M1,M2;
    M1=Parser::StringToMap("{\"hp\":110,\"name\":\"Rotfiend\",\"attackspeed\": 1.25,\"dmg\": 35}");
    M2=Parser::StringToMap("{\"attackspeed\": 1.25m,\"dmg\" 35 \"name\":\"Rotfiend\",\"hp\"110,}");
    
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1["hp"],"110")<<"M1[\"hp\"] is incorrect (read from string)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, IsFileExists) {
    ASSERT_ANY_THROW(Parser::jsonParser("../units/nonExistentFile.json"))<<"No error throw when try to read from file, what does not exist";
    ASSERT_NO_THROW(Parser::jsonParser("../units/unit3.json"))<<"The file does not exist";
}
TEST(ParserTest, FileRead) {
    std::map<std::string,std::string> M1,M2;
    M1=Parser::jsonParser("../units/unit3.json");
    M2=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":100,\"attackspeed\": 1.25");
    
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from file)";
    ASSERT_EQ(M1["hp"],"100")<<"M1[\"hp\"] is incorrect (read from file)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from file)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, Missing_Key){
     
     ASSERT_ANY_THROW(Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35}"))<<"No error throw when input incomplete";
     ASSERT_ANY_THROW(Parser::StringToMap("{\"name\":\"Rotfiend\""))<<"No error throw when input incomplete";
}
TEST(ParserTest, missingquotemarks){
    ASSERT_ANY_THROW(Parser::StringToMap("{\"name:\"Rotfiend,\"dmg: 35},hp\":110"))<<"No error throw when missing \" in input";
    
}
TEST(ParserTest, ParseUnit){   
    std::map<std::string,std::string> unit1;
    unit1=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":100,\"attackspeed\": 1.25");    
    Character C1(Character::parseUnit("../units/unit3.json"));
    ASSERT_EQ(stod(unit1["hp"]),C1.getHealth());       
}
TEST(GameTest, Attack){
    Game Testgame;
    Player p1(Player::parseUnit("../units/player.json"));
    Character c1(Character::parseUnit("../units/unit1.json"));
    p1.attack(c1);
    ASSERT_EQ(p1.getHealth(),94);
    
}
TEST(GameTest, Levelup){
    Game Testgame;
    Player p1(Player::parseUnit("../units/player.json"));
    Character c1(Character::parseUnit("../units/unit1.json"));
    p1.attack(c1);
    ASSERT_EQ(p1.getDamage(),44);

}
TEST(GameTest, XP){
    Game Testgame;
    Player p1(Player::parseUnit("../units/player.json"));
    Character c1(Character::parseUnit("../units/unit1.json"));
    p1.attack(c1);
    ASSERT_EQ(p1.getXP(),40);
}
TEST(GameTest, ENEMYHP){
    Game Testgame;
    Player p1(Player::parseUnit("../units/player.json"));
    Character c1(Character::parseUnit("../units/unit1.json"));
    p1.attack(c1);
    ASSERT_EQ(c1.getHealth(),0);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
