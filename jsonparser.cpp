#include "jsonparser.h"
#include <fstream>


std::map <std::string, std::string> Parser::jsonParser(std::istream& file) {
	std::string line, alldata;
	while (getline(file, line)) alldata += line;
	return jsonParser(alldata);
}


std::string Parser::jsonParserFILE(const std::string& filename){
	std::string line,alldata;
	std::ifstream file;
	file.open(filename);
	if (file.fail()) throw "The " + filename + " file does not exist or is not readable.";

	while (getline(file, line)) alldata += line;
	file.close();
	return alldata;
}


std::map <std::string, std::string> Parser::jsonParser(const std::string& fname) {

	std::string alldata, type = "";
	std::map<std::string, std::string> data;


	if (fname.find('\"') + 1) alldata = fname;
	else {
		alldata=jsonParserFILE(fname);
	}



	for (int i = 0; i < alldata.size(); i++) {
		if (alldata[i] == '"')
		{
			i++;
			if (type == "") {
				while (alldata[i] != '"') {						
					if( alldata[i]==' ' && !isalpha(alldata[i+1])) throw std::string("Invalid input formating");										
					type += alldata[i];
					i++;					
				}
			}
			else {
				while (alldata[i] != '"') {
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
	
	if(!data.count("name") or !data.count("hp") or !data.count("dmg")) throw std::string("Missing unit data");
	return data;
}