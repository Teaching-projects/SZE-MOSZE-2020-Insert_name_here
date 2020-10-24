#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <map>

class Parser
{

public:
    static std::map <std::string, std::string> jsonParser(std::istream& file);
    static std::map <std::string, std::string> jsonParser(const std::string& fname);
    static std::map <std::string, std::string> StringToMap(const std::string& alldata);    

};

#endif
