#include "jsonparser.h"
#include <fstream>
#include <algorithm>

std::map <std::string, std::string> Parser::jsonParser(std::istream& file) {
	std::string line, alldata;
	while (getline(file, line)) alldata += line;
	return jsonParser(alldata);
}


 
std::map <std::string, std::string> Parser::StringToMap(const std::string& alldata)
{
	std::string  type = "";
	std::map<std::string, std::string> data;
	for (size_t i = 0; i < alldata.size(); i++) {
		if (alldata[i] == '"')
		{
			i++;
			if (type == "") {
				while (alldata[i] != '"') {						
					if (i == alldata.size()) throw std::string("Invalid input formating");
					type += alldata[i];
					i++;					
				}
			}
			else {
				while (alldata[i] != '"') {
					if (i == alldata.size()) throw std::string("Invalid input formating");
					data[type] += alldata[i];
					i++;
				}
				type = "";
			}
		}

		if (isdigit(alldata[i])) {
			while (isdigit(alldata[i]) or alldata[i] == '.') {
				data[type] += alldata[i];
				i++;
			}
			type = "";
		}
		
	}
	
	if(!data.count("name") or !data.count("hp") or !data.count("dmg") or !data.count("attackspeed")) throw std::string("Missing unit data");
	return data;

}

std::map <std::string, std::string> Parser::jsonParser(const std::string& fname) {

	std::string line,alldata, type = "";
	std::map<std::string, std::string> data;	
	std::ifstream file;
	file.open(fname);
	if (file.fail()) throw "The " + fname + " file does not exist or is not readable.";

	while (getline(file, line)) {
		if(std::count(line.begin(), line.end(), '"') % 2 == 1) throw std::string("Invalid input formating");
		alldata += line; 
		
	
	}
	file.close();
	
	return StringToMap(alldata);
}
