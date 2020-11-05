#include "JSON.h"
#include <fstream>
#include <algorithm>

JSON JSON::jsonParser(std::istream& file) {
	std::string line, alldata;
	while (getline(file, line)) alldata += line;
	return parseFromFile(alldata);
}


 
JSON JSON::StringToMap(const std::string& alldata)
{
	int k;
	std::string  type = "";
	JSON data;
	bool isfloat=false;
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
					data.stringMap[type] += alldata[i];
					i++;
				}
				type = "";
			}
		}
		
		if (isdigit(alldata[i])) {
			k=i;
			while (isdigit(alldata[i]) || alldata[i] == '.') {
				if(alldata[i] == '.') isfloat=true;
				i++;
				
			}
			(!isfloat) ? data.intMap[type] = stoi(alldata.substr(k,i-k)) : data.floatMap[type] = stod(alldata.substr(k,i-k));
			isfloat=false;
			type = "";
		}
		
	}

	return data;
}

JSON JSON::parseFromFile(const std::string& fname) {

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

template<>
std::string JSON::get<std::string>(const std::string& key) const {
    return stringMap.at(key);
}

template<>
float JSON::get<float>(const std::string& key) const {
	return floatMap.at(key);
}

template<>
int JSON::get<int>(const std::string& key) const {
	return intMap.at(key);
}


bool JSON::count(const std::string& key) const {
  return stringMap.count(key);
}
