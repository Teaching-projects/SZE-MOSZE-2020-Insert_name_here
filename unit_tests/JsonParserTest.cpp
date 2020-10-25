#include "../jsonparser.h"
#include "../jsonparser.cpp"
#include "../character.h"
#include "../character.cpp"
#include "../game.h"
#include "../game.cpp"
#include <string>
#include <map>
#include <gtest/gtest.h>



TEST(ParserTest, StringRead) {
    std::map<std::string,std::string> M1,M2;
    M1=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":110");
    M2=Parser::StringToMap("{  \"hp\"110,\"dmg\" 35 \"name\":            \"Rotfiend\"}");
    
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
    M2=Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35},\"hp\":100");
    
    ASSERT_EQ(M1["name"],"Rotfiend")<<"M1[\"name\"] is incorrect (read from file)";
    ASSERT_EQ(M1["hp"],"100")<<"M1[\"hp\"] is incorrect (read from file)";
    ASSERT_EQ(M1["dmg"],"35")<<"M1[\"dmg\"] is incorrect (read from file)";
    
    EXPECT_EQ(M1["name"],M2["name"])<<"names are not equal";
    EXPECT_EQ(M1["hp"],M2["hp"])<<"healthpoints are not equal";
    EXPECT_EQ(M1["dmg"],M2["dmg"])<<"damages are not equal";
}
TEST(ParserTest, CorrectData){
     ASSERT_ANY_THROW(Parser::StringToMap("{\"name\":\"Rotfiend,\"dmg\": 35},\"hp\":110"))<<"No error throw when missing \" in input";
     ASSERT_ANY_THROW(Parser::StringToMap("{\"name\":\"Rotfiend\",\"dmg\": 35}"))<<"No error throw when input incomplete";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
