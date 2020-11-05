/**
 * \class JSON
 * 
 * \brief JSON class
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
#ifndef JSON_H
#define JSON_H
#include <string>
#include <map>

class JSON{
std::map<std::string, std::string> stringMap;
    std::map<std::string, float> floatMap;         
    std::map<std::string, int> intMap;

public:
      
	JSON(std::map<std::string, std::string> _map) : stringMap(_map) {}
    JSON(){};
    /**
     *  \brief Parsing from istream
     *  \param file istream with unit/character information
     *  \return Map with unit/character information
    */
    static JSON jsonParser(std::istream& file);
    /**
     *  \brief Parsing from Json file
     *  \param fname Filename of the Json file
     *  \return Map with unit/character information
    */
    static JSON parseFromFile(const std::string& fname);
    /**
     *  \brief Parsing from a string
     *  \param alldata string with unit/caharcter information
     *  \return Map with unit/character information
    */
    static JSON StringToMap(const std::string& alldata);    


    class ParseException : public std::exception {
    std::string s;
  public:
    ParseException(const std::string& str) : s(str) {}
    ~ParseException() throw() {}
    const char* what() const throw() { return s.c_str(); }
  };
    bool count(const std::string& key) const;
    template<typename T>
    T get(const std::string& key) const;
};
#endif
