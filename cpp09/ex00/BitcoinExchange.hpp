#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <fstream>
#include <ctime>
#include <string>

class Bitcoin {
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin& operator=(const Bitcoin&);
		Bitcoin (const Bitcoin&);
		bool parsecsv(std::string);

	private:
		std::map<std::string, float> _data;
};