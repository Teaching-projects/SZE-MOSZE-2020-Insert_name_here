/**
 * \class Parser
 * 
 * \brief Parser class
 * 
 * This class is repsonsible for parsing data from the input.
 * 
 * \author Bartalis Zoltán, Hercsel Péter, Mogyorósi Martin 
 * 
 * \version 1.0
 * 
 * \date 2020/11/02 19:44
 * 
 * Created on 2020/11/02 19:44
*/
#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <map>

class Parser
{

public:
    /**
     *  \brief Parsing from istream
     *  \param file istream with unit/character information
     *  \return Map with unit/character information
    */
    static std::map <std::string, std::string> jsonParser(std::istream& file);
    /**
     *  \brief Parsing from Json file
     *  \param fname Filename of the Json file
     *  \return Map with unit/character information
    */
    static std::map <std::string, std::string> jsonParser(const std::string& fname);
    /**
     *  \brief Parsing from a string
     *  \param alldata string with unit/caharcter information
     *  \return Map with unit/character information
    */
    static std::map <std::string, std::string> StringToMap(const std::string& alldata);    

};

#endif
