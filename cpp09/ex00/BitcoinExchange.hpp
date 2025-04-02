#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <fstream>

class Bitcoin {
	public:
		Bitcoin();
		~Bitcoin();
		Bitcoin& operator=(const Bitcoin&);
		Bitcoin (const Bitcoin&);
		bool validateFiles(std::string);
		
	private:
		std::map<std::string, float> _data;
};