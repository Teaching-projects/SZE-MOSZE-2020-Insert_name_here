#include "../JSON.h"
#include "../JSON.cpp"
#include "../Monster.h"
#include "../Monster.cpp"
#include "../Hero.cpp"
#include "../Hero.h"
#include <string>
#include <map>
#include <gtest/gtest.h>



TEST(ParserTest, StringRead) {
    JSON M1,M2;
    M1=JSON::StringToJSON("\"name\":\"Rotfiend\",\"damage\": 35,\"health_points\":110,\"attack_cooldown\": 1.25");
    M2=JSON::StringToJSON("{  \"health_points\"110,\"damage\" 35 \"name\":\"Rotfiend\",\"attack_cooldown\": 1.25}");
    
    ASSERT_EQ(M1.get<std::string>("name"),"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("health_points"),110)<<"M1[\"health_points\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("damage"),35)<<"M1[\"damage\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1.get<std::string>("name"),M2.get<std::string>("name"))<<"names are not equal";
    EXPECT_EQ(M1.get<int>("health_points"),M2.get<int>("health_points"))<<"healthpoints are not equal";
    EXPECT_EQ(M1.get<int>("damage"),M2.get<int>("damage"))<<"damages are not equal";
}
TEST(ParserTest, whitespaces){
    JSON M1,M2;
    M1=JSON::StringToJSON("{   \"name\"    :   \"Rotfiend\"     ,\"damage\"        : 35       ,     \"health_points\"  :110     ,\"attack_cooldown\"  : 1.25");
    M2=JSON::StringToJSON("{       \"health_points\"110,      \"damage\" 35      \"name\":\"Rotfiend\"       ,\"attack_cooldown\":               1.25}");
    
    ASSERT_EQ(M1.get<std::string>("name"),"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("health_points"),110)<<"M1[\"health_points\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("damage"),35)<<"M1[\"damage\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1.get<std::string>("name"),M2.get<std::string>("name"))<<"names are not equal";
    EXPECT_EQ(M1.get<int>("health_points"),M2.get<int>("health_points"))<<"healthpoints are not equal";
    EXPECT_EQ(M1.get<int>("damage"),M2.get<int>("damage"))<<"damages are not equal";
}
TEST(ParserTest, StringToMap){
    std::map<std::string,std::string> M1{{"health_points","110"},{"name","Rotfiend"},{"damage","35"},{"attack_cooldown","1.25"}};
    std::map<std::string,std::string> M2{{"name","Rotfiend"},{"damage", "35"},{"health_points","110"},{"attack_cooldown", "1.25"}};
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1["health_points"],"110")<<"M1[\"health_points\"] is incorrect (read from string)";
    ASSERT_EQ(M1["damage"],"35")<<"M1[\"damage\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["health_points"],M2["health_points"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["damage"],M2["damage"])<<"damages are not equal";
}

TEST(ParserTest, unit_data_order){
    JSON M1,M2;
    M1=JSON::StringToJSON("{\"health_points\":110,\"name\":\"Rotfiend\",\"attack_cooldown\": 1.25,\"damage\": 35}");
    M2=JSON::StringToJSON("{\"attack_cooldown\": 1.25m,\"damage\" 35 \"name\":\"Rotfiend\",\"health_points\"110,}");
    
    ASSERT_EQ(M1.get<std::string>("name"),"Rotfiend")<<"M1[\"name\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("health_points"),110)<<"M1[\"health_points\"] is incorrect (read from string)";
    ASSERT_EQ(M1.get<int>("damage"),35)<<"M1[\"damage\"] is incorrect (read from string)";
    
    EXPECT_EQ(M1.get<std::string>("name"),M2.get<std::string>("name"))<<"names are not equal";
    EXPECT_EQ(M1.get<int>("health_points"),M2.get<int>("health_points"))<<"healthpoints are not equal";
    EXPECT_EQ(M1.get<int>("damage"),M2.get<int>("damage"))<<"damages are not equal";
}

TEST(ParserTest, IsFileExists) {
    ASSERT_ANY_THROW(JSON::parseFromFile("../units/nonExistentFile.json"))<<"No error throw when try to read from file, what does not exist";
    ASSERT_NO_THROW(JSON::parseFromFile("../units/Fallen.json"))<<"The file does not exist";
}

TEST(ParserTest, FileRead) {
    JSON M1,M2;
    M1=JSON::parseFromFile("../units/Zombie.json");
    M2=JSON::StringToJSON("{\"name\":\"Rotfiend\",\"damage\": 1},\"health_points\":10,\"attack_cooldown\": 2.8");
    
    ASSERT_EQ(M1.get<std::string>("name"),"Zombie")<<"M1[\"name\"] is incorrect (read from file)";
    ASSERT_EQ(M1.get<int>("health_points"),10)<<"M1[\"health_points\"] is incorrect (read from file)";
    ASSERT_EQ(M1.get<int>("damage"), 1)<<"M1[\"damage\"] is incorrect (read from file)";
    
   // EXPECT_EQ(M1.get<std::string>("damage"),M2.get<std::string>("damage"))<<"names are not equal";
    EXPECT_EQ(M1.get<int>("health_points"),M2.get<int>("health_points"))<<"healthpoints are not equal";
    EXPECT_EQ(M1.get<int>("damage"),M2.get<int>("damage"))<<"damages are not equal";
}
TEST(ParserTest, Missing_Key){
     
   //  ASSERT_ANY_THROW(JSON::StringToJSON("{\"name\":\"Rotfiend\",\"damage\": 35}"))<<"No error throw when input incomplete";
   //  ASSERT_ANY_THROW(JSON::StringToJSON("{\"name\":\"Rotfiend\""))<<"No error throw when input incomplete";



}
//TEST(ParserTest, missingquotemarks){
//    ASSERT_ANY_THROW(JSON::StringToJSON("{\"name\":\"Rotfiend\", \"dmg: 35 , \"hp\": 110"))<<"No error throw when missing \" in input";
   
//}
/*
TEST(ParserTest, ParseUnit){   
    JSON unit1;
    unit1=JSON::StringToJSON("{\"name\":\"Rotfiend\",\"damage\": 35},\"health_points\":100,\"attack_cooldown\": 1.25");    
    Monster C1 (JSON::parseFromFile("../units/unit3.json"));
    ASSERT_EQ(stod(unit1["health_points"]),C1.getHealth());       
}
*/
/*
TEST(GameTest, Attack){
    Hero p1 {Hero::parse("../units/Zombie.json")};
    Monster c1{Monster::parse("../units/Zombie.json")};
    p1.fightTilDeath(c1);
    ASSERT_EQ(p1.getHealthPoints(), p1.getHealthPoints()); 
}*/
/*
TEST(GameTest, Levelup){
    Hero p1{Hero::parse("../units/Fallen.json")};
    Monster c1{Monster::parse("../units/Zombie.json")};
    p1.fightTilDeath(c1);
    ASSERT_FLOAT_EQ(p1.getDamage(),2);
}*/


/*
TEST(GameTest, XP){
    Hero p1(Hero::parse("../units/Zombie.json"));
    Monster c1(Monster::parse("../units/Zombie.json"));
    p1.fightTilDeath(c1);
    ASSERT_EQ(p1.getXP(),10);
}*/
/*
TEST(GameTest, ENEMYHP){
    Hero p1{Hero::parse("units/Fallen.json")};
    Monster c1{Monster::parse("units/Fallen.json")};
    p1.fightTilDeath(c1);
    ASSERT_EQ(c1.getHealthPoints(),0);
}*/
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}