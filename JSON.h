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
    /**
     *  JSON constructor
     * 
     * Sets the JSON's data according to the parameters.
     * 
     * \param param_map
    */
  	JSON(std::map<std::string, std::string> param_map) : stringMap(param_map) {}
    /**
     *  JSON constructor
    */
    JSON(){};
    /**
     *  \brief Parsing from istream
     *  \param file istream with unit/character information
     *  \return JSON with unit/character information
    */
    static JSON jsonParser(std::istream& file);
    /**
     *  \brief Parsing from Json file
     *  \param fname Filename of the Json file
     *  \return JSON with unit/character information
    */
    static JSON parseFromFile(const std::string& fname);
    /**
     *  \brief Parsing from a string
     *  \param alldata string with unit/caharcter information
     *  \return JSON with unit/character information
    */
    static JSON StringToJSON(const std::string& alldata);    


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
