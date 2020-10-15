#include "jsonparser.h"
#include <fstream>


std::map <std::string, std::string> Parser::jsonParser(std::istream& file) {
	std::string line, alldata;
	while (getline(file, line)) alldata += line;
	return jsonParser(alldata);
}





std::map <std::string, std::string> Parser::jsonParser(const std::string& fname) {

	std::string line, alldata, type = "";
	std::map<std::string, std::string> data;


	if (fname.find('\"') + 1) alldata = fname;
	else {
		std::ifstream file;
		file.open(fname);
		if (file.fail()) throw "The " + fname + " file does not exist or is not readable.";

		while (getline(file, line)) alldata += line;
		file.close();
	}



	for (int i = 0; i < alldata.size(); i++) {
		if (alldata[i] == '"')
		{
			i++;
			if (type == "") {
				while (alldata[i] != '"') {
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

	return data;
}